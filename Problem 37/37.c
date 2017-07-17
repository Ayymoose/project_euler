#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>
#include "../euler/euler.h"

int cmpfunc(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int is_truncatable_prime(prime_list *ps, int n) {
    int tp;
    int *item;
    int tmp = n;
    while (tmp) {
        tp = tmp;
        item = (int*) bsearch (&tp, ps->primes, ps->length-4, sizeof (int), cmpfunc);
        if (item == NULL) return 0;
        tmp /= 10;
    }
    tmp = n;
    for (int i=log10(tmp)+1; i>0; i--) {
        tp = tmp % (int)pow(10,i);
        item = (int*) bsearch (&tp, ps->primes, ps->length-4, sizeof (int), cmpfunc);
        if (item == NULL) return 0;
    }

    return 1;
}

int truncate_right(int n) {
    while (n) {
        printf("%d ", n);
        n /= 10;
    }
    printf("\n");
    return 0;
}

int truncate_left(int n) {
    for (int i=log10(n)+1; i>0; i--) {
        printf("%d ", n % (int)pow(10,i));
    }
    printf("\n");
    return 0;    
}

int main() {

    /* Find the sum of the only eleven primes that are both truncatable from left to right and right to left */
    prime_list *ps = create_prime_list(1000000);
    int sum = 0;
    for (int i=4; i<ps->length; i++) {
        if (is_truncatable_prime(ps,ps->primes[i])) sum+= ps->primes[i]; //printf("%d\n",ps->primes[i]);
    }
    printf("%d\n",sum);
    free_prime_list(ps);
    return 0;
}
