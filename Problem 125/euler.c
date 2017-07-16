#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "euler.h"

int* generate_palindromes(int n, int *length) {
	/*
	9	    1 - a			a
	9	    2 - aa			10*a + 1*a
	90	    3 - aba			100*a + 10*b + 1*a
	90	    4 - abba		1000*a + 100*b + 10*b + 1*a
	900	    5 - abcba		10000*a + 1000*b + 100*c + 10*b + 1*a
	900	    6 - abccba		100000*a + 10000*b + 1000*c + 100*c + 10*b + 1*a
	9000    7 - abcdcba		1000000*a + 100000*b + 10000*c + 1000*d + 100*c + 10*b + 1*a
	9000    8 - abcddcba
	90000    9 - abcdedcba

	*/
    
	int palindrome;
	int digits = log10(n)+1;
    int size;
    // Optimise this
    switch (digits) {
        case 1: size = 9; break;
        case 2: size = 9*2; break;
        case 3: size = 9*2 + 90; break;
        case 4: size = 9*2 + 90*2;break;
        case 5: size = 9*2 + 90*2 + 900; break;
        case 6: size = 9*2 + 90*2 + 900*2; break;
        case 7: size = 9*2 + 90*2 + 900*2 + 9000; break;
        case 8: size = 9*2 + 90*2 + 900*2 + 9000*2; break;
        default: return NULL; break;
    }	

    int *palindromes = malloc(size * sizeof(int));
       if (palindromes == NULL) return NULL;
    unsigned index = 0;

    for (int i=0; i<=digits; i++) {
		switch (i) {
			case 1: 
				for (int a=1; a<10; a++) {
                    palindromes[index++] = a;
				}
			break;
			case 2: 
				for (int a=1; a<10; a++) {
                    palindromes[index++] = 10*a+a;
				}
			break;
			case 3:
				for (int a=1; a<10; a++) {
					for (int b=0; b<10; b++) {
                        palindromes[index++] = 100*a + 10*b + a;
					}
				}
			break;
			case 4:
				for (int a=1; a<10; a++) {
					for (int b=0; b<10; b++) {
                        palindromes[index++] = 1000*a + 100*b + 10*b + a;
					}
				}
			break;
			case 5:
				for (int a=1; a<10; a++) {
					for (int b=0; b<10; b++) {
						for (int c=0; c<10; c++) {
                            palindromes[index++] = 10000*a + 1000*b + 100*c + 10*b + a;
						}
					}
				}
				break;
			case 6:
				for (int a=1; a<10; a++) {
					for (int b=0; b<10; b++) {
						for (int c=0; c<10; c++) {
                            palindromes[index++] = 100000*a + 10000*b + 1000*c + 100*c + 10*b + a;
						}
					}
				}
			break;
			case 7:
				for (int a=1; a<10; a++) {
					for (int b=0; b<10; b++) {
						for (int c=0; c<10; c++) {
							for (int d=0; d<10; d++) {
                                palindromes[index++] = 1000000*a + 100000*b + 10000*c + 1000*d + 100*c + 10*b + a;
							}
						}
					}
				}
			break;
			case 8:
                for (int a=1; a<10; a++) {
					for (int b=0; b<10; b++) {
						for (int c=0; c<10; c++) {
							for (int d=0; d<10; d++) {
                                palindromes[index++] = 10000000*a + 1000000*b + 100000*c + 10000*d + 1000*d + 100*c + 10*b + a;
							}
						}
					}
				}
			break;
			default: break;
		}
	}
    *length = size;
    return palindromes;
}
