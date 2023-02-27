
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <pthread.h>
#include "concurrentShearsort.h"
#include "arrayStruct.h"

volatile struct arrayStruct  global_2D_array_struct;
pthread_mutex_t     mutexLock;

//if we ever want to make it smarter and make it a dynamic and random array:
//https://www.includehelp.com/c-programs/generate-random-numbers-within-a-range.aspx
struct arrayStruct create2Darray(const char* fileName, int n){
    //https://stackoverflow.com/questions/917783/how-do-i-work-with-dynamic-multi-dimensional-arrays-in-c

    //initialize the variables to be used
    // struct arrayStruct twoD_array_struct;
    int **arrayPtr;
    FILE* filePointer;
    int bufferLength = 255;
    char buffer[bufferLength]; /* not ISO 90 compatible */

    //initialize the struct used to concurrent Shearsort
    // twoD_array_struct.twoD_array = arrayPtr;     //this followed up manipulating arrayPtr only does not work lol :P
    global_2D_array_struct.n = n;
    global_2D_array_struct.currentIter = 0;

    //to call, must pass the -lm flag, otherwise the compiler will optimize and not compile
    //eg rm ./lab3; gcc lab3.c -lm -o lab3; ./lab3
    float tempVal = 2*log2(n)+1;
    global_2D_array_struct.maxIter = (int)tempVal;
    //log2f((float)n); //log2f(n); -lm flag during compile?

    //store the file contents into the 2D array
    global_2D_array_struct.twoD_array = malloc(n*sizeof(*global_2D_array_struct.twoD_array));
    for (size_t i = 0; i < n; i++)
    {
        global_2D_array_struct.twoD_array[i] = malloc(n*sizeof(global_2D_array_struct.twoD_array[0]));
    }

    filePointer = fopen(fileName, "r");
    int coordI = 0;
    int coordJ = 0;


    //https://www.educative.io/answers/splitting-a-string-using-strtok-in-c
    while(fgets(buffer, bufferLength, filePointer)) {
        //remove the last element aka new line
        buffer[strlen(buffer)-1]='\0';
        // printf("length of buffer is %ld and line data is: %s", strlen(buffer), buffer);
        // printf("\n");
        char *stringToken = strtok(buffer, " ");
        while(stringToken!=NULL){
            // printf("%s\n", stringToken);
            global_2D_array_struct.twoD_array[coordI][coordJ] = atoi(stringToken);
            if(coordJ==n-1){
                coordJ = 0;
                coordI++;
            }else{
                coordJ++;
            }

            stringToken = strtok(NULL, " ");
        }


    }

    printf("Final result is:\n");
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            printf("%d ", global_2D_array_struct.twoD_array[i][j]);
        }
        printf("\n");
    }

    fclose(filePointer);

    return global_2D_array_struct;
}

void addByReference(struct arrayStruct *myArrayStruct, int n){
    for (size_t i = 0; i < myArrayStruct->n; i++)
    {
        for (size_t j = 0; j < myArrayStruct->n; j++)
        {
            myArrayStruct->twoD_array[i][j] += n;
        }
    }

    myArrayStruct->currentIter++;
    myArrayStruct->maxIter++;
}


void concurrentShearsort(struct arrayStruct *myArrayStruct){
    //use pThread to perform concurrent Shearsort
    //use semaphore or a condition variable to coordinate the concurrency of the sorting work
    //after sorting, return the array
    
    int                 n = myArrayStruct->n;
    //pthread_mutex_t     mutexLock;    //defined above as global
    pthread_t           sortThreadId[n];

    //create the POSIX semaphore
    if(pthread_mutex_init(&mutexLock, NULL)){
        printf("Mutex init failed!\n");
        return;
    }
    printf("\n Mutex init succeeded!\n");

    for (size_t i = 0; i < n; i++){
        int err = pthread_create(&sortThreadId[i],NULL,&concurrentShearsort_helper,(void*)myArrayStruct);
        if (err != 0){
            printf("\ncan't create thread :[%s]", strerror(err));
        }  
    }

    for (size_t i = 0; i < n; i++)
    {
        pthread_join(sortThreadId[i], NULL);
    }
    //the plus one iteration from the main thread
    finalPhaseSort();

    pthread_mutex_destroy(&mutexLock);

    return;
}

