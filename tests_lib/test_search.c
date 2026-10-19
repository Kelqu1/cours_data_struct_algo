#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "../include/long_sorted_array.h"
#include "../include/search.h"

int main(){
    clock_t start=clock();
    int a = linear_search(tab,95176,10000);
    clock_t end=clock();;
    double duree = (double)(end - start) / CLOCKS_PER_SEC;
    printf("linear search : %i\n",a);
    printf("Temps d'exécution: %f s\n", duree);
    
    start=clock();;
    int b = jump_search(tab,95176,10000);
    end=clock();;
    duree = (double)(end - start) / CLOCKS_PER_SEC;
    printf("jump search : %i \n",a);
    printf("Temps d'exécution: %f s\n", duree);

    start=clock();;
    int c = binary_search(tab,95176,10000);
    end=clock();
    duree = (double)(end - start) / CLOCKS_PER_SEC;
    printf("binary search : %i \n",a);
    printf("Temps d'exécution: %f s\n", duree);
} 