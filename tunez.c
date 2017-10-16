#include <stdio.h>
#include <stdlib.h>
#include "tunez.h"

//prints the song_nodes inside the list
void print_list(struct song_node *n){
    printf("printing llist \n");
    while(n){ //runs until node points to null
        printf("'%s' by '%s'\n", n->name, n->artist);
        n = n->next;
    }
    printf("\n");
}

//inserts new song at end of n
struct node * insert_front(struct node *n, char newName[], char newArtist[]){
    //special case if n points to null (no llist yet)
    if(!n){
        n = (struct song_node *)malloc(sizeof(struct song_node));//allocates memory for a node * and assigns it to n
        n->next = 0; //points n to null
        n->name = newName;
        n->artist = newArtist;
        return n;
    }

    //otherwise...
    struct node *retCpy = n; //a copy of where n used to point to
    while(n->next){ n = n->next; } //runs up to last node in list
    n->next = (struct song_node *)malloc(sizeof(struct song_node)); //allocates memory for a node * and assigns it to next
    n->next->name =  newName;
    n->next->artist =  newArtist;
    n->next->next = 0;
    return retCpy;
}

//takes a non null llist and frees its nodes returning pointer to first node
struct node * free_list(struct node *n){
    if(!n){return n;}//base case once n is null

    //recursive case
    free_list(n->next);//free the rest of the list
    free(n);//frees the original pointers after others have been freed
    n=0;
    return n;
}
