#include <stdio.h>
#include <math.h>
#include "sparseVector.c"

#define N 26

int main(int argc, char *argv[]) {

    printf("Hello World!\n");

    printf("*********************\n");
    int source1[] = {0, 0, 23, 0, -7, 0, 0, 48};
    int size1=sizeof(source1)/sizeof(source1[0]);
    int newSource1[size1];
    int new_source1[size1];
    int length1 = countComponents(source1,size1);
    int val1[length1];
    int pos1[length1];
    efficient(source1,val1,pos1,size1);
    reconstruct(newSource1, length1, val1, pos1, size1);
    // for (size_t i = 0; i < size1; i++)
    // {
    //     printf("%d ", newSource1[i]);
    // }
    printf("\n*********************\n");
    int source2[] = {0, -523, 0, 0, 89, 0, 0, 48, 0, 4, 6, 0, 0};
    int size2=sizeof(source2)/sizeof(source2[0]);
    int newSource2[size2];
    int new_source2[size2];
    int length2 = countComponents(source2,size2);
    int val2[length2];
    int pos2[length2];
    efficient(source2,val2,pos2,size2);
    reconstruct(newSource2, length2, val2, pos2, size2);
    // for (size_t i = 0; i < size2; i++)
    // {
    //     printf("%d ", newSource2[i]);
    // }
    printf("\n*********************\n");
    int source3[] = {1, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0};
    int size3=sizeof(source3)/sizeof(source3[0]);
    int newSource3[size3];
    int new_source3[size3];
    int length3 = countComponents(source3,size3);
    int val3[length3];
    int pos3[length3];
    efficient(source3,val3,pos3,size3);
    reconstruct(newSource3, length3, val3, pos3, size3);
    // for (size_t i = 0; i < size3; i++)
    // {
    //     printf("%d ", newSource3[i]);
    // }
    printf("\n*********************\n");
    //pos1 = [2 4 7] + pos2 = [1 4 7 9 10]
    //uniquePos=6
    int addEffVal4[6];
    int addEffPos4[6];
    addEff(val1, val2, addEffVal4, pos1, pos2, addEffPos4, 3, 5);
    printf("\n*********************\n");
    // //pos1 = [2 4 7] + pos2 = [0 8]
    // int addEffVal4[5+];
    // int addEffPos4[];
    // addEff(val1,val2);
    // printf("\n*********************\n");
    // //pos1 = [1 4 7 9 10] + pos2 = [0 8]
    // int addEffVal4[5+];
    // int addEffPos4[];
    // addEff(val1,val2);

   return 0;
}