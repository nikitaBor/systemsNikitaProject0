#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tunez.h"

//print_list
//prints the song_nodes inside the list
void print_list(struct song_node *n){
    printf("printing song list \n");
    while(n){ //runs until node points to null
        printf("'%s' by '%s' | ", n->name, n->artist);
        n = n->next;
    }
    printf("\n");
}

//print_node
//prints the song_nodes inside the list
void print_node(struct song_node *n){
    if(!n){printf("NO NODE\n"); return;}
    printf("printing node : '%s' by '%s' \n", n->name, n->artist);
}

//insert_front
//inserts new song at end of n and returns pointer to beginning of list
struct song_node * insert_front(struct song_node *n, char newName[], char newArtist[]){
    //special case if n points to null (no list yet)
    if(!n){
        n = (struct song_node *)malloc(sizeof(struct song_node));//allocates memory for a node * and assigns it to n
        n->next = 0; //points n to null
        strcpy(n->name,newName);
        strcpy(n->artist,newArtist);
        return n;
    }

    //otherwise...
    struct song_node *rtcpy = n;
    while(n->next){ n = n->next; } //runs up to last node in list
    n->next = (struct song_node *)malloc(sizeof(struct song_node)); //allocates memory for a node * and assigns it to next
    strcpy(n->next->name,newName);
    strcpy(n->next->artist,newArtist);
    n->next->next = 0;
    return rtcpy;
}


//insert_alph
//inserts new song into n and returns pointer to the list
struct song_node * insert_alph(struct song_node *n, char newName[], char newArtist[]){
    //if no list exists
    if(!n){
        return insert_front(n,newName,newArtist);
    }

    //otherwise...
    if(strcmp(newName,n->name)<0) { //newName isn't first word
        struct song_node *restOfList = n;
        n = (struct song_node *)malloc(sizeof(struct song_node)); //allocates memory for a node * and assigns it to next
        strcpy(n->name,newName);
        strcpy(n->artist,newArtist);
        n->next = restOfList;
        return n;//in this case you would have to set bill=n since the list begins one song earlier
    }
    //run until in correct place or hit end of list
    struct song_node *rtcpy = n;
    while (n->next && (strcmp(newName, n->next->name) > 0)) {
        n = n->next;
    }
    //else
    struct song_node *restOfList = n->next;
    n->next = (struct song_node *)malloc(sizeof(struct song_node)); //allocates memory for a node * and assigns it to next
    strcpy(n->next->name,newName);
    strcpy(n->next->artist,newArtist);
    n->next->next = restOfList;
    return rtcpy;
}

//search_list_name
//returns node with name and artist or null if it isn't in the list
struct song_node * search_list_name(struct song_node *n, char findName[], char findArtist[]){
    while(n && !(!strcmp(findName,n->name) && !strcmp(findArtist,n->artist))){ //run until end of list or both name and artist match
        n = n->next;
    }
    return n;
}

//search_list_artist
//returns first node with findArtist or null if it isn't in the list
struct song_node * search_list_artist(struct song_node *n, char findArtist[]){
    while(n && strcmp(findArtist,n->artist)){ //run until end of list or artist match
      n = n->next;
    }
    return n;
}

//print_list_artist
//prints all songs by findArtist
//does nothing if no songs by the artist found
void print_list_artist(struct song_node *n, char findArtist[]){
  while(n){
    if(!strcmp(findArtist,n->artist)){ print_node(n); }
    n = n->next;
  }
}

//search_list_random
//returns random node in list
struct song_node * search_list_random(struct song_node *n){
    struct song_node *ncpy = n; //for finding length of n
    int length = 0;
    while(ncpy){ncpy=ncpy->next; length++;} //runs to end of list and finds length
    int randPos = rand() % length; //random position in list;
    while(randPos){n=n->next; randPos--;} //works up the list as randPos goes to 0
    return n;
}

//delete_list_song
//removes song_node and frees its contents
struct song_node * delete_list_song(struct song_node *n, char findName[], char findArtist[]){
    if(!n){return 0;}//if there is no list

    struct song_node *rtcpy = n; //copy of where n originally points
    if(!search_list_name(n,findName,findArtist)){return rtcpy;}// if there is no element inside
    if(!strcmp(findName,n->name) && !strcmp(findArtist,n->artist)){ //special case if first node is to be deleted
        rtcpy = n->next;
        free(n);
        n = 0;
        return(rtcpy);
    }

    while(n && !(!strcmp(findName,n->next->name) && !strcmp(findArtist,n->next->artist))){ //run prior to node with both name and artist match
        n = n->next;
    }
    //else
    struct song_node *restOfList = n->next->next;
    free(n->next);
    n->next = restOfList;
    return rtcpy;
}

//free_list
//takes a non null list and frees its nodes returning pointer to first node
void free_list(struct song_node *n){
    if(!n){return;}//base case once n is null

    //recursive case
    free_list(n->next);//free the rest of the list
    free(n);//frees the original pointers after others have been free
}
