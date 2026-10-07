#ifndef LIST_H
#define LIST_H

typedef struct cell_simple {
    float memory;
    struct cell_simple* next;
}*slist;

typedef struct cell_double {
    float memory;
    struct cell_double* previous;
    struct cell_double* next;
}*dlist;

slist slist_add(float a,slist t);
dlist dlist_add(float a,dlist t);

void print_slist(slist l);
void print_dlist(dlist l);

#endif