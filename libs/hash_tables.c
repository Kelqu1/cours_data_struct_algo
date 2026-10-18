#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/hash_tables.h"

hash_table init_hash_tables(){
    hash_table table=calloc(TABLE_SIZE,sizeof(struct cell));
    return table;
}

unsigned long hash(const char *s) {
    unsigned long h = 5381;
    while (*s) {
        h = h * 33 + (unsigned char)*s;
        s++;
    }
    return h;
}

// return -1 if the element don't exist
int find_slot(const char *key,hash_table table) {
    unsigned long idx = hash(key) % TABLE_SIZE; 

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[idx].key == NULL)           return idx;   // empty 
        if (strcmp(table[idx].key, key) == 0) return idx;   // not empty
        idx = (idx + 1) % TABLE_SIZE;
    }
    return -1;
}

int ht_set(const char *key, int value,hash_table table) {
    int idx = find_slot(key,table);
    if (idx < 0) return 0;

    if (table[idx].key == NULL)
        table[idx].key = strdup(key); 
    table[idx].value = value;
    return 1;
}

int *ht_get(const char *key,hash_table table) {
    int idx = find_slot(key,table);
    if (idx < 0 || table[idx].key == NULL)
        return NULL;
    return &table[idx].value;
}

void print_hash_tables(const hash_table table){
    printf("hash table:\n");
    printf("|keys\t|value\t|\n");
    for (int idx = 0; idx < TABLE_SIZE; idx++) {
        if (table[idx].key!=NULL){
            printf("|%i\t|%i\t|\n",idx,table[idx].value);
        }
    }
    printf("____\t|____\t|\n");
}

void ht_free(hash_table table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        free(table[i].key);
        table[i].key = NULL;
    }
    return;
}
