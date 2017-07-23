#include <stdio.h>
#include <gmp.h>
#include <string.h>
#include <stdlib.h>

void strrev(char *str) {
    char *start = str;
    char *end = str+strlen(str)-1;
    char temp;    
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int is_palindrome(char *str) {
    char *start = str;
    char *end = str+strlen(str)-1;
    while (start < end) {
        if (*start != *end) return 0;
        start++; end--; 
    }
    return 1;
}

int lychrel_number(int i) {
    mpz_t n,n_rev,result;
    mpz_init(n);
    mpz_init(n_rev);
    mpz_init(result);
    mpz_set_ui(n,i);
    for (int i=0; i<50; i++) {
        char *reverse = mpz_get_str(NULL,10,n);
        strrev(reverse);  
        mpz_clear(n_rev);
        mpz_init_set_str(n_rev,reverse,10);
        mpz_add(result, n, n_rev);
        mpz_set(n,result);  
        char *result_string = mpz_get_str(NULL,10,result);    
        free((void*)reverse);
        if (is_palindrome(result_string)) {
            free((void*)result_string);
            mpz_clear(n);
            mpz_clear(n_rev);
            mpz_clear(result);
            return 0;
        } else {
            free((void*)result_string);
        }
    }
    mpz_clear(n);
    mpz_clear(n_rev);
    mpz_clear(result);
    return 1;
}

int main() {
    int lychrel = 0;
    for (int i=1; i<10000; i++) {
        lychrel += lychrel_number(i);
    }
    printf("%d\n",lychrel);
	return 0;
}
