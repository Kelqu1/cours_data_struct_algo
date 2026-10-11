#include <stdio.h>
#include <stdlib.h>

#include "../include/stacks.h"

int main(){
    stack my_stack=create_stack(4);
    my_stack=push(19,my_stack);
    my_stack=push(4,my_stack);
    my_stack=push(255,my_stack);

    printf("expected value (255) \t:%i\n",peek(my_stack));

    my_stack=pop(my_stack);

    printf("exepected value (4) \t:%i\n",peek(my_stack));

    my_stack=push(5,my_stack);
    //expected :---
    //expected :|5|
    //expected :|4|
    //expected :|19|
    //expected :---S
    print_stack(my_stack);


    my_stack=push(28,my_stack);
    my_stack=push(55,my_stack);
    //expected : stack max size is 4, cannot push

}