#include <stdio.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} vec2;

// dot two vectors
int dot(const vec2 *a,const vec2 *b) {
    return (a->x * b->x) + (a->y * b->y);
}

int main() {
    vec2 a;
    vec2 b;
    int s1=0; int s2=0;

    for (int x1=0; x1<=50; x1++) {
        for (int y1=0; y1<=50; y1++) {
            for (int x2=0; x2<=50; x2++) {
                for (int y2=0; y2<=50; y2++) {
                    if ( !((x1 == 0 && y1 == 0) || (x2 ==0 && y2 ==0) || (x1 == x2 && y1 == y2)) ) {
                        a.x = x1; a.y = y1;
                        b.x = x2; b.y = y2;
                        if (dot(&a,&b) == 0) {
                           s1++;
                        }
                        a.x = -x1; a.y = -y1;
                        b.x = x2-x1; b.y = y2-y1;
                        if (dot(&a,&b) == 0) {
                           s2++;
                        }
                    }
                }
            }   
        }
    }
    printf("%d\n",s1/2+s2);
    return 0;
}
