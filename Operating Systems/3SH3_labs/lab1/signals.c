#include <string.h>
#include "signal.h"



void sig_handler(int signum){
    if(signum == SIGALRM){
        printf("Alarm! Value of SIGALRM is %d\n", SIGALRM);
    }
    if(signum == SIGINT){
        printf("\nCTRL+C pressed! Value of SIGINT is %d\n", SIGINT);
    }
    if(signum == SIGTSTP){
        printf("\nCTRL+Z pressed! Value of SIGTSTP is %d\n", SIGTSTP);
        exit(1);
    }
}

void register_signal_handler(){
    if(signal(SIGALRM,sig_handler) == SIG_ERR){
        printf("failed to register alarm handler for SIGALRM.");
        exit(1);
    }
    if(signal(SIGINT,sig_handler) == SIG_ERR){
        printf("failed to register alarm handler for SIGINT.");
        exit(1);
    }
    if(signal(SIGTSTP,sig_handler) == SIG_ERR){
        printf("failed to register alarm handler for SIGTSTP.");
        exit(1);
    }
}

void register_signal_handler2(){
    //create a sigaction structure, and link it to the handler
    struct sigaction mySigAction;
    memset(&mySigAction, 0, sizeof(mySigAction));
    mySigAction.sa_handler = sig_handler;

    if(signal(SIGALRM,sig_handler) == SIG_ERR){
        printf("failed to register alarm handler for SIGALRM.");
        exit(1);
    }
    if(signal(SIGINT,sig_handler) == SIG_ERR){
        printf("failed to register alarm handler for SIGINT.");
        exit(1);
    }
    if(signal(SIGTSTP,sig_handler) == SIG_ERR){
        printf("failed to register alarm handler for SIGTSTP.");
        exit(1);
    }
}