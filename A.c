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

    bill = insert_front(bill,"september","earth,wind,fire");
    printf("testing print_list\n");
    print_list(bill);
    printf("===================\n");

    printf("adding to test insert_front\n");
    insert_front(bill, "tighten up","black keys");
    print_list(bill);
    printf("===================\n");

    printf("adding new songs with insert_alph at begininning, middle, end\n");
    bill = insert_alph(bill,"howlin for you", "black keys");
    bill = insert_alph(bill,"joker and the theft", "wolfmother");
    bill = insert_alph(bill,"woman", "wolfmother");
    print_list(bill);
    printf("===================\n");

    printf("testing search_song_name\n");
    printf("searching for september...\n");
    print_node(search_list_name(bill,"september", "earth,wind,fire"));
    printf("searching for NOTASONG...\n");
    print_node(search_list_name(bill,"NOTASONG", "NOTANARTIST"));
    printf("===================\n");

    printf("testing search_list_artist\n");
    printf("searching for song by black keys...\n");
    print_node(search_list_artist(bill,"black keys"));
    printf("searching for song by NOTANARTIST...\n");
    print_node(search_list_artist(bill, "NOTANARTIST"));
    printf("===================\n");

    printf("testing print_list_artist\n");
    printf("printing songs by black keys...\n");
    print_list_artist(bill,"black keys");
    printf("printing songs by NOTANARTIST...\n");
    print_list_artist(bill, "NOTANARTIST");
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

    printf("removing songs (delete_list_song) at begininning, middle, end\n");
    printf("removing joker,howling,woman \n");
    bill = delete_list_song(bill,"joker and the theft", "wolfmother");
    bill = delete_list_song(bill,"howlin for you", "black keys");
    bill = delete_list_song(bill,"woman", "wolfmother");
    bill = delete_list_song(bill,"woman", "wolfmother"); //to make sure that no error if it isnt there
    print_list(bill);
    printf("===================\n\n\n\n");

    free_list(bill);
    bill=0;
    ///////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////////////////
    //start of array testing
    struct song_node * ipod[26];
    int i = 0;
    while(i < 26){ipod[i]=0; i++;} //sets all list pointers to null

    printf("===================\n");
    printf("testing tunezLIB LIBRARY FUNCTIONS\n");
    printf("===================\n\n");

    printf("adding 4 songs with add_song\n");
    add_song(ipod, "hey jude", "beatles");
    add_song(ipod, "howlin for you", "black keys");
    add_song(ipod, "gold on the ceiling", "black keys");
    add_song(ipod, "the wolf", "siames");
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
    printf("===================\n\n\n\n");

    free_lib(ipod);

    return 0;
}
