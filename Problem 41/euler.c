#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>
#include "euler.h"

int is_pandigital(int n) {
    int d;
    int length = log10(n)+1;
    do {
        d = (n % 10);
        n /= 10;
        int ds = n;
	if (d > length) return 0;
        if (d == 0) return 0;
        while (ds) {
            int dss = ds % 10;
            if (dss == d) return 0;
            ds /= 10;
        }
    } while (n);
    return 1;
}

int rotate(int n) {
	// Performs a left rotation of a number
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

int reverse(int n) {
	int rev = 0;
	while(n) {
		rev *= 10;
		rev += n % 10;		
		n /= 10;	
	}
	return rev;
}

int* generate_palindromes(int n, int *length) {
	/*
	9	    1 - a			a
	9	    2 - aa			10*a + 1*a
	90	    3 - aba			100*a + 10*b + 1*a
	90	    4 - abba		1000*a + 100*b + 10*b + 1*a
	900	    5 - abcba		10000*a + 1000*b + 100*c + 10*b + 1*a
	900	    6 - abccba		100000*a + 10000*b + 1000*c + 100*c + 10*b + 1*a
	9000    7 - abcdcba		1000000*a + 100000*b + 10000*c + 1000*d + 100*c + 10*b + 1*a
	9000    8 - abcddcba
	90000    9 - abcdedcba

	*/
    
	int palindrome;
	int digits = log10(n)+1;
    int size;
    // Optimise this
    switch (digits) {
        case 1: size = 9; break;
        case 2: size = 9*2; break;
        case 3: size = 9*2 + 90; break;
        case 4: size = 9*2 + 90*2;break;
        case 5: size = 9*2 + 90*2 + 900; break;
        case 6: size = 9*2 + 90*2 + 900*2; break;
        case 7: size = 9*2 + 90*2 + 900*2 + 9000; break;
        case 8: size = 9*2 + 90*2 + 900*2 + 9000*2; break;
        default: return NULL; break;
    }	

    int *palindromes = malloc(size * sizeof(int));
       if (palindromes == NULL) return NULL;
    unsigned index = 0;

    for (int i=0; i<=digits; i++) {
		switch (i) {
			case 1: 
				for (int a=1; a<10; a++) {
                    palindromes[index++] = a;
				}
			break;
			case 2: 
				for (int a=1; a<10; a++) {
                    palindromes[index++] = 10*a+a;
				}
			break;
			case 3:
				for (int a=1; a<10; a++) {
					for (int b=0; b<10; b++) {
                        palindromes[index++] = 100*a + 10*b + a;
					}
				}
			break;
			case 4:
				for (int a=1; a<10; a++) {
					for (int b=0; b<10; b++) {
                        palindromes[index++] = 1000*a + 100*b + 10*b + a;
					}
				}
			break;
			case 5:
				for (int a=1; a<10; a++) {
					for (int b=0; b<10; b++) {
						for (int c=0; c<10; c++) {
                            palindromes[index++] = 10000*a + 1000*b + 100*c + 10*b + a;
						}
					}
				}
				break;
			case 6:
				for (int a=1; a<10; a++) {
					for (int b=0; b<10; b++) {
						for (int c=0; c<10; c++) {
                            palindromes[index++] = 100000*a + 10000*b + 1000*c + 100*c + 10*b + a;
						}
					}
				}
			break;
			case 7:
				for (int a=1; a<10; a++) {
					for (int b=0; b<10; b++) {
						for (int c=0; c<10; c++) {
							for (int d=0; d<10; d++) {
                                palindromes[index++] = 1000000*a + 100000*b + 10000*c + 1000*d + 100*c + 10*b + a;
							}
						}
					}
				}
			break;
			case 8:
                for (int a=1; a<10; a++) {
					for (int b=0; b<10; b++) {
						for (int c=0; c<10; c++) {
							for (int d=0; d<10; d++) {
                                palindromes[index++] = 10000000*a + 1000000*b + 100000*c + 10000*d + 1000*d + 100*c + 10*b + a;
							}
						}
					}
				}
			break;
			default: break;
		}
	}
    *length = size;
    return palindromes;
}

