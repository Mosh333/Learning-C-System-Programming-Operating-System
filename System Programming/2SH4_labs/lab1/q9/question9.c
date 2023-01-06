// Header file for input output functions
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define my_m_value 1000 //preprocessor directive approach to initialize value

/* Testcases to try:
17 0 0 0 0 0 1 1 0 0 0 0 0 0 0 1 1 1              -> 5 2 7 3
17 1 1 1 1 1 0 0 0 0 1 1 1 0 0                    -> 0 5 2 7 3
21 0 0 0 0 1 1 1 1 1 0 0 1 1 1 1 1 1 1 0 0 0      -> 4 5 2 7 3
21 1 1 1 1 0 0 0 0 0 1 1 0 0 0 0 0 0 0 1 1 1      -> 0 4 5 2 7 33
*/

// main function -
// where the execution of program begins
int main(int argc, char *argv[])
{   
    char filename1[] = "./inputFile1.txt";
    char filename2[] = "./outputFile1.txt";
    char filename3[] = "./inputFile2.txt";
    char filename4[] = "./outputFile2.txt";
    
    writeIntegerSequenceFromBinarySequence(filename1, filename2);
    writeBinaryStreamFromIntegerSequence(filename3, filename4);




    return 0;
}

void writeIntegerSequenceFromBinarySequence(const char *inputFilename, const char *outputFilename){
    FILE *fptrIn, *fptrOut;     //It might be possible to implement this with only one FILE pointer variable
                                //But that makes it unnecessarily difficult
    int currBit = -1;
    int result=-1;
    int fileInt;
    
    printf("writeIntegerSequenceFromBinarySequence() \n Reading from files called: %s\n", inputFilename);
    #ifdef _WIN32
        fptrIn = fopen(inputFilename,"r"); //w+ for reading+writing
    #elif __unix__
        fptrIn = fopen(inputFilename,"r"); //w+ for reading+writing
    #else
        printf("Other OS\n");
    #endif

    if(fptrIn == NULL){
        printf("Error!");
        exit(1);
    }

    printf("Contents of the file are: \n");
    fscanf(fptrIn, "%d", &fileInt);
    printf("Number of binary digits in the input file: %d\n", fileInt);
    printf("Deleting and rewriting into files: %s\n", outputFilename);
    remove(outputFilename);

    //To visually verify that the file is removed
    sleep(1);

    printf("Rewriting into files: %s\n", outputFilename);
    #ifdef _WIN32
        fptrOut = fopen(outputFilename,"w"); //w+ for reading+writing
    #elif __unix__
        fptrOut = fopen(outputFilename,"w"); //w+ for reading+writing
    #else
        printf("Other OS\n");
    #endif

    if(fptrOut == NULL){
        printf("Error!");
        exit(1);
    }
    
    fprintf(fptrOut, "%d", result);

    fclose(fptrIn);
    fclose(fptrOut);


}

//function declaration inspired from https://www.tutorialspoint.com/c_standard_library/c_function_remove.htm
void writeBinaryStreamFromIntegerSequence(const char *inputFilename, const char *outputFilename){
    FILE *fptrIn, *fptrOut;     //It might be possible to implement this with only one FILE pointer variable
                                //But that makes it unnecessarily difficult
    int currBit = -1;
    int result=-1;
    int fileInt;
    
    printf("writeBinaryStreamFromIntegerSequence() \n Reading from files called: %s\n", inputFilename);
    #ifdef _WIN32
        fptrIn = fopen(inputFilename,"r"); //w+ for reading+writing
    #elif __unix__
        fptrIn = fopen(inputFilename,"r"); //w+ for reading+writing
    #else
        printf("Other OS\n");
    #endif

    if(fptrIn == NULL){
        printf("Error!");
        exit(1);
    }

    printf("Contents of the file are: \n");

    printf("Deleting and rewriting into files: %s\n", outputFilename);
    remove(outputFilename);

    //To visually verify that the file is removed
    sleep(1);

    printf("Rewriting into files: %s\n", outputFilename);
    #ifdef _WIN32
        fptrOut = fopen(outputFilename,"w"); //w+ for reading+writing
    #elif __unix__
        fptrOut = fopen(outputFilename,"w"); //w+ for reading+writing
    #else
        printf("Other OS\n");
    #endif

    if(fptrOut == NULL){
        printf("Error!");
        exit(1);
    }
    
    /* read the input file stream digit by digit and apply appropriate logic to write the correct result into fptrOut
    while(condition to read){
        fscanf(fptrIn, "%d", &fileInt);
        printf("Number of binary digits in the input file: %d\n", fileInt);
        //some logic...
        fprintf(fptrOut, "%d", result);
    }*/

    fprintf(fptrOut, "%d", result);

    fclose(fptrIn);
    fclose(fptrOut);
}



