#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/queue.h"

queue create_queue(){
    queue q;
    q.head=0;
    q.tail=-1;
    return q;
}

//true=empty
bool is_queue_empty(const queue q){
    return q.head > q.tail;
}

//true=full
bool is_queue_full(const queue q){
    return q.tail +1 >= SIZE_MAX;
}

queue add_queue(int a, queue q){
    if (!is_queue_full(q)){
        q.tail++;
        q.val[q.tail]=a;
        printf("ajoute %i\n",a);
        return q;
    }else{
        printf("size max atteinte/ dépassé");
    }
}

queue remove_queue(queue q){
    if (!is_queue_empty(q)){
        //egal if the queue is empty
        q.head++;
    }
    else{
        printf("removing is imposible");
    }
    return q;
}

int look_top_queue(const queue q){
    return q.val[q.head];
}

void print_queue(const queue q) {
    printf("the queue state (");
    if (!is_queue_empty(q)){
        for (int i = q.head; i <= q.tail; i++){   // du sommet vers le bas
            printf("%d,", q.val[i]);
        }
        printf(")\n");
    }
    else printf(")the queue is empty\n");
}