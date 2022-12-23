#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../include/databaseFunctionality.h"
#include "../include/studentStruct.h"
#include "databaseFunctionality.c"

/*
Useful links for creating C project:
   - https://stackoverflow.com/questions/11557237/how-to-use-extern-struct-to-share-variables-in-c-programming-and-compile-with
   - 
*/


int main() {
   printf("Hello World!\n");
   
   output_final_course_grades();

   return 0;
}