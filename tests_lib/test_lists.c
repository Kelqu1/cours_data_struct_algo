#include <stdio.h>
#include <stdlib.h>

#include "../include/lists.h"

void main(){
    dlist d = dlist_add(5,dlist_add(8,dlist_add(25,NULL)));
    print_dlist(d);

    slist s = slist_add(5,slist_add(8,slist_add(25,NULL)));
    print_slist(s);
    
    print_dlist(NULL);
    print_slist(NULL);
}