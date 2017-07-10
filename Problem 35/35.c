#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <stdlib.h>

// Generate a list of primes less than n
int** prime_list(int n) {
	int *primes = malloc(n * sizeof(n));	
	// Populate
	for (int i=0; i<n; i++) {
		primes[i] = i;
	}
	// Prime sieve filter
	for (int j=2; j<n/2; j++) {
		for (int i=2; i*j<n; i++) {
			primes[i*j] = 0;
		}
	}
	// Re-allocate 

	int actual_primes = 0;
	// 1 is not prime
	for (int i=2; i<n; i++) {
		if (primes[i]) {
			actual_primes++;
		}
	}
	int *new_primes = malloc(actual_primes * sizeof(actual_primes));  	
	for (int i=0,j=2; i<actual_primes && j<n; j++) {
		if (primes[j]) {
			new_primes[i++] = primes[j];
		}
	}
	free(primes);
	//Pointer for length + prime list
	int **ps = malloc(2 * sizeof(int*));
	int *size = malloc(sizeof(int));	//Do not take the local address of a variable
	*size = actual_primes;
	ps[0] = new_primes; 
	ps[1] = size;  

	return ps;
}

void print_prime_list(int **p) {
	int *ps = p[0];
	int length = *p[1];
	printf("[");
	for (int i=0; i<length-1; i++) {
		printf("%d,",ps[i]);
	}
	printf("%d]\n",ps[length-1]);
}

int cmpfunc(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void free_prime_list(int **p) {
	free(p[0]);
	free(p[1]);
	free(p);
	// free a prime list
}

int rotate_number(int n) {
	// Does a left rotation of a number
	// 719 <- 197
	int r = 0;
	int p = 1;
	while (n > 9) {	
		r += pow(10,p) * (n % 10);
		n /= 10;
		p++;
	}
	r += n;
	return r;
}


int main() {

	int **p = prime_list(1000000);
	int length = *p[1];
	int *ps = p[0];
	int circular_primes = 0;
	
	//123,231,312,
	
	for (int i=0; i<length; i++) {
		// Get a prime
		int is_not_circular = 0;
		int prime = ps[i];
		// Perform rotations
		for (int j=0; j<log10(prime); j++) {
			// Check if prime is circular		
			int *item = (int*) bsearch (&prime, ps, length, sizeof (int), cmpfunc);
			if (item == NULL) {
				is_not_circular = 1;
				break;
			} 
			prime = rotate_number(prime);
		} 
		if (!is_not_circular) {
			circular_primes++;
			is_not_circular=0;
		}
	}

	printf("Number of circular primes below %d equals %d\n",1000000,circular_primes);
	// Not really -> I manually sifted through all the primes that contained a 0 in them
	// Answer -> 55
	free_prime_list(p);
	return 0;
}
