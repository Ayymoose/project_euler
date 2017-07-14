#ifndef PRIME_LIST_H
#define PRIME_LIST_H

typedef struct {
	int *primes;
	int length;
} prime_list;

prime_list* create_prime_list(int n);

void free_prime_list(prime_list *pl);

void print_prime_list(prime_list *pl);

#endif
