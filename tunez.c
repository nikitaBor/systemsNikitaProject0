#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tunez.h"

//print_list
//prints the song_nodes inside the list
void print_list(struct song_node *n){
    printf("printing llist \n");
    while(n){ //runs until node points to null
        printf("'%s' by '%s'\n", n->name, n->artist);
        n = n->next;
    }
    printf("\n");
}

//insert_front
//inserts new song at end of n
struct song_node * insert_front(struct song_node *n, char newName[], char newArtist[]){
    //special case if n points to null (no llist yet)
    if(!n){
        n = (struct song_node *)malloc(sizeof(struct song_node));//allocates memory for a node * and assigns it to n
        n->next = 0; //points n to null
        strcpy(n->name,newName);
        strcpy(n->artist,newArtist);
        return n;
    }

    //otherwise...
    struct song_node *retCpy = n; //a copy of where n used to point to
    while(n->next){ n = n->next; } //runs up to last node in list
    n->next = (struct song_node *)malloc(sizeof(struct song_node)); //allocates memory for a node * and assigns it to next
    strcpy(n->next->name,newName);
    strcpy(n->next->artist,newArtist);
    n->next->next = 0;
    return retCpy;
}

//free_list
//takes a non null llist and frees its nodes returning pointer to first node
void free_list(struct song_node *n){
    if(!n){return;}//base case once n is null

    //recursive case
    free_list(n->next);//free the rest of the list
    free(n);//frees the original pointers after others have been freed
    n=0;
}
