#include <stdio.h>
#include <math.h>
#include "letter_freq.c"

#define N 26

int main(int argc, char *argv[]) {
   printf("Hello World!\n");
   char word1[] = "word";
   int letterFreq1[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
   printf("*********************\n");
   letter_freq(word1, letterFreq1);
   print_letter_freq(word1, letterFreq1);
   printf("\n*********************\n");
   char word2[] = "AbSoRptIoMEtrIc";
   int letterFreq2[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
   printf("*********************\n");
   letter_freq(word2, letterFreq2);
   print_letter_freq(word2, letterFreq2);
   printf("\n*********************\n");
   char word3[] = "";
   int letterFreq3[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
   printf("*********************\n");
   letter_freq(word3, letterFreq3);
   print_letter_freq(word3, letterFreq3);
   printf("\n*********************\n");


   return 0;
}