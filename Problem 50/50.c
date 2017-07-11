#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *primes;
	int length;
} prime_list;

prime_list* create_prime_list(int n) {
	prime_list *pl = malloc(sizeof(prime_list));
	if (pl == NULL) {
		return NULL;	
	}
	int *ps = malloc(n * sizeof(int));
	// Not gonna bother checking for null here...
	// Populate
	for (int i=0; i<n; i++) {
		ps[i] = i;
	}
	// Prime sieve filter
	for (int j=2; j<n/2; j++) {
		for (int i=2; i*j<n; i++) {
			ps[i*j] = 0;
		}
	}
	// Resize 
	int actual_primes = 0;
	// 1 is not prime
	for (int i=2; i<n; i++) {
		if (ps[i]) {
			actual_primes++;
		}
	}
	int *primes = malloc(actual_primes * sizeof(actual_primes));  	
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

int cmpfunc(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main() {
	//[2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97]
	//77 8
	const int limit = 1000000;
	prime_list *p = create_prime_list(limit);
	int *item;
	int max_prime_length = 0;
	int max_prime_sum = 0;
	// Start at an index
	for (int i=0; i<p->length; i++) {
		int prime_sum = 0;
		int prime_length = 0;
		// Find consecutive sum of primes up until limit
		for (int j=i; prime_sum+p->primes[j] < limit && j<p->length; j++) {
			prime_sum += p->primes[j];
			prime_length++;
		} 
		// If it's a prime then record its consecutive sum length
		// Otherwise backtrace till the first prime
		while ( (item = (int*) bsearch (&prime_sum, p->primes, p->length, sizeof (int), cmpfunc)) == NULL ) {
			if (!prime_length) break;
			prime_sum -= p->primes[--prime_length+i];
		}
		if (prime_length > max_prime_length) {
			max_prime_length = prime_length;
			max_prime_sum = prime_sum;
		}
		
	}
	printf("max_prime_sum = %d\tmax_prime_length = %d\n",max_prime_sum,max_prime_length);
	free_prime_list(p);

	return 0;
}
