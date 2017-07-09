#include <stdio.h>
#include <omp.h>
#include <math.h>

int p(int n) {

	// p = a + b + c
	// c = p - a - b

	// a*a + b*b = c*c
	// a*a + b*b = (p - a - b)*(p - a - b)

	int solutions = 0;
	for (int a=3; a<n/2; a++) {
		for (int b=4; b<n/2; b++) {
			// Includes permutations too
			if ( (a*a + b*b) == (n - a - b)*(n - a - b)) {
				//printf("(%d,%d,%d)\n",a,b,n-a-b);
				solutions++;
			}
		}
	}
	return solutions;
}

int main() {
	// Race condition present
	int m = 0,in = 0;
	int max = 0;
	int ind = 0;
	// Skip all the odd solutions
	#pragma omp parallel
	{ 
		#pragma omp for 
		for (int i=12; i<1000; i+=2) {
			if (p(i) > max) {
				max = p(i);
				ind = i;
			}
			//printf("Solutions for %d = %d\n",840,p(840));
		}
	#pragma omp critical
		{
			m = max;
			in = ind;
		}
	}
	printf("Max %d\nIndex %d\n",m,in);
	return 0;
}

//gcc 39.c -o 39.o -fopenmp -lm -Ofast
// 0.0049s
