#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "signals.c"

// How to automatically run C/C++ in WSL Linux environment from Windows Visual Studio Code IDE
// https://code.visualstudio.com/docs/cpp/config-wsl

// Notes about Signals in Unix/Linux:
// https://www.tutorialspoint.com/unix/unix-signals-traps.htm

// More details about Event and Signals:
// https://w3.cs.jmu.edu/kirkpams/OpenCSF/Books/csf/html/EventsSignals.html

int main (int argc, char *argv[]){
    int p_id;
    int counter = 0;
    long arg;
    
    if(argc!=2){
        printf("Please enter 1 or 2 to indicate implementation version! Example: 'gcc main.c -o mainExe; ./mainExe 1' \n");
    }else{
        arg = strtol(argv[1],NULL,10);
        if(arg==1){
            //register the signal handler
            register_signal_handler();
        }
        if(arg==2){
            //register the signal handler with alternative implementation
            register_signal_handler2();
        }
    }

    // alarm(3);
    while(1){
        p_id = getpid();
        printf("Process ID: %d\n", p_id);
        raise(SIGALRM);
        if(counter==0){
            printf("******************************************\n");
            counter++;
        }else if(counter==1){
            printf("##########################################\n");
            counter=0;
        }
        sleep(2);
    }
}

/*
Notes:
    - Run code in terminal via: `gcc main.c -o mainExe; ./mainExe 15 16 18`
    - kill -l to list all signals
    - watch -n 2 "ps -aux" to list all current running process
    - watch -n 2 "ps -aux | grep lab1" to obtain PID of the running process
*/