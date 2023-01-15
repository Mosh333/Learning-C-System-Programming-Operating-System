#include <stdio.h>
#include <math.h>
#include "string_copy.h"

void string_copy(const char source[], char destination[], int n){
    //copy from source[] to destination[n] up to n-1 chars plus '\n' into
    //destination[n]
    int i;
    if(n<1){
        printf("Please enter an integer greater than 1! A word must at least be one char in size!");
        return;
    }
    if(string_length(source)<1){
        printf("Please ensure source char array size is at least 1! A word must at least be one char in size!");
        return;
    }


    for (i = 0; i < n; i++)
    {
        destination[i] = source[i];
        printf("%c", destination[i]);
    }
    //mark the data as a string
    destination[i+1]='\0';
    printf("%c", destination[i+1]);
    

    return;
}

//what signal SIEGSEGV is:
//https://komodor.com/learn/sigsegv-segmentation-faults-signal-11-exit-code-139/#:~:text=What%20is%20SIGSEGV%20SIGSEGV%2C%20also%20known%20as%20a,used%20by%20Unix-based%20operating%20systems%20%28such%20as%20Linux%29.
int string_length(const char word[]){
    int result=0;
    int i=0;
    while(word[i]!='\0'){
        i++;
    }
    result = i;

    return result;
}