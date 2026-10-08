#include <stdio.h>
#include <stdlib.h>

#include "../include/stacks.h"

stack create_stack(int size_max){
    stack s;
    s.size_max=size_max;
    s.val=malloc(s.size_max*sizeof(int));
    s.size=0;
    return s;
}

stack push(int a,stack s){
    if(s.size<s.size_max){
        s.size++;
        s.val[s.size-1]=a;
    }
    else{
        printf("the list is full, we are at size:%i\n",s.size);
    }
    return s;
}

stack pop (stack s){
    if (s.size>0){
        s.size--;
    }
    else{
        printf("the list is empty\n");
    }
    return s;
}

//type of the value in the stack
int peek(stack s){
    return s.val[s.size-1];
}

void print_stack(const stack s) {
    printf("the stack state :\n");
    for (int i = s.size - 1; i >= 0; i--){   // du sommet vers le bas
        printf("---\n");
        printf("|%d|\n", s.val[i]);
    }
    printf("---\n");
}
