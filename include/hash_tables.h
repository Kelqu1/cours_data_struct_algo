#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 1024

typedef struct {
    char *key;      // NULL = case vide
    int value;
} hash_table;

unsigned long hash(const char *s);

int find_slot(const char *key);

int ht_set(const char *key, int value);

int *ht_get(const char *key);

void ht_free(void);

#endif