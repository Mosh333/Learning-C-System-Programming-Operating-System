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
   char fileName[50] = "./src/studentDatabase.txt";  //for windows: .\\src\\studentDatabased.txt, for linux: ./src/studentDatabase.txt
   int sizeVar;
   int *size=&sizeVar;
   *size = 0;

   student **classList;
   
   printf("Size originally is before the create_class_list() call is: %d\n", *size);
   classList = create_class_list(fileName, size);
   printf("classList[0]->studentId: %d\n", classList[0]->studentId);
   printf("find() output is: %d\n", find(4580,classList,*size));
   input_grades("./src/studentGrades.txt", classList,*size);
   compute_final_course_grades(classList,*size);
   output_final_course_grades("./src/studentFinalGradesOnly.txt", classList, *size);
   print_list(classList,*size);
   withdraw(4580, classList, size);
   withdraw(9000, classList, size);
   withdraw(1200, classList, size);
   withdraw(32, classList, size);
   //illustratePointerMechanics();
   //create_class_list();
   //practiceSyntax();
   printf("Size after the create_class_list() call is: %d\n", *size);

   return 0;
}