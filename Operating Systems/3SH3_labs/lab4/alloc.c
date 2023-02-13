#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/sem.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// More descriptions about mmap and the memory mapping model
// https://www.youtube.com/watch?v=8hVLcyBkSXY
void resourceAlloc()
{
    // https://www.tutorialspoint.com/what-is-fopen-and-open-in-linux
    // https://stackoverflow.com/questions/1658476/c-fopen-vs-open
    //  int fp = open("res.txt","w+");   //we need FILE* to implement the code

    // initialize variables for later use
    int counter = 0;
    key_t semkey;
    int semId;
    int fd, fd2;
    struct sembuf sbuf;
    struct stat resFileStat;
    void *mmapPtr;
    int requestedResourceType;
    int requestedUnit;
    int temp1, temp2;
    char temp1Buffer[7];
    char temp2Buffer[7];
    char buffer[30]; // one single digit and and a space to store
    char tempBuffer[10], lineBuffer[10];
    char fileBuffer[100];
    // char *token1, *token2;


    //lock the resource using semaphore and perform an mmap to obtain copy of the file
    semkey = ftok("res.txt", 'a');
    if ((semId = semget(semkey, 1, IPC_CREAT | 0666)) == -1)
    {
        fprintf(stderr, "semget() call failed, could not create semaphore!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        //https://www.prodevelopertutorial.com/system-v-semaphores-in-c-using-semget-semctl-semop-system-v-system-calls-in-linux/
        int semctlcode = semctl(semId,0,SETVAL);
        semctlcode = semctl(semId,0,IPC_CREAT);
        struct sembuf sop [1];   //alternatively = {0,-1,0};
        sop[0].sem_num = 0;
        sop[0].sem_op = 1;  //seems to freeze when set at -1
        sop[0].sem_flg = 0;
        int semopcode = semop(semId,sop,1);
        if(semopcode<0){
            fprintf(stderr,"semop() call failed, could not operate on semaphore!\n");
            exit(EXIT_FAILURE);
        }
        // printf("Worked semopcode is %d\n",semopcode);
        // printf("res.txt file locked.\n");
        // printf("Performing file operations!\n");

        // FILE *fp = fopen("res.txt", "r+");
        // fd = fileno(fp);
        // fd2 = fp->_fileno;
        if ((fd = open("res.txt", O_RDWR)) < 0) {
            perror("res.txt");
            exit(1);
        }


        int fstatReturnCode = fstat(fd, &resFileStat);

        if (fstatReturnCode < 0)
        {
            printf("Could not open res.txt\n");
            exit(EXIT_FAILURE);
        }

        mmapPtr = mmap(NULL, resFileStat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
        if (mmapPtr == MAP_FAILED)
        {
            printf("Mapping Failed\n");
            return 1;
        }

        // have a copy of the file now, can close the file now
        close(fd);
        //remove the semaphore lock for it
        semctl(semId, 0, IPC_RMID);
    }



    printf("Mapped res.txt file to address space mmapPtr @ %p!\n", mmapPtr);
    printf("The size of res.txt file is %ld bytes!\n", resFileStat.st_size);
    printf("fd=%d and fd2=%d\n", fd, fd2);

    printf("Contents of mmapPtr is: \n%s", strcpy(buffer, mmapPtr));
    // printf("Contents of mmapPtr is: \n%s", strcpy(newBuffer, mmapPtr));
    
    // int i=0;
    //there must be a newline at the 4th entry of each line
    // while (buffer[i] != '\0')
    // {
    //     printf("The Character at %d Index Position = %c \n", i, buffer[i]);
    //     i++;
    // }

    
    //each iteration appends the correct line worth of updated file data into fileBuffer[]
    while(1){

        printf("Moshiur - Contents of buffer with size of %d is: \n%s", strlen(mmapPtr), mmapPtr);
        strcpy(buffer, mmapPtr);
        printf("Moshiur - Contents of buffer with size of %d is: \n%s", strlen(buffer), buffer);
        printf("Please enter resource type,units for it (eg 2,4):");
        scanf("%d,%d",&requestedResourceType, &requestedUnit);
        printf("The requestedResourceType is %d and requestedUnit is %d\n",requestedResourceType, requestedUnit);
        for (size_t i = 0; i < strlen(buffer)/4; i++)
        {
            printf("buffer item1: %c and item2: %c with length of %d\n", buffer[4*i], buffer[4*i+2], strlen(buffer));
            temp1 = (int)buffer[4*i]-48;
            temp2 = (int)buffer[4*i+2]-48;
            if(temp1==requestedResourceType){
                if(temp2>=requestedUnit){
                    printf("Available for resource allocation!\n");
                    sprintf(temp1Buffer, "%d", requestedResourceType);
                    sprintf(temp2Buffer, "%d", temp2-requestedUnit);
                    strcat(temp1Buffer, " ");
                    strcat(temp1Buffer, temp2Buffer);
                    strcat(temp1Buffer, "\n");
                    strcat(fileBuffer,temp1Buffer);
                }else{
                    printf("Not enough resource available for resource allocation!\n");
                    sprintf(temp1Buffer, "%d", temp1);
                    sprintf(temp2Buffer, "%d", temp2);
                    strcat(temp1Buffer, " ");
                    strcat(temp1Buffer, temp2Buffer);
                    strcat(temp1Buffer, "\n");
                    strcat(fileBuffer,temp1Buffer);
                }
            }else{
                printf("Requested resource type not available!\n");
                //store the line information correctly into fileBuffer[]
                sprintf(temp1Buffer, "%d", temp1);
                sprintf(temp2Buffer, "%d", temp2);
                strcat(temp1Buffer, " ");
                strcat(temp1Buffer, temp2Buffer);
                strcat(temp1Buffer, "\n");
                strcat(fileBuffer,temp1Buffer);
            }
        }
        printf("Final contents of fileBuffer with size of %d is: \n%s", strlen(fileBuffer), fileBuffer);
        memmove(buffer, fileBuffer, sizeof(fileBuffer));    //memcpy seems to append to the end
        
        semkey = ftok("res.txt",'a');
        if( ( semId = semget(semkey, 1, IPC_CREAT | 0666 ) ) == -1 ) {
                fprintf(stderr,"semget() call failed, could not create semaphore!\n");
                exit(EXIT_FAILURE);
        }else{
            //https://www.prodevelopertutorial.com/system-v-semaphores-in-c-using-semget-semctl-semop-system-v-system-calls-in-linux/
            printf("semget call worked!\n");
            printf("Value of semget is: %d\n", semId);
            int semctlcode = semctl(semId,0,SETVAL);
            printf("semctlcode is %d\n",semctlcode);
            semctlcode = semctl(semId,0,IPC_CREAT);
            printf("semctlcode is %d\n",semctlcode);
            struct sembuf sop[1];   //alternatively = {0,-1,0};
            sop[0].sem_num = 0;
            sop[0].sem_op = -1;
            sop[0].sem_flg = 0;
            int semopcode = semop(semId,&sop,1);
            if(semopcode<0){
                fprintf(stderr,"semop() call failed, could not operate on semaphore!\n");
                exit(EXIT_FAILURE);
            }
            printf("Worked semopcode is %d\n",semopcode);
            printf("res.txt file locked.\n");
            printf("Performing msync operation!\n");
            strcpy(mmapPtr,buffer);
            int result = msync(mmapPtr,getpagesize(),MS_SYNC);
            // sleep(10);
            printf("result is: %d\n", result);
            // munmap(mmapPtr,getpagesize());
            //remove the semaphore lock for it
            semctl(semId, 0, IPC_RMID);     
        }


    }




    return;
}

int main(int argc, char *argv[]){

    resourceAlloc();

}