#include <stdio.h>
#include <stdlib.h>
#include "tunez.h"
#include <time.h>

int main(){
    struct song_node *bill = 0;
    bill = insert_front(bill,"september","earth,wind,fire");
    printf("testing print_list\n");
    print_list(bill);

    printf("adding to test insert_front\n");
    insert_front(bill, "tighten up","black keys");
    print_list(bill);

    printf("adding new songs with insert_alph at begininning, middle, end\n");
    bill = insert_alph(bill,"howlin for you", "black keys");
    bill = insert_alph(bill,"joker and the theft", "wolfmother");
    bill = insert_alph(bill,"woman", "wolfmother");
    print_list(bill);

    printf("testing find_song_name\n");
    printf("searching for september...\n");
    print_node(search_list_name(bill,"september", "earth,wind,fire"));
    printf("searching for NOTASONG...\n");
    print_node(search_list_name(bill,"NOTASONG", "NOTANARTIST"));

    printf("testing find_song_artist\n");
    printf("searching for songs by black keys...\n");
    print_node(search_list_artist(bill,"black keys"));
    printf("searching for songs by NOTANARTIST...\n");
    print_node(search_list_artist(bill, "NOTANARTIST"));

    printf("testing find_song_random\n");
    printf("searching for random song...\n");
    srand(time(NULL));
    print_node(search_list_random(bill));
    printf("searching for random song again(probably different this time)...\n");
    print_node(search_list_random(bill));
    printf("one more time, just in case...\n");
    print_node(search_list_random(bill));
    printf("\n");

    printf("removing songs (delete_list_song) at begininning, middle, end\n");
    printf("removing joker,howling,woman \n");
    bill = delete_list_song(bill,"joker and the theft", "wolfmother");
    bill = delete_list_song(bill,"howlin for you", "black keys");
    bill = delete_list_song(bill,"woman", "wolfmother");
    bill = delete_list_song(bill,"woman", "wolfmother"); //to make sure that no error if it isnt there
    print_list(bill);

    free_list(bill);

    return 0;
}
