#include <stdio.h>
#include <math.h>
#include "diagMat.h"

#define N 4


int is_diag_dom(int mat[][N]){
    int result =1;
    int diagCounter=0;
    int nonDiagCounter=0;

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            if(i==j){
                diagCounter = diagCounter + fabs(mat[i][j]);
            }else{
                nonDiagCounter = nonDiagCounter+ fabs(mat[i][j]);
            }
            printf("%d ", mat[i][j]);
        }
        if(nonDiagCounter>=diagCounter){
            result = 0;
        }
        diagCounter=0;
        nonDiagCounter=0;
        printf("\n");
    }
    
    if(result==1){
        printf("diagonally dominant\n");
    }else if(result==0){
        printf("diagonally indominant\n");
    }

    return result;
}