#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/queue.h"

int main(){
    queue a =create_queue(10);
    a= add_queue(25,a);
    printf("top of the queue %i\n",look_top_queue(a));
    a= add_queue(10,a);
    printf("top of the queue %i\n",look_top_queue(a));
    a=remove_queue(a);
    printf("top of the queue %i\n",look_top_queue(a));
    print_queue(a);
}