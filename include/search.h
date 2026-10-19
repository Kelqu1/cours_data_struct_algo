#ifndef SEARCH_H
#define SEARCH_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "../include/long_sorted_array.h"

bool is_sorted_increasing(int *array,int array_size);

int linear_search(int* array,int target,int array_size);

//sorting the array must be done before calling the two next functions
int jump_search(int *array,int target,int array_size);
int binary_search(int *array,int target,int array_size);

#endif