void *concurrentShearsort_helper(void *myArrayStruct){
    //actual sorting takes place here
    //problem to overcome now is how to sort if these instances have all different pieces of memory?
    //looks like the global variable approach is what https://hpc-tutorials.llnl.gov/posix/example_using_mutexes/ does as well :)
    int tempInt;
    pid_t tid = gettid();    
    printf("Sorting from thread %d!\n", tid);

    /*
    Need to do something like (from the guide):
    
    Lock a mutex prior to updating the value in the shared
    structure, and unlock it upon updating.
    
    pthread_mutex_lock (&mutexsum);
    dotstr.sum += mysum;
    pthread_mutex_unlock (&mutexsum);

    pthread_exit((void*) 0);

    */

    pthread_mutex_lock(&mutexLock);
    //critical section
    if(global_2D_array_struct.currentIter%2==0){
        //Row sort phase
        //even phase -> 0, 2, 4...
        for (size_t i = 0; i < global_2D_array_struct.n; i++)
        {
            for (size_t j = 0; j < global_2D_array_struct.n-1; j++)
            {
                for (size_t k = 0; k < global_2D_array_struct.n-j-1; k++)
                {
                    // printf("thread %d A Comparing between %d and %d: i=%d and j=%d\n", tid, global_2D_array_struct.twoD_array[i][j], global_2D_array_struct.twoD_array[i][j+1], i, j);
                    if(i%2==0){
                        // printf("Value of i is: %d\n",i%2);
                        //sort ascending
                        if(global_2D_array_struct.twoD_array[i][k]>global_2D_array_struct.twoD_array[i][k+1]){
                            tempInt=global_2D_array_struct.twoD_array[i][k];
                            global_2D_array_struct.twoD_array[i][k]=global_2D_array_struct.twoD_array[i][k+1];
                            global_2D_array_struct.twoD_array[i][k+1]=tempInt;
                        }
                    }else{
                        // printf("Value of i is: %d\n",i%2);
                        //sort descending
                        if(global_2D_array_struct.twoD_array[i][k]<global_2D_array_struct.twoD_array[i][k+1]){
                            tempInt=global_2D_array_struct.twoD_array[i][k];
                            global_2D_array_struct.twoD_array[i][k]=global_2D_array_struct.twoD_array[i][k+1];
                            global_2D_array_struct.twoD_array[i][k+1]=tempInt;
                        }
                    }
                }
                //printf("%d ", global_2D_array_struct.twoD_array[i][j]);
            }
            // printf("\n");
        }
        // global_2D_array_struct.twoD_array[0][0]+=1;
    }else{
        //Column sort phase
        //odd phase -> 1, 3, 5...
        // global_2D_array_struct.twoD_array[0][0]+=0;
        for (size_t j = 0; j < global_2D_array_struct.n; j++)
        {
            for (size_t i = 0; i < global_2D_array_struct.n-1; i++)
            {
                for (size_t k = 0; k < global_2D_array_struct.n-i-1; k++)
                {
                    // printf("thread %d B Comparing between %d and %d\n", tid, global_2D_array_struct.twoD_array[i][j], global_2D_array_struct.twoD_array[i+1][j]);
                    if(global_2D_array_struct.twoD_array[k][j]>global_2D_array_struct.twoD_array[k+1][j]){
                        tempInt=global_2D_array_struct.twoD_array[k][j];
                        global_2D_array_struct.twoD_array[k][j]=global_2D_array_struct.twoD_array[k+1][j];
                        global_2D_array_struct.twoD_array[k+1][j]=tempInt;
                    }
                }
                
            }
            
        }
    }
    global_2D_array_struct.currentIter++;
    printf("After phase %d:\n", global_2D_array_struct.currentIter);
    for (size_t i = 0; i < global_2D_array_struct.n; i++)
    {
        for (size_t j = 0; j < global_2D_array_struct.n; j++)
        {
            printf("%d ", global_2D_array_struct.twoD_array[i][j]);
        }
        printf("\n");
    }
    pthread_mutex_unlock(&mutexLock);
    pthread_exit((void*) 0);            //return 0; seems to work just fine here
}

