#include <stdio.h>
#include <stdlib.h>
#include "tunez.h"
#include "tunezLIB.h"
#include <time.h>

//Nikita Borisov
//Project0


int main(){
    struct song_node *bill = 0;
    printf("===================\n");
    printf("*Project0 for Systems Level Programming\n");
    printf("*The list functions are in tunez.c and the library functions are in tunezLIB.c\n");
    printf("*PLEASE USE ONLY LOWER CASE SONG NAMES AND ARTISTS\n");
    printf("*Made by: Nikita Borisov (nikitaBor)\n");
    printf("===================\n\n\n");
    printf("===================\n");
    printf("Testing tunez LIST FUNCTIONS\n");
    printf("===================\n\n");

    //adding a single node
    bill = insert_front(bill,"tighten up","black keys" );
    
    printf("Testing print_list\n\n");
    print_list(bill);
    printf("===================\n");

    printf("Testing insert_front\n\n");
    printf("adding 'september' by 'earth,wind,fire'...\n");
    insert_front(bill, "september","earth,wind,fire");
    print_list(bill);
    printf("===================\n");

    printf("Testing insert_alph\n\n");
    printf("adding 'howling for you'(beggining),'woman'(end),'joker and the theft'/'gold on ceiling'(middle)...\n");
    bill = insert_alph(bill,"howlin for you", "black keys");
    bill = insert_alph(bill,"gold on the ceiling", "black keys");
    bill = insert_alph(bill,"woman", "wolfmother");
    bill = insert_alph(bill,"joker and the theft", "wolfmother");
    print_list(bill);
    printf("There sould now be 6 SONGS\n");
    printf("===================\n");

    printf("Testing search_song_name\n\n");
    printf("searching for 'september' by 'earth,wind,fire'...\n");
    print_node(search_list_name(bill,"september", "earth,wind,fire"));
    printf("searching for 'not_a_song' by 'not_an_artist'...\n");
    print_node(search_list_name(bill,"not_a_song", "not_an_artist"));
    printf("===================\n");

    printf("Testing search_list_artist\n\n");
    printf("searching for song by 'wolfmother'...\n");
    print_node(search_list_artist(bill,"wolfmother"));
    printf("searching for song by 'not_an_artist'...\n");
    print_node(search_list_artist(bill, "not_an_artist"));
    printf("===================\n");

    printf("Testing print_list_artist\n\n");
    printf("printing songs by 'black keys'...\n");
    print_list_artist(bill,"black keys");
    printf("printing songs by 'not_an_artist'...\n");
    print_list_artist(bill, "not_an_artist");
    printf("===================\n");

    printf("Testing find_song_random\n\n");
    printf("searching for random song...\n");
    srand(time(NULL));
    print_node(search_list_random(bill));
    printf("searching for random song again(probably diff this time)...\n");
    print_node(search_list_random(bill));
    printf("one more time, just in case...\n");
    print_node(search_list_random(bill));
    printf("===================\n");

    printf("Testing delete_list_song\n\n");
    printf("removing 'gold on the ceiling'(beginning),'joker and the theft'(middle),'woman'(end), and 'not_a_song'... \n");
    bill = delete_list_song(bill,"gold on the ceiling", "black keys");
    bill = delete_list_song(bill,"joker and the theft", "wolfmother");
    bill = delete_list_song(bill,"woman", "wolfmother");
    bill = delete_list_song(bill,"not_a_song", "not_an_artist"); //to make sure that no error if it isnt there
    print_list(bill);
    printf("There should now be 3 SONGS\n");
    printf("===================\n");

    printf("Testing free_list\n\n");
    free_list(bill);
    bill=0;
    printf("===================\n\n\n\n");
    ///////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////////////////
    //start of array Testing
    struct song_node * ipod[26];
    int i = 0;
    while(i < 26){ipod[i]=0; i++;} //sets all list pointers to null

    printf("===================\n");
    printf("Testing tunezLIB LIBRARY FUNCTIONS\n");
    printf("===================\n\n");

    printf("Testing add_song\n\n");
    printf("adding 7 songs and printing lib...\n");
    add_song(ipod, "hey jude", "beatles");
    add_song(ipod, "howlin for you", "black keys");
    add_song(ipod, "gold on the ceiling", "black keys");
    add_song(ipod, "gimme shelter", "the rolling stones");
    add_song(ipod, "the wolf", "siames");
    add_song(ipod, "mette rich", "tokio hotel");
    add_song(ipod, "god save the queen", "sex pistols");
    print_lib(ipod);
    printf("There should now be 7 SONGS\n");
    printf("===================\n");
   
    printf("Testing search_lib_name\n\n");
    printf("searching for 'the wolf' by 'siames'...\n");
    print_node(search_lib_name(ipod,"the wolf", "siames"));
    printf("searching for 'not_a_song'...\n");
    print_node(search_lib_name(ipod,"not_a_song","not_an_artist"));
    printf("===================\n");

    printf("Testing search_lib_artist\n\n");
    printf("searching for song by 'black keys'...\n");
    print_node(search_lib_artist(ipod,"black keys"));
    printf("searching for song by 'not_an_artist'...\n");
    print_node(search_lib_artist(ipod,"not_an_artist"));
    printf("===================\n");

    printf("Testing print_lib_letter\n\n");
    printf("printing 'b's contents...\n");
    print_lib_letter(ipod,'b');
    printf("printing 'k's nonexistent contents...\n");
    print_lib_letter(ipod,'k');
    printf("===================\n");

    printf("Testing print_lib_artist\n\n");
    printf("printing songs by 'black keys'...\n");
    print_lib_artist(ipod,"black keys");
    printf("printing songs by 'not_an_artist'...\n");
    print_lib_artist(ipod,"not_an_artist");
    printf("===================\n");

    printf("Testing print_lib\n\n");
    printf("printing entire lib...\n");
    print_lib(ipod);
    printf("===================\n");

    printf("Testing print_lib_random\n\n");
    printf("printing 5 randomly selected songs from lib...\n");
    print_lib_random(ipod, 5);
    printf("===================\n");

    printf("Testing delete_lib_song\n\n");
    printf("removing 'gimme shelter'(beginning),'gold on ceiling'(middle),'the wolf'(end), 'not_a_song'...\n");
    delete_lib_song(ipod,"gimme shelter", "the rolling stones");
    delete_lib_song(ipod,"gold on the ceiling", "black keys");
    delete_lib_song(ipod,"the wolf", "siames");
    delete_lib_song(ipod,"not_a_song", "not_an_artist"); //to make sure that no error if it isnt there
    print_lib(ipod);
    printf("There should now be 4 SONGS\n");
    printf("===================\n");

    printf("Testing free_lib\n\n");
    free_lib(ipod);
    printf("===================\n\n\n\n");

    return 0;
}
