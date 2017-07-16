#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "euler.h"
#define N 99999999
            
    // 2906969179

int main() {
    // Find the sum of all the numbers less than 10^8 that are both palindromic and can be written as the sum of consecutive squares.
    // 1^2 + 2^2 
    int size;
	int *ps = generate_palindromes(N,&size);

    /* *7071^2 + 7072^ exceeds 10^8 */
    int limit = 7071; 
    unsigned long sum = 0;
    unsigned long palindrome = 0;

    for (int i=0; i<size ; i++) {
        for (int k=1; k<=limit; k++) {
            for (int j=k; j<=limit; j++) {
                sum += j*j;
                if (sum >= ps[i]) {
                    if (sum == ps[i]) {
                        sum = 0; 
                        if (k!=j) {
                         //   printf("palindrome %d k=%d j=%d i=%d\n",ps[i],k,j,i);
                            palindrome+=ps[i];
                            goto skip;
                        } 
                    } else {
                        sum = 0;                         
                    }
                    break; 
                }
            }
        }
        skip:
            sum=0;
        
    }

    printf("%ld\n",palindrome);
    free(ps);
	return 0;
}
