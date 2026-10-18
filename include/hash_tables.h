#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 1024

typedef struct cell{
    char *key;      // NULL = case vide
    int value;
} *hash_table;

hash_table init_hash_tables();

unsigned long hash(const char *s);

int find_slot(const char *key, const hash_table table);

int ht_set(const char *key, int value, hash_table table);
int *ht_get(const char *key, hash_table table);

void print_hash_tables(const hash_table table);

void ht_free(hash_table table);

#endif
