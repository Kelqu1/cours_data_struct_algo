#ifndef QUEUE_H
#define QUEUE_H

typedef struct cell {
    int *val;
    int head;
    int tail;
    int size_max;
} queue;

queue create_queue(int size_max);

bool is_queue_empty(const queue q);
bool is_queue_full(const queue q);

queue add_queue(int a, queue q);
queue remove_queue(queue q);

int look_top_queue(const queue q);
void print_queue(const queue q);

#endif