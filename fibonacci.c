#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 40

long naive_fibonacci(long n){
    if (n==0 || n==1){
        return n;
    }
    else {
        return naive_fibonacci(n-1)+naive_fibonacci(n-2);
    }
}

long not_naive_fibonacci(long n,long *memo){
    if (memo[n] != -1){
        return memo[n];
    }
    if (n <=1){
        memo[n]=1;
    }
    else{
        memo[n]=not_naive_fibonacci(n-1,memo)+not_naive_fibonacci(n-2,memo);
    }
    return memo[n];
}


int main(){
    clock_t start;
    clock_t end;
    start=clock();                                          //start naif
    long res=naive_fibonacci(N);
    end=clock();                                            //stop naif
    double duree = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Resultat naif : %ld \n",res);
    printf("Temps d'exécution naive : %f s\n", duree);

    start=clock();                                          //start non naif
    long *memory = malloc((N + 1) * sizeof(long));
    for (int i=0;i<=N;i++) {
        memory[i]=-1;
    }
    res = not_naive_fibonacci(N,memory);
    end=clock();                                            //stop non naif
    duree = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("Resultat non naif : %ld \n",res);
    printf("Temps d'exécution not naive : %f s\n", duree);

    free(memory);
    return 0;
}