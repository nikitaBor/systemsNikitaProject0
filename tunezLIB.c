#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tunez.h"
#include "tunezLIB.h"

//Nikita Borisov
//Project0


//add_song
//inserts song into library under correct letter alphabetically 
//return pointer to beginning of list with that song
struct song_node * add_song(struct song_node * lib[], char newName[], char newArtist[]){
  lib[newArtist[0]-97] = insert_alph(lib[newArtist[0]-97], newName, newArtist);
  return lib[newArtist[0]-97];
}

//search_lib_name
//searches for node in library with song name by looking through
//... all lists in order
//returns null if song not found
struct song_node * search_lib_name(struct song_node * lib[],
				   char findName[], char findArtist[]){
  char c = 97;
  struct song_node *n = 0;
  while(c<123){ //goes up to 'z' list
    if(n = search_list_name(lib[c-97], findName, findArtist)){return n;}
    c++;
  }
    return n; //n would still be null if here
}

//search_lib_artist
//looks for first node with artist name by
//... going directly to the song list with same letter as artist
//returns null if song is not found
struct song_node * search_lib_artist(struct song_node * lib[],
				     char findArtist[]){
  return search_list_artist(lib[findArtist[0]-97], findArtist);
}

//print_lib_letter
//prints the song list under ltr in lib
//doesnt do anything if list is empty
void print_lib_letter(struct song_node * lib[], char ltr){
  if(!lib[ltr-97]){return;}//if no list is there
  //else
  printf("%c list\n", ltr);
  print_list(lib[ltr-97]);
}

//print_lib_artist
//prints all songs by an findArtist
void print_lib_artist(struct song_node *lib[], char findArtist[]){
  print_list_artist(lib[findArtist[0]-97],findArtist);//print songs by artist in artist's list
}

//print_lib
//prints entire library
void print_lib(struct song_node * lib[]){
  char c = 97;
  while(c<123){ //prints all list up to 'z'
    print_lib_letter(lib,c); 
    c++; 
  } 
}

//print_random
//prints numSongs random song from lib
//precond: at least one list in lib isn't null(infinite loop otherwise)
void print_lib_random(struct song_node * lib[], int numSongs){
  int libPos = 0;
  while(numSongs--){ //performs operation numSongs times
    while(!lib[libPos++ % 26]){} //runs until a non-empty list is found and index is kept under 26 by wrapping around
    print_node(search_list_random(lib[(libPos-1)%26])); //libPos-1 used to undo the libPos++ after correct pos was found
  }
}

//delete_lib_song
//deletes findName by findArtist by going to list with correct letter of findName
//does nothing if song isn't present
void delete_lib_song(struct song_node * lib[], char findName[], char findArtist[]){
    lib[findArtist[0]-97] = delete_list_song(lib[findArtist[0]-97], findName, findArtist);
}

//free_lib
//frees all library contents
void free_lib(struct song_node * lib[]){
  int libPos = 0;
  while(libPos <26){
    free_list(lib[libPos]);
    libPos++;
  }
}
