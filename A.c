#include <stdio.h>
#include <stdlib.h>
#include "tunez.h"

int main(){
    struct song_node *bill = 0;
    bill = insert_front(bill,"september","earth,wind,fire");
    printf("testing print_list\n");
    print_list(bill);

    printf("adding to test insert front\n");
    insert_front(bill, "x","misterY");
    print_list(bill);

    printf("add\n");
    free_list(bill);
    return 0;
}
