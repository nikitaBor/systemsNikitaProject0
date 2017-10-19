#include <stdio.h>
#include <stdlib.h>
#include "tunez.h"
#include "tunezLIB.h"
#include <time.h>

int main(){
    struct song_node *bill = 0;
    printf("===================\n");
    printf("testing tunez LIST FUNCTIONS\n");
    printf("===================\n\n");

    //adding a single node
    bill = insert_front(bill,"september","earth,wind,fire");
    
    printf("testing print_list\n");
    print_list(bill);
    printf("===================\n");

    printf("testing insert_front(adding 'tighten up')\n");
    insert_front(bill, "tighten up","black keys");
    print_list(bill);
    printf("===================\n");

    printf("testing insert_alph\n");
    printf("adding at howlin(beginning),joker(middle),woman(end)...\n");
    bill = insert_alph(bill,"howlin for you", "black keys");
    bill = insert_alph(bill,"joker and the theft", "wolfmother");
    bill = insert_alph(bill,"woman", "wolfmother");
    print_list(bill);
    printf("===================\n");

    printf("testing search_song_name\n");
    printf("searching for september...\n");
    print_node(search_list_name(bill,"september", "earth,wind,fire"));
    printf("searching for not_a_song...\n");
    print_node(search_list_name(bill,"not_a_song", "not_an_artist"));
    printf("===================\n");

    printf("testing search_list_artist\n");
    printf("searching for song by black keys...\n");
    print_node(search_list_artist(bill,"black keys"));
    printf("searching for song by not_an_artist...\n");
    print_node(search_list_artist(bill, "not_an_artist"));
    printf("===================\n");

    printf("testing print_list_artist\n");
    printf("printing songs by black keys...\n");
    print_list_artist(bill,"black keys");
    printf("printing songs by not_an_artist...\n");
    print_list_artist(bill, "not_an_artist");
    printf("===================\n");

    printf("testing find_song_random\n");
    printf("searching for random song...\n");
    srand(time(NULL));
    print_node(search_list_random(bill));
    printf("searching for random song again(probably diff this time)...\n");
    print_node(search_list_random(bill));
    printf("one more time, just in case...\n");
    print_node(search_list_random(bill));
    printf("===================\n");

    printf("testing delete_list_song\n");
    printf("removing howlin(beginning),joker(middle),woman(end), and not_a_song \n");
    bill = delete_list_song(bill,"joker and the theft", "wolfmother");
    bill = delete_list_song(bill,"howlin for you", "black keys");
    bill = delete_list_song(bill,"woman", "wolfmother");
    bill = delete_list_song(bill,"not_a_song", "not_an_artist"); //to make sure that no error if it isnt there
    print_list(bill);
    printf("===================\n");

    printf("testing free_list\n");
    free_list(bill);
    bill=0;
    printf("===================\n\n\n\n");
    ///////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////////////////
    //start of array testing
    struct song_node * ipod[26];
    int i = 0;
    while(i < 26){ipod[i]=0; i++;} //sets all list pointers to null

    printf("===================\n");
    printf("testing tunezLIB LIBRARY FUNCTIONS\n");
    printf("===================\n\n");

    printf("testing add_song(adding 5 songs and printing lib)\n");
    add_song(ipod, "hey jude", "beatles");
    add_song(ipod, "howlin for you", "black keys");
    add_song(ipod, "gold on the ceiling", "black keys");
    add_song(ipod, "gimme shelter", "the rolling stones");
    add_song(ipod, "the wolf", "siames");
    print_lib(ipod);
    printf("===================\n");
   
    printf("testing search_lib_name(looking for the wolf by siames)\n");
    print_node(search_lib_name(ipod,"the wolf", "siames"));
    printf("testing search_lib_name(looking for not_a_song)\n");
    print_node(search_lib_name(ipod,"not_A_SONG","not_an_artist"));
    printf("===================\n");

    printf("testing search_lib_artist(looking for black keys)\n");
    print_node(search_lib_artist(ipod,"black keys"));
    printf("testing search_lib_artist(looking for not_AN_artist)\n");
    print_node(search_lib_artist(ipod,"not_AN_artist"));
    printf("===================\n");

    printf("testing print_lib_letter(print 'h's contents)\n");
    print_lib_letter(ipod,'h');
    printf("testing print_lib_letter(print 'k's nonexistent contents)\n");
    print_lib_letter(ipod,'k');
    printf("===================\n");

    printf("testing print_lib_artist(printing songs by black keys)\n");
    print_lib_artist(ipod,"black keys");
    printf("testing print_lib_letter(print songs by not_an_artist)\n");
    print_lib_artist(ipod,"not_an_artist");
    printf("===================\n");

    printf("testing print_lib(print entire lib)\n");
    print_lib(ipod);
    printf("===================\n");

    printf("testing print_lib_random(print 5 randomly selected songs lib)\n");
    print_lib_random(ipod, 5);
    printf("===================\n");

    printf("testing delete_lib_song\n");
    printf("removing gold,howlin,hey jude \n");
    delete_lib_song(ipod,"gold on the ceiling", "black keys");
    delete_lib_song(ipod,"howlin for you", "black keys");
    delete_lib_song(ipod,"hey jude", "beatles");
    delete_lib_song(ipod,"hey jude", "beatles"); //to make sure that no error if it isnt there
    print_lib(ipod);
    printf("===================\n");

    printf("testing free_lib\n");
    free_lib(ipod);
    printf("===================\n\n\n\n");

    return 0;
}
