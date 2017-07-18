#include <stdio.h>
#include <math.h>

int is_increasing(int n) {
    while (n) {
        int d1 = n % 10; 
        n/= 10;
        int d2 = n % 10;
        if (d2 == 0 && n == 0) { break;}
        if (d1 < d2) {return 0;}
    }
    return 1;
}

int is_decreasing(int n) {
    while (n) {
        int d1 = n % 10; 
        n/= 10;
        int d2 = n % 10;
        if (d2 == 0 && n == 0) { break;}
        if (d1 > d2) {return 0;}
    }
    return 1;
}

int is_bouncy(int n) {
   return !is_increasing(n) && !is_decreasing(n);
 /*   int d1=n%10; 
    int d2=(n/10)%10;
    do {
        d1=n%10; 
        n /=10;
        if (!n) return 0;
        d2=n%10;
    } while (d1 == d2 && n);
    
   // printf("d1 = %d d2 = %d\t %d > %d = %d\n",d1,d2,d1,d2,d1>d2);
    if (d1 > d2) {
        // ...68
        while (n) {
            d1 = n % 10;
            n /=10;        
            if (!n) break;    
            d2 = n % 10;
        //    printf("d1 = %d d2 = %d\t %d < %d = %d\n",d1,d2,d1,d2,d1<d2);
            if (d1 < d2) return 1;     
        }  
    } else {
        //...20
        while (n) {
            d1 = n % 10;
            n /=10;            
            if (!n) break;
            d2 = n % 10;
      //      printf("d1 = %d d2 = %d\t %d > %d = %d\n",d1,d2,d1,d2,d1>d2);
            if (d1 > d2) return 1;     
        }
    }
          

    return 0;*/
}

int main() {

    //for (int i=1; i<10000; i++) {
       // if (is_increasing(770)) {
         /*   printf("%d\n",is_increasing(0));
            printf("%d\n",is_increasing(1));
            printf("%d\n",is_increasing(13));
            printf("%d\n",is_increasing(11));
            printf("%d\n",is_increasing(2000));*/
       //     printf("%d\n",is_increasing(2003));
       /*     printf("%d\n",is_increasing(7777));
            printf("%d\n",is_increasing(1234));
            printf("%d\n",is_increasing(4321));
            printf("%d\n",is_increasing(112233));*/
    //    }
   // }
    int bouncy = 0;
    int total = 100;
    do {
        if (is_bouncy(total)) {
            printf("%d\n",total);
            bouncy++;
        }
        total++;
    } while (100*bouncy - 90*total != 0);
    printf("\nbouncy %d\ntotal %d\n",bouncy,total);

    
    return 0;
}
