#ifndef EULER_H
#define EULER_H

typedef struct {
	int *primes;
	int length;
} prime_list;


/* Generate a list of primes up to n */
prime_list* create_prime_list(int n);

/* Free the prime list */
void free_prime_list(prime_list *pl);

/* Print it out*/
void print_prime_list(prime_list *pl);

/* Generate palindromes up to n */
int* generate_palindromes(int n, int *length); 

/* Performs a left rotation on an integer */
int rotate(int n);

/* Reverse an integer n */
int reverse(int n);

/* Returns whether an integer is pandigital */
int is_pandigital(int n);


#endif
