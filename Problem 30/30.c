#include <stdio.h>
#include <omp.h>

int power_digit_sum_5(int n) {
    int sum = 0;    
    while (n) {
        sum += (n % 10)*(n % 10)*(n % 10)*(n % 10)*(n % 10);
        n /= 10;
    }
    return sum;
}

int main() {
    int sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for (int i=2; i<9999999; i++) {
        int pds = power_digit_sum_5(i);
        if (pds == i) {
            sum += i;
           // printf("%d\n",i);
        }
    }
    printf("\n%d\n",sum);
    return 0;
}
