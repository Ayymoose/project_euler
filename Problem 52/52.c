#include <stdio.h>

int same_digits(int a,int b) {
    int digits[10] = {0}; 
    while (a) {
        digits[a % 10]++;
        a /= 10;
    }
    while (b) {
        digits[b % 10]--;
        b /= 10;
    }
    for (int i=0; i<10; i++) {
        if (digits[i] > 0) return 0;
    }
    return 1;
}

int main() {
    for (int i=1; i<999999; i++) {
        if (same_digits(i,2*i) && same_digits(3*i,4*i) && same_digits(5*i,6*i)) {
            printf("(%d,%d,%d,%d,%d,%d)\n",i,2*i,3*i,4*i,5*i,6*i);
            break;
        }
    }
    return 0;
}
