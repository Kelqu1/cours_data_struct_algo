#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/hash_tables.h"

int main(){
    ht_set("foo", 42);
    ht_set("bar", 7);
    ht_set("foo", 100);

    int *v;

    v = ht_get("foo");
    printf("foo = %d\n", v ? *v : -1);

    v = ht_get("bar");
    printf("bar = %d\n", v ? *v : -1);

    v = ht_get("baz");
    printf("baz = %d\n", v ? *v : -1);   // -1 = absent

    ht_free();
    return 0;
}