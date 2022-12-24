#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "../include/databaseFunctionality.h"
#include "../include/studentStruct.h"
#include "databaseFunctionality.c"

/*
Useful links for creating C project:
   - https://www.reddit.com/r/C_Programming/comments/qim1zv/how_should_i_structure_my_c_project/
   - https://stackoverflow.com/questions/11557237/how-to-use-extern-struct-to-share-variables-in-c-programming-and-compile-with
   - https://stackoverflow.com/questions/228684/how-to-declare-a-structure-in-a-header-that-is-to-be-used-by-multiple-files-in-c
   - https://stackoverflow.com/questions/6316987/should-struct-definitions-go-in-h-or-c-file
   - https://www.tutorialspoint.com/cprogramming/c_structures.htm
   - 
*/


int main() {
   printf("Hello World!\n");
   char fileName[50] = "studentDatabase.txt";
   int sizeVar;
   int *size=&sizeVar;
   *size = 5;
   
   //printf("%d", *size);
   create_class_list(fileName, size);
   //illustratePointerMechanics();
   //create_class_list();
   //practiceSyntax();

   return 0;
}