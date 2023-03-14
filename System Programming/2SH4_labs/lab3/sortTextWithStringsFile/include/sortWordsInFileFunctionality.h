#ifndef SORTWORDSINFILEFUNCTIONALITY_H_   /* Include guard */
#define SORTWORDSINFILEFUNCTIONALITY_H_

#include "wordStruct.h"

char **read_words( const char *input_filename, int *nPtr);

//use insertion sorts
void sort_words(char **wordList, int size);

//use bubble sort
void sort2_words(char **wordList, int size);

//compare the lexicographical order of the words
void compareLexicographicalOrder(char **wordList, int index1, int index2);


#endif