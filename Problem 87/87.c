#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include "prime_list.h"

#define LIMIT 50000000

int main() {
	//How many numbers below fifty million can be expressed as the sum of a prime square, prime cube, and prime fourth power?
	int *primes = calloc(LIMIT,sizeof(int));	// Memory hungry!!! ~190MB
	prime_list *p = create_prime_list(7081); 	// 7081 is the first prime after 7071
	int *ps = p->primes;	
	
	int x_l,y_l,z_l;
	x_l = y_l = z_l = 0;
	int i=0;
	while ( x_l ==0 || y_l == 0 || z_l == 0) {
		if (ps[i] > 7071 && x_l == 0) {
			x_l = i-1;	
		}
		if (ps[i] > 368 && y_l == 0) {
			y_l = i-1;
		}
		if (ps[i] > 85 && z_l == 0) {
			z_l = i-1;
		}
		i++;
	}

	for (int x=0; x<=x_l; x++) {
		for (int y=0; y<=y_l; y++) {
			for (int z=0; z<=z_l; z++) {
				int number = ps[x]*ps[x] + ps[y]*ps[y]*ps[y] + ps[z]*ps[z]*ps[z]*ps[z];
				if (number < LIMIT) {
					primes[number] = number;
				}	
			}
		}
	}

	int count = 0;
	for (int i=0; i<LIMIT; i++) {
		if (primes[i]) {
			count++;
		}
	}	

	printf("%d\n",count);
	free_prime_list(p);
	free(primes);
	return 0;
}
