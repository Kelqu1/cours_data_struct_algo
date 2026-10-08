#ifndef STACK_H
#define STACK_H

typedef struct cell {
    int *val;
    int size;
    int size_max;
} stack;

stack create_stack(int size_max);

stack push(int a,stack s);
stack pop (stack s);
int peek(stack s);

void print_stack(const stack s);

#endif