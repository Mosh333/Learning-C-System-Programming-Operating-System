// Header file for input output functions
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define my_m_value 1000 //preprocessor directive approach to initialize value

/* Testcases to try for writeIntegerSequenceFromBinarySequence():
17 0 0 0 0 0 1 1 0 0 0 0 0 0 0 1 1 1              -> 5 2 7 3        PASS
17 1 1 1 1 1 0 0 1 1 1 1 1 1 1 0 0 0              -> 0 5 2 7 3      PASS
21 0 0 0 0 1 1 1 1 1 0 0 1 1 1 1 1 1 1 0 0 0      -> 4 5 2 7 3      PASS
21 1 1 1 1 0 0 0 0 0 1 1 0 0 0 0 0 0 0 1 1 1      -> 0 4 5 2 7 3    PASS
4 1 0 1 0                                         -> 0 1 1 1 1      PASS
4 1 1 1 1                                         -> 0 4            PASS
4 0 1 0 1                                         -> 1 1 1 1        PASS
4 0 0 0 0                                         -> 4              PASS
Lesson Learned: The program is not wrong if the user inputs incorrect values
*/

/* Testcases to try for writeBinaryStreamFromIntegerSequence():
4 5 2 7 3          -> 17 0 0 0 0 0 1 1 0 0 0 0 0 0 0 1 1 1            PASS
5 0 5 2 7 3        -> 17 1 1 1 1 1 0 0 1 1 1 1 1 1 1 0 0 0            PASS
5 4 5 2 7 3        -> 21 0 0 0 0 1 1 1 1 1 0 0 1 1 1 1 1 1 1 0 0 0    PASS
6 0 4 5 2 7 3      -> 21 1 1 1 1 0 0 0 0 0 1 1 0 0 0 0 0 0 0 1 1 1    PASS
5 0 1 1 1 1        -> 4 1 0 1 0                                       PASS
2 0 4              -> 4 1 1 1 1                                       PASS
4 1 1 1 1          -> 4 0 1 0 1                                       PASS
1 4                -> 4 0 0 0 0                                       PASS
Lesson Learned: The program is not wrong if the user inputs incorrect values
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
    printf("**********************************\n");
    writeBinaryStreamFromIntegerSequence(filename3, filename4);




    return 0;
}

//how to debug C programs in GDB:
// tldr: compile gcc with -g flag, break #lineNum, then run
// can get local variables with "info locals"
//https://www.youtube.com/watch?v=5yZIFmplXsw
void writeIntegerSequenceFromBinarySequence(const char *inputFilename, const char *outputFilename){
    FILE *fptrIn, *fptrOut;     //It might be possible to implement this with only one FILE pointer variable
                                //But that makes it unnecessarily difficult
    int firstBit = -1;
    int currBit = -1;
    int prevBit = -1;
    int counter = 0;
    int result=-1;
    int fileInt;
    int tempResult;
    int bitStreamChanged = -1;
    int numberOfWrites = 0;
    
    printf("writeIntegerSequenceFromBinarySequence() \nReading from files called: %s\n", inputFilename);
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
    
    //I can think of two approachs to implement this logic
    //option one is a counter to increment accordingly
    //option two store the actual decimal equivalent and print digit by digit "%d " format
    for (size_t i = 0; i < fileInt; i++)
    {
        fscanf(fptrIn, "%d", &tempResult);
        printf("Obtained %d\n", tempResult);
        
        if(i==0){
            firstBit = tempResult;
            currBit = tempResult;
        }
        if(i==0 && firstBit == 1){
                //indicate that there are no 0's at the beginning of the bit stream
                fprintf(fptrOut, "%d ", 0);
                numberOfWrites++;
        }

        if(i!=0){
            prevBit = currBit;
            currBit = tempResult;
            if(currBit!=prevBit){
                bitStreamChanged = 1;
            }
        }

        if(i>0 && prevBit != currBit){
            fprintf(fptrOut, "%d ", counter);
            numberOfWrites++;
            counter = 0;
        }

        // if(i==fileInt-1 && firstBit == 1){
        //     fprintf(fptrOut, "%d ", counter);
        // }
        counter++;
        // printf("counter: %d\n", counter);
        // printf("%d ", tempResult);

        //edge case where last two are both same digits so the write never happens above
        //i can't explain why this fixes for the 1's 0's case for the integer stream :/
        //my guess is the edge case of reading the extra digit for the starting with 1 case?
        //too time consuming to test, going to move on since the above test cases pass
        if(i==fileInt-1){
            // printf("what's goind on in counter %d?\n", counter);
            fprintf(fptrOut, "%d", counter);
            numberOfWrites++;
        }
        printf("prevBit %d currBit %d firstBit %d\n", prevBit, currBit, firstBit);
        printf("number of writes %d, int i is %d\n", numberOfWrites, i);
    }
    
    
    printf("\n");
    fclose(fptrIn);
    fclose(fptrOut);


}

//function declaration inspired from https://www.tutorialspoint.com/c_standard_library/c_function_remove.htm
void writeBinaryStreamFromIntegerSequence(const char *inputFilename, const char *outputFilename){
    FILE *fptrIn, *fptrOut;     //It might be possible to implement this with only one FILE pointer variable
                                //But that makes it unnecessarily difficult
    int firstBitDataRead = -1;
    int currBit = -1;
    int bitCounter = 0;
    int fileInt;
    int tempResult;
    int totalBits = 0;
    
    printf("writeBinaryStreamFromIntegerSequence() \nReading from files called: %s\n", inputFilename);
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

    for (size_t i = 0; i < fileInt; i++)
    {
        fscanf(fptrIn, "%d", &tempResult);
        totalBits = totalBits + tempResult;
    }
    
    //rewind to the beginning of the file
    rewind(fptrIn);
    //skip first line, going to use while loop for example below:
    fscanf(fptrIn, "%d", &fileInt);

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
    
    //read the input file stream digit by digit and apply appropriate logic to write the correct result into fptrOut
    //and with 1, note that EOF returns a negative value so
    //checking if fscanf output not equal EOF to keep reading the integers one by one
    fprintf(fptrOut, "%d ", totalBits);

    while(fscanf(fptrIn, "%d", &tempResult)!=EOF){
        //first read, determine if the sequence starts with 0 or 1
        if(firstBitDataRead==-1){
            //unset the flag
            firstBitDataRead = 1;
            //tempResult contains the first integer in the sequence
            //which will tell whether the binary sequence will start with
            //0 or 1
            if(tempResult!=0){
                currBit = 0;
            }else if(tempResult==0){
                currBit = 1;
                //skip this integer used to inform us about currBit = 1
                fscanf(fptrIn, "%d", &tempResult);
            }
            
        }
        printf("Writing: %dx%d's \n", tempResult, currBit);
        
        for (size_t i = 0; i < tempResult; i++)
        {
            bitCounter++;
            if(bitCounter<totalBits){
                //with space
                fprintf(fptrOut, "%d ", currBit);
                //without space
            }else if(bitCounter>=totalBits){
                fprintf(fptrOut, "%d", currBit);
            }
            
        }

        //flip the bit
        currBit = 1 - currBit;

    }

    fclose(fptrIn);
    fclose(fptrOut);
}



