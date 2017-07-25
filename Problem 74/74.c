#include <stdio.h>
#include <omp.h>
#include "../euler/euler.h"

int init_chain_length(int n) {
    switch (n) {
        case 2:
        case 145:
        case 40585:
            return 1;
        case 871:
        case 872:
        case 45631:
        case 45632:
            return 2;
        case 169:
        case 1454:
        case 363601:
            return 3;
        default:
           return 1;
    }
}

int main() {

/*

    number  chain_length     

    2           1           
    145         1           
    169         3           
    871         2
    872         2
    1454        3
    40585       1
    45631       2
    45632       2
    363601      3

    */
    
    int sixty_chains = 0;
    #pragma omp parallel for reduction (+:sixty_chains)
    for (int n=3; n<1000000; n++) {    
        int cc = n;  
        int chain_length = init_chain_length(cc);
        for (int i=0; i<60; i++) {
            chain_length++;            
            cc = digit_factorial_sum(cc);
            if (cc == 2 || cc == 145 || cc == 169 || cc == 871 || cc == 872 || cc == 1454 || cc == 40585 || cc == 45631 || cc == 45632 || cc == 363601) {
                chain_length += init_chain_length(cc)-1;
                break;
            }
        }
        if (chain_length == 60) {
            sixty_chains++;
        }
    }
    printf("%d\n",sixty_chains);
    return 0;
}
