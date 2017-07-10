#include <stdio.h>
#include <omp.h>
#include <math.h>

long is_pentagonal(long n) {
	long m = (1 + sqrt(1 + 24*n))/6;
	return (n == ((m*(3*m-1)/2)));
}

long is_hexagonal(long n) {
	long hn = (1 + sqrt(1 + 8*n))/4;
	return (n == (hn*(2*hn-1)));
}

int main() {
	for (long n=1; n<10000000; n++) {
		long tn = n*(n+1)/2;
		if (is_pentagonal(tn) && is_hexagonal(tn)) {
			printf("%ld which gives %ld\n",n,tn); 
		}
	}
	return 0;
}
