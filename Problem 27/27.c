#include <stdio.h>
#include <stdlib.h>

#define SIZE 111000

int main() {

    int *primes = calloc(SIZE,sizeof(int));
    if (!primes) {
        fprintf(stderr,"calloc fail\n");
        exit(1);
    }

    for (int j=2; j<SIZE/2; j++) {
        for (int i=2*j; i<SIZE; i+=j) {
            primes[i]=1;
        }
    }

    int length = 0;
    int max_length = 0;
    int max_a = 0;
    int max_b = 0;

    for (int a=-999; a<1000; a++) {
        for (int b=-1000; b<=1000; b++) {
            for (int n=0; ; n++) {
                int p = n*n + a*n + b;
                if (p < 0 || primes[p]) break;
                length++;                
            }
            if (length > max_length) {
                max_length = length;
                max_a = a;
                max_b = b;
            }
            length = 0;
        }
    }

    printf("a = %d b = %d length = %d\n",max_a,max_b,max_length);  
    free(primes);
    return 0;
}
