#include <stdio.h>
#include <math.h>
#include "diagMat.c"

#define N 4

int main(int argc, char *argv[]) {

   printf("Hello World!\n");
   int testcase1[N][N] = { {100, 23, 132, 66},
                              {74, 45, 65, 95},
                              {75, 49,52, 51},
                              {6, 51, 732, 14}};
    printf("*********************\n");
    printf("Output of is_diag_dom() %d\n", is_diag_dom(testcase1));
    printf("*********************\n");

   int testcase2[N][N] = { {1, 0, 0, 0},
                              {0, 1, 0, 0},
                              {0, 0, 1, 0},
                              {0, 0, 0, 1}};
    printf("Output of is_diag_dom() %d\n", is_diag_dom(testcase2));
    printf("*********************\n");

   int testcase3[N][N] = { {-1, 0, 0, 0},
                              {0, -1, 0, 0},
                              {0, 0, -1, 0},
                              {0, 0, 0, -1}};
    printf("Output of is_diag_dom() %d\n", is_diag_dom(testcase3));
    printf("*********************\n");

   int testcase4[N][N] = { {-1, 0, 0, 0},
                              {0, -1, 0, 0},
                              {0, 0, -1, 0},
                              {0, 0, 0, 0}};
    printf("Output of is_diag_dom() %d\n", is_diag_dom(testcase4));
    printf("*********************\n");

   return 0;
}