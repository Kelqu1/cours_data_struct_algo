#include <stdio.h>
#include <stdlib.h>

#include "lists.h"

slist slist_add(float a,slist t){
    slist l=malloc(sizeof(struct cell_simple));
    l->memory=a;
    l->next=t;
    return l;
}

dlist dlist_add(float a,dlist t){
    dlist l=malloc(sizeof(struct cell_double));
    l->memory=a;
    l->previous=l->next;
    l->next=t;
    return l;
}

void print_slist(slist l){
    printf("(");
    slist ptr=l;
    while (ptr != NULL )
    {
        printf(" %.1f",ptr->memory);
        ptr=ptr->next;
    }
    printf(" )\n");
}

void print_dlist(dlist l){
    printf("(");
    dlist ptr=l;
    while (ptr != NULL )
    {
        printf(" %.1f",ptr->memory);
        ptr=ptr->next;
    }
    printf(" )\n");
}
