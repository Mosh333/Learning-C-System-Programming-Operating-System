#ifndef CONCURRENTSHEARSORT_H_   /* Include guard */
#define CONCURRENTSHEARSORT_H_

#include "arrayStruct.h"

//2SH4 lab3 concepts coming in handy :)
struct arrayStruct create2Darray(const char* fileName, int n);

//old prototype below,
// int **concurrentShearsort(int **arrayPtr, int n);
void concurrentShearsort(struct arrayStruct *myArrayStruct);
void *concurrentShearsort_helper(void *myArrayStruct);
void free_2dArrayStruct(struct arrayStruct *myArrayStruct);
void addByReference(struct arrayStruct *myArrayStruct, int n);

//should it be 
//struct arrayStruct *concurrentShearsort_helper(void *myArrayStruct)??

#endif // CONCURRENTSHEARSORT_H_