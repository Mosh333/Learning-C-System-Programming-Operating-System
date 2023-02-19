#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>



int main(void){
    int             childToParentPipe[2], parentToChildPipe[2], nbytes;
    pid_t           childpid;
    char            string[] = "We love 3SH3!\n";
    char            readbuffer[80];
    signed char     tempResult, tempResult2;            //supports -128 to 127, format specifier is %c
    int             totalReceivedSum;
    //cannot store the sum in variable because of the technicality in the requirement
    signed char     parentProcessArray[100] = {0};      //intialize all the entries in the array to 0
    int             parentProcessArrayIndex = 0;        //for tracking parentProcessArray
    
    int pipeReturnCode1 = pipe(childToParentPipe);
    int pipeReturnCode2 = pipe(parentToChildPipe);

    if(pipeReturnCode1 == -1){
        perror("pipe");
    }else{
        printf("Pipe1 system call succeeded!\n");
    }

    if(pipeReturnCode2 == -1){
        perror("pipe");
    }else{
        printf("Pipe2 system call succeeded!\n");
    }

    if((childpid = fork()) == -1){
        perror("fork");
        exit(0);
    }else{
        printf("Fork system call succeeded!\n");
    }

    //not going to rely on any fancy mutual exclusion mechanisms to handle communication between pipes
    //simple sleep() and == -1 to implement feature
    //child process
    if(childpid == 0){
        while(1){
            
            printf("Enter a 1-byte integer, press -1 to terminate: ");
            scanf("%hhd", &tempResult);
            // printf("Child Process: Received signed char value of %d\n", tempResult);
            close(childToParentPipe[0]);
            write(childToParentPipe[1], &tempResult, sizeof(tempResult));
            if(tempResult==-1){
                sleep(2);
                close(parentToChildPipe[1]);
                nbytes = read(parentToChildPipe[0], &totalReceivedSum, sizeof(totalReceivedSum));
                printf("Child Process: Received total sum from parent process: %d\n", totalReceivedSum);
                exit(EXIT_SUCCESS);
            }
            sleep(0.5);
        }
    
    //parent process
    }else{
        while(1){
            close(childToParentPipe[1]);
            nbytes = read(childToParentPipe[0], &tempResult2, sizeof(tempResult2));
            // printf("Parent Process: Received signed char value is: %d\n", tempResult2);
            
            //put data in array if data is not -1
            if(tempResult2==-1 || parentProcessArrayIndex==100){
                int totalSum = 0;
                for (size_t i = 0; i < parentProcessArrayIndex; i++)
                {
                    totalSum += (int)parentProcessArray[i];
                }
                // printf("Sending the value %d\n", totalSum);
                
                close(parentToChildPipe[0]);
                write(parentToChildPipe[1],&totalSum,sizeof(totalSum));
            }else{
                parentProcessArray[parentProcessArrayIndex] = tempResult2;
                parentProcessArrayIndex++;
            }

            
        }
    }
}