void finalPhaseSort(){
    int tempInt;
    pid_t tid = gettid();  
    printf("Final Phase Sorting from thread %d!\n", tid);
    if(global_2D_array_struct.currentIter%2==0){
        //Row sort phase
        //even phase -> 0, 2, 4...
        for (size_t i = 0; i < global_2D_array_struct.n; i++)
        {
            for (size_t j = 0; j < global_2D_array_struct.n-1; j++)
            {
                for (size_t k = 0; k < global_2D_array_struct.n-j-1; k++)
                {
                    // printf("thread %d A Comparing between %d and %d: i=%d and j=%d\n", tid, global_2D_array_struct.twoD_array[i][j], global_2D_array_struct.twoD_array[i][j+1], i, j);
                    if(i%2==0){
                        // printf("Value of i is: %d\n",i%2);
                        //sort ascending
                        if(global_2D_array_struct.twoD_array[i][k]>global_2D_array_struct.twoD_array[i][k+1]){
                            tempInt=global_2D_array_struct.twoD_array[i][k];
                            global_2D_array_struct.twoD_array[i][k]=global_2D_array_struct.twoD_array[i][k+1];
                            global_2D_array_struct.twoD_array[i][k+1]=tempInt;
                        }
                    }else{
                        // printf("Value of i is: %d\n",i%2);
                        //sort descending
                        if(global_2D_array_struct.twoD_array[i][k]<global_2D_array_struct.twoD_array[i][k+1]){
                            tempInt=global_2D_array_struct.twoD_array[i][k];
                            global_2D_array_struct.twoD_array[i][k]=global_2D_array_struct.twoD_array[i][k+1];
                            global_2D_array_struct.twoD_array[i][k+1]=tempInt;
                        }
                    }
                }
                //printf("%d ", global_2D_array_struct.twoD_array[i][j]);
            }
            // printf("\n");
        }
        // global_2D_array_struct.twoD_array[0][0]+=1;
    }else{
        //Column sort phase
        //odd phase -> 1, 3, 5...
        // global_2D_array_struct.twoD_array[0][0]+=0;
        for (size_t j = 0; j < global_2D_array_struct.n; j++)
        {
            for (size_t i = 0; i < global_2D_array_struct.n-1; i++)
            {
                for (size_t k = 0; k < global_2D_array_struct.n-i-1; k++)
                {
                    // printf("thread %d B Comparing between %d and %d\n", tid, global_2D_array_struct.twoD_array[i][j], global_2D_array_struct.twoD_array[i+1][j]);
                    if(global_2D_array_struct.twoD_array[k][j]>global_2D_array_struct.twoD_array[k+1][j]){
                        tempInt=global_2D_array_struct.twoD_array[k][j];
                        global_2D_array_struct.twoD_array[k][j]=global_2D_array_struct.twoD_array[k+1][j];
                        global_2D_array_struct.twoD_array[k+1][j]=tempInt;
                    }
                }
                
            }
            
        }
    }
    global_2D_array_struct.currentIter++;
    printf("After phase %d:\n", global_2D_array_struct.currentIter);
    for (size_t i = 0; i < global_2D_array_struct.n; i++)
    {
        for (size_t j = 0; j < global_2D_array_struct.n; j++)
        {
            printf("%d ", global_2D_array_struct.twoD_array[i][j]);
        }
        printf("\n");
    }
}

void free_2dArrayStruct(struct arrayStruct *myArrayStruct){
    free(myArrayStruct->twoD_array);
}