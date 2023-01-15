#include <stdio.h>
#include <math.h>
#include "string_copy.c"

#define N 26

int main(int argc, char *argv[]) {
    // String Shenanigans below:
    // char tempStr[0] = '\0';  //fails
    // char tempStr[0] = "\0";  //works
    // char tempStr[0] = "";    //works
    // char tempStr[0] = {'\0'};   //works
    /*
    char tempStr[0];
    tempStr[0] = 0;
    */
    // printf("First char is: \"%c\"\n", tempStr[0]);

   printf("Hello World!\n");

    printf("*********************\n");
    int s1 = 4;
    char source1[] = "word";
    char destination1[s1];
    //swapping %d and %s will cause a SIEGSEGV
    printf("Length of %d is %s\n", source1, string_length(source1));
    printf("Result of string_copy(%s, dest[]) call: ", source1);
    string_copy(source1, destination1, s1);
    printf("\n*********************\n");
    int s2 = 3;
    char source2[] = "word";
    char destination2[s2];
    printf("Length of %s is %d\n", source2, string_length(source2));
    printf("Result of string_copy(%s, dest[]) call: ", source2);
    string_copy(source2, destination2, s2);
    printf("\n*********************\n");
    int s3 = 0;
    char source3[] = "word";
    char destination3[s3];
    printf("Length of %s is %d\n", source3, string_length(source3));
    printf("Result of string_copy(%s, dest[]) call: ", source3);
    string_copy(source3, destination3, s3);
    printf("\n*********************\n");
    int s4 = 0;
    char source4[] = "";
    char destination4[s4];
    printf("Length of %s is %d\n", source4, string_length(source4));
    printf("Result of string_copy(%s, dest[]) call: ", source4);
    string_copy(source4, destination4, s4);
    printf("\n*********************\n");
    int s5 = 1;
    char source5[] = "";
    char destination5[s5];
    printf("Length of %s is %d\n", source5, string_length(source5));
    printf("Result of string_copy(%s, dest[]) call: ", source5);
    string_copy(source5, destination5, s5);
    printf("\n*********************\n");

   return 0;
}