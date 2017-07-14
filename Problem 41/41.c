#include <stdio.h>
#include <stdlib.h>
#include "prime_list.h"

int main() {
	prime_list *p = create_prime_list(999999999);
	//print_prime_list(p);
	printf("Length %d\n",p->length);
	//free_prime_list(p);
	return 0;
}

/*
	100m 0m15.093s
	299m 0m59.660s
	399m 1m27.943s
	499m 1m57.786s
	599m 2m35.930s
	699m 3m23.022s
	799m 4m14.884s
	899m 5m20.725s

4	999m 6m26.204s
12	999m 1m47.437s

*/
