#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){

    pid_t resultCode = fork();

    if(resultCode==0){
        printf("This is the child process\n");
    }else{
        printf("I am the parent process\n");
    }

    sleep(100);
    printf("Both parent and child reach here.\n");

    return 0;
}