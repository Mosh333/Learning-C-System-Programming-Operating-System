/*
 * alarm_fork.c
 *
 * This version of alarm.c uses pthread_create to create a
 * separate thread to wait for each alarm to expire.
 */
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include "errors.h"

typedef struct alarm_tag {
    int         seconds;
    char        message[64];
} alarm_t;

void *alarm_thread (void *arg)
{
    alarm_t *alarm = (alarm_t*)arg;
    int status;

    status = pthread_detach (pthread_self ());
    if (status != 0)
        err_abort (status, "Detach thread");
    sleep (alarm->seconds);
    printf ("(%d) %s\n", alarm->seconds, alarm->message);
    free (alarm);
    return NULL;
}

void *randomInt_thread(void *arg){
    //pthread_detach (pthread_self ());
    printf("RandomVal supplied to new thread wasss: %d \n", *(int*)arg);
    // *(int*)arg = rand();
    // int status;

    // status = pthread_detach (pthread_self ());
    return NULL;
}

int main (int argc, char *argv[])
{
    int status;
    char line[128];
    alarm_t *alarm;
    srand(time(NULL));   // Initialization, should only be called once.
    int *randomVal;
    int *newRandom; newRandom = (int*)malloc(sizeof(int)); *newRandom = -1;
    pthread_t thread;
    pthread_t moshiurThread;

    while (1) {
        printf ("Alarm> ");
        if (fgets (line, sizeof (line), stdin) == NULL) exit (0);
        if (strlen (line) <= 1) continue;
        alarm = (alarm_t*)malloc (sizeof (alarm_t));
        if (alarm == NULL)
            errno_abort ("Allocate alarm");

        /*
         * Parse input line into seconds (%d) and a message
         * (%64[^\n]), consisting of up to 64 characters
         * separated from the seconds by whitespace.
         */
        if (sscanf (line, "%d %64[^\n]", 
            &alarm->seconds, alarm->message) < 2) {
            fprintf (stderr, "Bad command\n");
            free (alarm);
        } else if(alarm->seconds < 4){
            fprintf (stderr, "Must be greater than 3 second!\n");
            free (alarm);            
        }else {
            randomVal = (int*)malloc(sizeof(int)); //bus error 10 unless allocate memory
            *randomVal = rand();
            printf("Current Random Value in Main thread: %d\n", *randomVal);            
            status = pthread_create (
                &thread, NULL, alarm_thread, alarm);

            *newRandom =  pthread_create (
                &moshiurThread, NULL, randomInt_thread, randomVal);
            
            // printf("randomVal is: %d\n", *randomVal);
            // printf("newRandom is: %d\n", *newRandom);

            if (status != 0)
                err_abort (status, "Create alarm thread");
        }
        sleep(3);
    }
}
