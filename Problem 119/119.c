#include <stdio.h>
#include <math.h>
#include <omp.h>

long digit_power_sum(unsigned long n) {
    int sum = 0;
    int tmp = n;
    while (tmp) {
           sum += tmp % 10;
           tmp /= 10;
    }
    if (sum == 1) return 0;
    // power method
    int e = 2;
    while (pow(sum,e) < n) {
        e++;
     //   printf("pow(%d,%d) = %d\n",sum,e,(int)pow(sum,e));
    }
    return (long)pow(sum,e) == n;
}

int main() {
   // digit_power_sum(512);
    #pragma omp parallel for 
    for (long i=205962976; i<9999999999; i++) {
        if (digit_power_sum(i)) printf("%ld\t%ld\n",i,digit_power_sum(i));
    }    
    return 0;
}
