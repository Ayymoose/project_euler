#include <stdio.h>


typedef struct {
    int value;
    int x;
    int y;
} triple;

#define R 5
#define C 5

int main() {

    triple ts[R*C] = {0};
    //[*,*,...]    
    // -> (884,0,2)

    int matrix[R][C] = {0};
    FILE *fp = fopen("matrix_5_5.txt","r");
    if (fp) {
        for (int x=0; x<R; x++) {
            for (int y=0; y<C; y++) {
                fscanf(fp,"%d,",&matrix[x][y]);
            }
        }

    }
    fclose(fp);

    int current = 0;
    for (int x=0; x<R; x++) {
        for (int y=0; y<C; y++) {
            
        }
    }
    
    ts[0].value = 884;
    ts[0].x = 0;
    ts[0].y = 1;

    printf("(%d,%d,%d)\n",ts[0].value,ts[0].x,ts[0].y);


    for (int x=0; x<R; x++) {
    printf("[");
        for (int y=0; y<C-1; y++) {
            printf("%d,",matrix[x][y]);
        }
    printf("%d]\n",matrix[x][C-1]);
    }

    return 0;
}
