#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/hash_tables.h"

int main(){
    hash_table htable =init_hash_tables();
    ht_set("foo", 42,htable);
    ht_set("bar", 7,htable);
    ht_set("foo", 100,htable);

    print_hash_tables(htable);

    int *v;

    v = ht_get("foo",htable);
    printf("foo = %d\n", v ? *v : -1);

    v = ht_get("bar",htable);
    printf("bar = %d\n", v ? *v : -1);

    v = ht_get("baz",htable);
    printf("baz = %d\n", v ? *v : -1);   // -1 = absent

    ht_free(htable);
    return 0;
}