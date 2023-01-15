#include <stdio.h>
#include <math.h>

#define N 4
#define iterN 2*N-1

void print_squareMatrix_diag(int mat[][N]){
    //i is row, j is column => ith row jth column
    int i, j, x, y;

    for (x = 0; x < N; x++)
    {
        i=x;    //ith column is xth row
        j=0;    //jth column is 0th col

        while(i>=0){
            printf("%d ", mat[i][j]);
            // printf("ij: %d %d ", i, j);
            i--;
            j++;
        }
    }

    //start y at 1 to skip duplication
    for (y = 1; y < N; y++)
    {
        i=N-1;
        j=y;
        while(j<=N-1){
            printf("%d ", mat[i][j]);
            i--;
            j++;
        }
    }
    
    
}

/*
1 2 3 4
5 6 7 9
1 2 3 4
5 6 7 9

ij: {00} {01 10} {20 11 02} {30 } 


*/