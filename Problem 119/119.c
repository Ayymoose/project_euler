#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int digit_sum( long n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int comp(const void *a,const void *b) {
    if (*( long*)a - *( long*)b == 0) {
        return 0;
    } else if (*( long*)a - *( long*)b > 0) {
        return 1;
    } else {
        return -1;
    }
}

int main() {
    long elems[32];
    int an = 0;
    for (int x=2; x<70; x++) {
        for (int n=2; n<20; n++) {
            long r = pow(x,n);
            if (digit_sum(r) == x && r>9) {
                elems[an++] = r;  
            }
        }
    }
    qsort((void*)elems,32,sizeof(long),comp);
    printf("\n%ld\n",elems[29]);
    return 0;
}
