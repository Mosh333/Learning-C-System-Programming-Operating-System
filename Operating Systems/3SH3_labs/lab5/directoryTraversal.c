#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include "fileAttributes.c"

extern int errno;

void printDirectoryTraversal(const char* startingDirectoryPath){
    //this function needs to print the directory contents like ls -lRa
    // interesting discussion on the best way to recursively iterate/walk filesystem directory in Linux:
    // https://stackoverflow.com/a/29402705
    printf("Provided directoryPath is: %s\n", startingDirectoryPath);

    /*
        - opendir() : returns a null or a pointer address depending on the directory exists
        - readdir() : returns a null or a pointer address 
        - closedir() : closedir() function closes the directory stream associated with dirPointer
        - chdir() : changes the current working directory
        - getcwd() : returns current working directory from where the program is called
        - rewinddir() : resets the position of the directory stream
    */
    DIR *currDir;
    struct dirent *readDir;
    struct stat path_stat;
    char tempAbsPath[512];
    int errnum;
    int closedirReturn;

    currDir = opendir(startingDirectoryPath);
    

    if(currDir){
        //currDir!=NULL
        //printf("Directory exist!\n");

        //base case hit when readDir == NULL; reached the very end of a branch of the directory tree
        while ((readDir=readdir(currDir))!=NULL)
        {
            //additional error handling required if approach was via chdir() + getcwd() + rewinddir()
            if(strcmp(readDir->d_name,".")!=0 && strcmp(readDir->d_name,"..")!=0){
                strcat(tempAbsPath,startingDirectoryPath);
                if(tempAbsPath[strlen(tempAbsPath)-1]!='/'){
                    //do a char compare, not a strcmp()
                    //add a slash if the path is missing one at the end
                    strcat(tempAbsPath,"/");
                }
                
                strcat(tempAbsPath,readDir->d_name);
                stat(tempAbsPath, &path_stat);
                if(S_ISDIR(path_stat.st_mode)==1){
                    // printf("The path %s is a directory!\n", tempAbsPath);
                    printFileAttributes(tempAbsPath);
                    printDirectoryTraversal(tempAbsPath);
                }else if(S_ISDIR(path_stat.st_mode)==0){
                    // printf("The path %s is not a directory!\n", tempAbsPath);
                    printFileAttributes(tempAbsPath);
                }else{
                    perror("S_ISDIR() called failed for some reason.\n");
                }
            }

            memset(tempAbsPath, '\0', sizeof(tempAbsPath));
        }
        if(closedirReturn=closedir(currDir)!=0){
            //EBADF error
            errnum = errno;
            fprintf(stderr, "Value of errno: %d\n", errno);
            perror("Error printed by perror");
            fprintf(stderr, "Error closing directory: %s\n", strerror( errnum ));        
        }
    }else{
        
        //currDir==NULL
        errnum = errno;
        fprintf(stderr, "Value of errno: %d\n", errno);
        perror("Error printed by perror");
        fprintf(stderr, "Directory does not exist or inaccessible directory: %s\n", strerror( errnum ));
        closedir(currDir);
        return;
    }
    

}