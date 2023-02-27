#include <stdio.h>
#include <math.h>
#include "concurrentShearsort.c"

int main(void){

    printf("Hello World!\n");
    struct arrayStruct myArrayStruct1 = create2Darray("input.txt", 4);
    printf("Printing results from the outside:\n");
    printf("myArrayStruct1.twoD_array is:\n");
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            printf("%d ", myArrayStruct1.twoD_array[i][j]);
        }
        printf("\n");
    }
    printf("myArrayStruct1.n: %d\n", myArrayStruct1.n);
    printf("myArrayStruct1.currentIter: %d\n", myArrayStruct1.currentIter);
    printf("myArrayStruct1.maxIters: %d\n", myArrayStruct1.maxIter);
    // int **myArrPtr = create2Darray("threeByThree.txt", 3); 

    /*
    Learning how to pass and modify by reference
    addByReference(&myArrayStruct1, 4);
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            printf("%d ", myArrayStruct1.twoD_array[i][j]);
        }
        printf("\n");
    }    
    printf("myArrayStruct1.currentIter: %d\n", myArrayStruct1.currentIter);
    printf("myArrayStruct1.maxIters: %d\n", myArrayStruct1.maxIter);
    */
    concurrentShearsort(&myArrayStruct1);
    free_2dArrayStruct(&myArrayStruct1);
    printf("***************************************\n");
    struct arrayStruct myArrayStruct2 = create2Darray("threeByThree.txt", 3);
    concurrentShearsort(&myArrayStruct2);

    return 0;
}