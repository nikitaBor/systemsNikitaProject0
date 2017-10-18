#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tunez.h"
#include "tunezLIB.h"

//add_song
//inserts song into library under correct letter alphabetically 
//return pointer to beginning of list with that song
struct song_node * add_song(struct song_node * lib[], char newName[], char newArtist[]){
  return insert_alph(lib[newName[0]-97], newName, newArtist);
  //inserts at correct index in lib
}
