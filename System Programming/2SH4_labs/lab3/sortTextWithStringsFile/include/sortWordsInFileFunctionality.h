#ifndef SORTWORDSINFILEFUNCTIONALITY_H_   /* Include guard */
#define SORTWORDSINFILEFUNCTIONALITY_H_

#include "wordStruct.h"

char **read_words( const char *input_filename, int *nPtr);

//use insertion sorts
void sort_words(char **wordList, int size);

//use bubble sort
void sort2_words(char **wordList, int size);

//
void compareLexicographicalOrder(char **wordList, int index1, int index2);

// int find(int idNo, student **list, int size);

// void input_grades( char *filename, student **list, int size );

// void compute_final_course_grades(student **list, int size);

// void output_final_course_grades(char *filename, student **list, int size);

// void print_list( student **list, int size);

// void withdraw(int idNo, student **list, int *sizePtr);

// void destroy_list(student **list, int *sizePtr);

// void practiceSyntax();

// void illustratePointerMechanics();

#endif