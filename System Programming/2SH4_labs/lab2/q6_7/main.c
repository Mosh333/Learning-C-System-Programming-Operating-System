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
    printf("val1 and pos1\n");
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
    printf("val2 and pos2\n");
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
    printf("val3 and pos3\n");
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
    // addEff(val1, val2, addEffVal4, pos1, pos2, addEffPos4, 3, 5);
    addEff(val2, val1, addEffVal4, pos2, pos1, addEffPos4, 5, 3);
    printf("\n*********************\n");
    // //pos1 = [2 4 7] + pos3 = [0 8]
    //uniquePos=5
    int addEffVal5[5];
    int addEffPos5[5];
    addEff(val1,val3, addEffVal5, pos1, pos3, addEffPos5, 3, 2);
    // addEff(val3, val1, addEffVal5, pos3, pos1, addEffPos5, 2, 3);
    printf("\n*********************\n");
    // //pos1 = [1 4 7 9 10] + pos2 = [0 8]
    int addEffVal6[7];
    int addEffPos6[7];
    // addEff(val2,val3, addEffVal6, pos2, pos3, addEffPos6, 5, 2);
    addEff(val3,val2, addEffVal6, pos3, pos2, addEffPos6, 2, 5);
    printf("\n*********************\n");

   return 0;
}