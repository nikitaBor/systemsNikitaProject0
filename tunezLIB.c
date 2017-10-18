#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tunez.h"
#include "tunezLIB.h"

//add_song
//inserts song into library under correct letter alphabetically 
//return pointer to beginning of list with that song
struct song_node * add_song(struct song_node * lib[], char newName[], char newArtist[]){
  lib[newName[0]-97] = insert_alph(lib[newName[0]-97], newName, newArtist);
  return lib[newName[0]-97];
}

//search_lib_name
//looks for node based on song name and artist and returns pointer to it by
//... going directly to the song list with the correct ltr
//returns null if song is not found
struct song_node * search_lib_name(struct song_node *lib[], 
				   char findName[], char findArtist[]){
  return search_list_name(lib[findName[0]-97],findName,findArtist);
}

//search_lib_artist
//searches for first node in library with artist name by looking through
//... all lists in order
//returns null if artist not found
struct song_node * search_lib_artist(struct song_node *lib[], 
				     char findArtist[]){
  char c = 97;
  struct song_node *n = 0;
  while(c<123){ //goes up to 'z' list
    if(n = search_list_artist(lib[c-97], findArtist)){return n;}
    c++;
  }
    return n; //n would still be null if here
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
  char c = 97;
  while(c<123){ //goes up to 'z' list
  }
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
