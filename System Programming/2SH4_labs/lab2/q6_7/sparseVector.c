#include <stdio.h>
#include <math.h>
#include "sparseVector.h"

//as per https://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c
//unless working with pointers or strings, just pass the length
int countComponents(int source[], int length){
    int counter=0;
    /*  below does not work, see SO link above
    printf("size is: %d\n", sizeof(source)/sizeof(int));
    */
    
    for (size_t i = 0; i < length; i++)
    {
        if(source[i]!=0){
            counter++;
        }
    }
    
    return counter;
}

void efficient(const int source[], int val[], int pos[], int size){
    printf("The original array: ");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", source[i]);
    }
    printf("\n");

    int counter=0;
    for (size_t i = 0; i < size; i++)
    {
        if(source[i]!=0){
            val[counter]=source[i];
            pos[counter]=i;
            printf("Val %d is at position %d\n", val[counter], pos[counter]);
            counter++;
        }
    }

    printf("The val array is: ");
    for (size_t i = 0; i < counter; i++)
    {
        printf("%d ", val[i]);
    }
    printf("\nThe pos array is: ");
    for (size_t i = 0; i < counter; i++)
    {
        printf("%d ", pos[i]);
    }
    printf("\n");
}

void reconstruct(int source[], int m, const int val[], const int pos[], int n){
    for (size_t i = 0; i < n; i++)
    {
        source[i] = 0;
    }

    for (size_t i = 0; i < m; i++)
    {
        source[pos[i]] = val[i];
    }

    printf("Reconstructed array: ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", source[i]);
    }
    printf("\n");
}

void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2){
    //uniquePos will be the size of 
    int uniquePos = 0;
    int searchPos = 0;
    int found = -1;
    if(k1==0 || k2==0){
        printf("Both k1 and k2 must be at least 1!\n");
    //the below branches finds the number of uniquePos
    //find the number of uniquePos in this branch statement
    //way I written below, you set uniquePos to max of (k1,k2) then iterate through the smaller pos[] list to determine the additional
    //number of uniquePos there is in addition to the max(k1,k2)
    //in retrospect, you can just set uniquePos to either or then search then increment and it would work
    }else if(k1>k2){
        int shorterArray = k2;
        int longerArray = k1;
        uniquePos = k1; //gurantee of at least k1 unique entries
        //here from 0 to k2 entries can be unique in addition to k1
        for (size_t i = 0; i < shorterArray; i++)
        {
            searchPos = pos2[i];
            for (size_t j = 0; j < longerArray; j++)
            {
                if(pos1[j]==searchPos){
                    found=1;
                }
            }

            if(found==-1){
                //unique to pos2
                uniquePos++;
            }else{
                //reset flag
                found=-1;
            }
        }
        
    }else if(k1==k2){
        uniquePos = k1; //gurantee of at least k1 unique entries
        //here from 0 to k2 entries can be unique in addition to k1
        for (size_t i = 0; i < k1; i++)
        {
            searchPos = pos1[i];
            for (size_t j = 0; j < k2; j++)
            {
                if(pos2[j]==searchPos){
                    found=1;
                }
            }

            if(found==-1){
                //unique to pos2
                uniquePos++;
            }else{
                //reset flag
                found=-1;
            }
        }
    }else if(k2>k1){
        int shorterArray = k1;
        int longerArray = k2;
        uniquePos = k2; //gurantee of at least k2 unique entries
        //here from 0 to k1 entries can be unique in addition to k2
        for (size_t i = 0; i < shorterArray; i++)
        {
            searchPos = pos1[i];
            for (size_t j = 0; j < longerArray; j++)
            {
                if(pos2[j]==searchPos){
                    found=1;
                }
            }

            if(found==-1){
                //unique to pos2
                uniquePos++;
            }else{
                //reset flag
                found=-1;
            }
        }        
    }
    
    printf("Unique Pos Entries: %d\n", uniquePos);
}