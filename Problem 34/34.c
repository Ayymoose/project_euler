#include <stdio.h>
#include <omp.h>

int fac(int n) {
	int r = 1;
	for (int i=n; i>0; i--) {
		r = r * i;
	}
	return r;
}	

int df(int n) {
	int r = 0;
	int nn = n;
	while (n) {
		r += fac(n % 10);
		n /= 10;
	}
	return (r == nn);
}

int main() {
	for (int i=3; i<9999999;i++) {
		if (df(i)) {
			printf("df(%d) = %d\n",i,df(i));
		}
	}
	return 0;
}
