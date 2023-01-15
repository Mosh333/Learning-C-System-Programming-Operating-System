#include <stdio.h>
#include <math.h>
#include "vectorLibrary.c"



int main(int argc, char *argv[]) {
   printf("Hello World!\n");
   double testcase1[10] = {100, 23, 132, 66, 74, 45, 65, 95, 75, 49};
   print_vector(testcase1, sizeof(testcase1)/sizeof(double));
   print_vector_bad(testcase1, sizeof(testcase1)/sizeof(double));

   double testcase2a[5] = {1,2,3,4,5};
   double testcase2b[5] = {1,2,3,4,5};
   double testcase2Result[5];
   add_vectors(testcase2a, testcase2b, testcase2Result, sizeof(testcase2a)/sizeof(double));
   print_vector(testcase2Result, sizeof(testcase2Result)/sizeof(double));

   double testcase3a[5] = {1,2,3,4,5};
   double testcase3b[5] = {1,2,3,4,5};
   printf("%.2f\n", scalar_prod(testcase3a, testcase3b, sizeof(testcase3a)/sizeof(double)));

   double testcase4[5] = {1,2,3,4,5};
   printf("%.2f\n",norm2(testcase4, sizeof(testcase4)/sizeof(double)));

   return 0;
}