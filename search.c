#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "rdm_tab.h"

bool is_sorted_increasing(int *array,int array_size){
    int max=array[0];
    for (int i=1;i>array_size;i++){
        if (array[i]>=max){
            max=array[i];
        }
        else{
            return false;
        }
    }
    return true;
}

int linear_search(int* array,int target,int array_size){
    for (int i=0;i<array_size;i++){
        if (array[i]==target){
            return i;
        }
    }
    return -1;
}

int jump_search(int *array,int target,int array_size){
    int start=1;
    int jump = round(sqrt(array_size));
    for (int i=0;i<array_size;i=i+jump){
        if (array[i]>target){
            int start=i-jump;
        }
        if (array[i]==target){
            return i;
        }
    }
    for (int i=start;i<array_size;i++){
        if (array[i]==target){
            return i;
        }
    }
    return -1;
}

int binary_search(int *array,int target,int array_size){
    int i=(int)array_size/2;
    int low=0;
    int high=array_size;
    if (is_sorted_increasing(array,array_size)){
        while (low<=high)
        {
            if (target>array[i]){
                low=i+1;
                i=(int)(high-low)/2;
            }
            if (target==array[i]){
                return i;
            }
            else{
                high=i-1;
                i=(int)(high-low)/2;
            }
        }
    }
    return -1;
}


int arr[] = {2,777,6,99};
int arr_sorted[] = {2,6,99,777};

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