#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 10000

int is_square(int x) {
    int y = sqrt(x);
    return y*y == x; 
}

int prime_prev(int *primes,int prime) {
    while (!primes[--prime]);
    return primes[prime];    
}

int main() {
    int *primes = malloc(SIZE*sizeof(int));
    if (!primes) {
        fprintf(stderr,"malloc fail\n");
        exit(1);
    }    
    for (int i=0; i<SIZE; i++) {
        primes[i] = i;    
    }
    for (int j=2; j<SIZE/2; j++) {
        for (int i=2*j; i<SIZE; i+=j) {
	        primes[i] = 0;
        }
    }

    int brk=0;
    for (int n=3; brk != 1 && n<SIZE; n+=2) {  
        int p = prime_prev(primes,n);
        while (!is_square((n-p)/2)) {
            if (p==1) {
                if ( primes[n] == 0) {
                    brk=1;
                    printf("%d\n",n);
                }
                break;            
            }
            p = prime_prev(primes,p);            
        }
    }  

    free(primes);
    return 0;
}
