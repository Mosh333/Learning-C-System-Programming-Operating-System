#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "../include/sortWordsInFileFunctionality.h"
#include "../include/wordStruct.h"
#include "sortWordsInFileFunctionality.c"

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
   char fileName[50] = "words.txt";  //for windows: .\\src\\studentDatabased.txt, for linux: ./src/studentDatabase.txt
   int sizeVar1, sizeVar2;
   int *size1=&sizeVar1;
   int *size2=&sizeVar2;
   *size1 = 0;
   *size2 = 0;

   char **wordList1, **wordList2;

   wordList1 = read_words(fileName, &size1);
   wordList2 = read_words(fileName, &size2);

   sort_words(wordList1,size1);
   sort2_words(wordList2,size2);
   
   

   return 0;
}