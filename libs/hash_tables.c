#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/hash_tables.h"

hash_table table[TABLE_SIZE];   // initialisé à 0 (key = NULL)

unsigned long hash(const char *s) {   // djb2
    unsigned long h = 5381;
    while (*s) {
        h = h * 33 + (unsigned char)*s;
        s++;
    }
    return h;
}

// Renvoie l'indice de la clé si elle existe, sinon l'indice de la première
// case vide où elle devrait être insérée. Renvoie -1 si la table est pleine.
int find_slot(const char *key) {
    int idx = hash(key) % TABLE_SIZE;   // < 1024, tient dans un int

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[idx].key == NULL)           return idx;   // case vide
        if (strcmp(table[idx].key, key) == 0) return idx;   // clé trouvée
        idx = (idx + 1) % TABLE_SIZE;
    }
    return -1;
}

int ht_set(const char *key, int value) {
    int idx = find_slot(key);
    if (idx < 0) return 0;                    // table pleine

    if (table[idx].key == NULL)
        table[idx].key = strdup(key);         // nouvelle clé
    table[idx].value = value;
    return 1;
}

int *ht_get(const char *key) {
    int idx = find_slot(key);
    if (idx < 0 || table[idx].key == NULL)
        return NULL;                          // absente
    return &table[idx].value;
}

void ht_free(void) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        free(table[i].key);
        table[i].key = NULL;
    }
}