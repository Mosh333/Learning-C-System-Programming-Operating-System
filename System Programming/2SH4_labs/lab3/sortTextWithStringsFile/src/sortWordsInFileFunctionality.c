#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

char **read_words( const char *input_filename, int *nPtr){
    printf("%d\n", *nPtr);
    

    FILE *fptr;
    char **strListStorage;
    char tempBuff[100];
    int totalBytes = 0;

    printf("Reading from file called: %s\n", input_filename);
    #ifdef _WIN32
        fptr = fopen(input_filename,"r"); //w+ for reading+writing
    #elif __unix__
        fptr = fopen(input_filename,"r"); //w+ for reading+writing
    #elif __APPLE__
        fptr = fopen(input_filename,"r"); //w+ for reading+writing
    #else
        printf("Other OS\n");
    #endif

    if(fptr == NULL){
        printf("Error!");
        exit(1);
    }

    fscanf(fptr,"%d",nPtr);
    int charLengthArray[*nPtr];
    printf("%d\n", *nPtr);
    // for (size_t i = 0; i < *nPtr; i++)
    // {
    //     printf("moshiur has: %d\n", charLengthArray[i]);
    // }
    

    //don't know the total bytes size of all the characters, must iterate line by line and allocate the necessary memory
    // char **strListStorage = malloc(totalBytes)

    //read the bytes sizes per line and store those information
    //tempBuff will store the read word in the line for calculating byte size
    //charLengthArray will store the length of each word per line
    //totalBytes with sum the total number of bytes the strListStorage list will need
    //note  - sizeof() returns number of bytes (for the data like string,int struct etc), 
    //      - strlen() returns length of the string
    for (size_t i = 0; i < *nPtr; i++)
    { 
        fscanf(fptr, "%s", tempBuff);
        charLengthArray[i] = strlen(tempBuff);
        //allocate memory for strlen(word) + '\0' null terminating character
        // see https://stackoverflow.com/questions/15000544/how-to-get-the-string-size-in-bytes
        //printf("%d strlen(%s) = %d, allocating %d bytes\n", (int)i, tempBuff, charLengthArray[i], (charLengthArray[i]+1)*(int)sizeof('a'));
        totalBytes = totalBytes + (charLengthArray[i]+1)*(int)sizeof('a');
    }

    //allocate total list space based on the accumulated 
    //printf("Malloc for **strListStorage requires %d bytes\n", totalBytes);
    strListStorage = malloc(totalBytes);

    //rewind back to the very beginning of the file
    rewind(fptr);

    //scan the first line integer into a variable, can be anything really
    fscanf(fptr, "%d",nPtr);    //or &intVar

    for (size_t i = 0; i < *nPtr; i++)
    {
        fscanf(fptr, "%s", tempBuff);
        //printf("dec29: strlen(%s) = %d\n", tempBuff, (int)strlen(tempBuff));
        //allocate word
        char *word = malloc((charLengthArray[i]+1)*(int)sizeof('a'));
        //copy into allocated memory
        strcpy(word, tempBuff);
        //assign or store into strListStorage
        strListStorage[i] = word;
        //printf("Did it explode? %s\n", strListStorage[i]);
    }   

    fclose(fptr);

    return strListStorage;
}

int mystrcmp(const char * word1, const char * word2){
    //if string is equal
    int result = 0;
    int wordLength1=0, wordLength2=0;
    int asciiValue1=0, asciiValue2=0;
    int minWordLength=0;

    wordLength1 = strlen(word1);
    wordLength2 = strlen(word2);

    if(wordLength1<wordLength2){
        minWordLength=wordLength1;
    }else{
        //equal or less
        minWordLength=wordLength2;
    }

    for (size_t i = 0; i < minWordLength; i++)
    {
        if((int)word1[i]>(int)word2[i]){
            result = 1;
            return result;
        }else if((int)word1[i]<(int)word2[i]){
            result = -1;
            return result;
        }else{
            result = 0;
        }
        printf("%c %c %d %d\n", word1[i], word2[i], (int)word1[i], (int)word2[i]);
    }
    
    if(result==0){
        if(wordLength1<wordLength2){
            result = 1;
        }else if(wordLength1>wordLength2){
            result = -1;
        }else{
            result = 0;
        }
    }

    return result;
}

void sort_words(char **wordList, int size){
    char buff[100];
    int j,k;
    k = 0;
    //use insertion sort

    printf("result of mystrcmp(%s,%s), %d\n", wordList[0], wordList[1], mystrcmp(wordList[0], wordList[1]));
    
    for (size_t i = 0; i < size; i++)
    {
        printf("Initial array in sort_words(): %s\n", wordList[i]);
    }
    printf("Using insertion sort!\n");
    for (int i = 1; i < size; i++)
    {
        //below does not work, see https://stackoverflow.com/questions/37225244/error-assignment-to-expression-with-array-type-error-when-i-assign-a-struct-f
        //buff = wordList[i];
        strcpy(buff,wordList[i]);
        j = i - 1;
        //printf("result of strcmp(buff,wordList[i]): %s vs %s is %d, also %d %d\n",buff,wordList[i],strcmp(buff,wordList[i]),strlen(buff),strlen(wordList[i]));

        while(j>=0){
            //printf("result of strcmp(buff,wordList[i]): %s vs %s is %d, also %d %d\n",buff,wordList[i],strcmp(buff,wordList[i]),strlen(buff),strlen(wordList[i]));
            if(mystrcmp(buff,wordList[j])<0){
                //printf("%d\n",j);
                strcpy(wordList[j+1],wordList[j]);
            }
            else
            {
                break;
            }
            j=j-1;
        }

        strcpy(wordList[j+1],buff);
    }

    for (size_t i = 0; i < size; i++)
    {
        printf("Post insertion sort_words() call: %s\n", wordList[i]);
    }
    
}

void sort2_words(char **wordList, int size){
    char buff[100];
    
    //use bubble sort
    printf("Using bubble sort!\n");
    for (int i = 0; i < size-1; ++i)
    {
        for (int j = 0; j < size-i-1; ++j)
        {
            if(mystrcmp(wordList[j],wordList[j+1])>0){
                //printf("%d\n",j);
                strcpy(buff,wordList[j]);
                strcpy(wordList[j],wordList[j+1]);
                strcpy(wordList[j+1],buff);
            }
        }
        
        //printf("Did it explode in sort2_words()? %s\n", wordList[i]);
    }

    for (size_t i = 0; i < size; i++)
    {
        printf("Post bubble sort2_words() call: %s\n", wordList[i]);
    }
}