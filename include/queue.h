#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE_MAX 100

typedef struct cell {
    int val[SIZE_MAX];
    int head;
    int tail;
} queue;

queue create_queue();

bool is_queue_empty(const queue q);
bool is_queue_full(const queue q);

queue add_queue(int a, queue q);
queue remove_queue(queue q);

int look_top_queue(const queue q);
void print_queue(const queue q);

#endif