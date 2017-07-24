#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000000

int main() {
   
    int *factors = calloc(SIZE,sizeof(int));
    if (!factors) {
        fprintf(stderr,"calloc fail\n");
        exit(1);
    }
    for (int j=2; j<SIZE/2; j++) {
        for (int i=2*j; i<SIZE; i+=j) {
	        factors[i]++;
        }
    }

    int i=1;
    int tn = (i*(i+1))/2;
    do {
        tn = (i*(i+1))/2;
        i++;
    } while (factors[tn]+2 < 500);

    printf("%d has %d factors\n",tn,factors[tn]+2);
    free(factors);
    return 0;
}
