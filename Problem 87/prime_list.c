#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "prime_list.h"



// Effective for ranges up to < 200,000,000
prime_list* create_prime_list(int n) {
	prime_list *pl = malloc(sizeof(prime_list));
	if (pl == NULL) {
		return NULL;	
	}

	int *ps = malloc(n * sizeof(int));
	if (pl == NULL) {
		free(pl);
		return NULL;
	}
	// Populate
	#pragma omp parallel for
	for (int i=0; i<n; i++) {
		ps[i] = i;
	}
	#pragma omp parallel for
	// Prime sieve filter
	for (int j=2; j<n/2; j++) {
		int i;		
		for (i=2*j; i<n; i+=j) {
			ps[i] = 0;
		}
		while (i<n && !ps[i++]);
	}
	// Resize 
	int actual_primes = 0;
	#pragma omp parallel for reduction(+:actual_primes)
	for (int i=2; i<n; i++) {
		if (ps[i]) {
			actual_primes++;
		}
	}
	int *primes = malloc(actual_primes * sizeof(actual_primes));  	
	if (primes == NULL) {
		free(pl);
		free(ps);
		return NULL;
	}
	for (int i=0,j=2; i<actual_primes; j++) {
		if (ps[j]) {
			primes[i++] = ps[j];
		}
	}
	free(ps);
	
	// Now allocate
	pl->primes = primes;
	pl->length = actual_primes;
	
	return pl;
}

void free_prime_list(prime_list *pl) {
	free(pl->primes);
	free(pl);
}

void print_prime_list(prime_list *pl) {
	printf("[");
	for (int i=0; i<pl->length-1; i++) {
		printf("%d,",pl->primes[i]);
	}
	printf("%d]\n",pl->primes[pl->length-1]);
}


