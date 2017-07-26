#include <stdio.h>
#include <math.h>
#include <gmp.h>
#include <stdlib.h>
#include <string.h>

int main() {
    mpz_t xx;
    mpz_init (xx);
    char *result;
    int count=0;
    for (int x=1; x<10; x++) {
        for (int n=1; n<22; n++) {
            mpz_set_ui(xx,x);
            mpz_pow_ui(xx,xx,n);
            result = mpz_get_str(NULL,10,xx);
            if (strlen(result) == n) {
                gmp_printf ("%Zd = %d ^ %d\n",xx,x,n);
                count++; 
            }
            free(result);
        }
    }
    printf("\n%d\n",count);
    mpz_clear(xx);
    return 0;
}
