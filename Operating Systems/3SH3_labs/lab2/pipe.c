#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// #include <sys/type.h>


int main(void){
    int     fd[2], nbytes;
    pid_t   childpid;
    char    string[] = "We love 3SH3!\n";
    char    readbuffer[80];
    
    int pipeReturnCode = pipe(fd);

    if(pipeReturnCode == -1){
        perror("pipe");
    }else{
        printf("Pipe system call succeeded!\n");
        printf("Content @ fd[0] is %d\n", fd[0]);
        printf("Content @ fd[1] is %d\n", fd[1]);
    }

    if((childpid = fork()) == -1){
        perror("fork");
        exit(0);
    }

    if(childpid == 0){
        printf("Content @ fd[0] is %d\n", fd[0]);
        printf("Content @ fd[1] is %d\n", fd[1]);
        close(fd[0]);
        printf("Content @ fd[0] is %d\n", fd[0]);
        printf("Content @ fd[1] is %d\n", fd[1]);
        write(fd[1], string, (strlen(string+1)));
        printf("Content @ fd[0] is %d\n", fd[0]);
        printf("Content @ fd[1] is %d\n", fd[1]);
        exit(0);
    }else{
        printf("In else branch\n");
        printf("Content @ fd[0] is %d\n", fd[0]);
        printf("Content @ fd[1] is %d\n", fd[1]);
        close(fd[1]);
        printf("Content @ fd[0] is %d\n", fd[0]);
        printf("Content @ fd[1] is %d\n", fd[1]);
        nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
        printf("Content @ fd[0] is %d\n", fd[0]);
        printf("Content @ fd[1] is %d\n", fd[1]);
        printf("Received string: %s\n", readbuffer);
    }
}