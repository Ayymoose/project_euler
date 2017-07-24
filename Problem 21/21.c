#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

int main() {
    int *primes = calloc(SIZE,sizeof(int));
    if (!primes) {
        fprintf(stderr,"calloc fail\n");
        exit(1);
    }
    for (int j=2; j<SIZE/2; j++) {
        for (int i=2*j; i<SIZE; i+=j) {
            primes[i]+=j;
        }
    }
    int amicable_sum = 0;
    for (int n=1; n<10000; n++) {
        int dn = primes[n]+1;
        if (primes[dn]+1 == n && n != dn) {
            amicable_sum+=n;
        } 
    }
    printf("%d\n",amicable_sum);
    free(primes);
    return 0;
}
