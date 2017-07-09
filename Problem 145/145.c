#include <stdio.h>
#include <omp.h>

int reverse(int n) {
	int rev = 0;
	while(n) {
		rev *= 10;
		rev += n % 10;		
		n /= 10;	
	}
	return rev;
}

int oddd(int n) {
	while (((n % 10) & 1) && (n > 9)) {
		n /= 10;
	}
	return (n & 1);
}

int main() {
	int sum = 0;
	int count = 0;
	#pragma omp parallel
	{
		#pragma omp for reduction(+:count) 
		for (int n=1; n<1000000000; n++) {
			sum = n + reverse(n);
			// Branch predictor performance is better WITH the branch for this problem
			if (oddd(sum) && (n % 10)) {
				count++;
			} 			
			//count += oddd(sum) && (n % 10);
		}
	}
	printf("%d\n",count);
	return 0;
}

// gcc 145.c -o 145.o -fopenmp -Ofast
