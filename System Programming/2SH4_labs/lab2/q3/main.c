#include <stdio.h>
#include <math.h>
#include "diagScan.c"

#define N 4

int main(int argc, char *argv[]) {
   printf("Hello World!\n");
   int testcase1[N][N] = { {100, 23, 132, 66},
                              {74, 45, 65, 95},
                              {75, 49,52, 51},
                              {6, 51, 732, 14}};
    printf("*********************\n");
    print_squareMatrix_diag(testcase1);
    printf("\n*********************\n");

    printf("\n%d\n", testcase1[3][0]);
    printf("\n%d\n", testcase1[3][3]);

   return 0;
}