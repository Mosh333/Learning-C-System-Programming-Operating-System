/*
 * sample_fork.c
 * This program will create 5 fork process to check if pokemon exists
 * in the array. Will print which fork process found the pokemon.
 */
#include <sys/types.h>
#include <sys/wait.h>
#include "errors.h"
volatile int glb = 0;

int main (int argc, char *argv[])
{
    printf("Initializing the pokemon array!\n");

    volatile int status = -1;
    char line[20];
    pid_t pid1, pid2, pid3, pid4, pid5;
    char message[64];
    char ch_arr[5][20] = {
                         "Pikachu\n",
                         "Bulbasur\n",
                         "Squirtle\n",
                         "Charmander\n",
                         "Eevee\n"
                     };

    while(1){
        printf("Please enter a pokemon to search: ");
        if(fgets(line, sizeof(line), stdin)==NULL){
            exit(0);
        }
        if(strlen(line)<=1){
            continue;
        }
        //string scanf
        if(sscanf(line, "%20[A-Z]^[A-Z]\n", message)<1){
            fprintf (stderr, "Bad command\n");
        }else{
            pid1 = fork();
            pid2 = fork();
            pid3 = fork();
            pid4 = fork();
            pid5 = fork();
            if(pid1 == 1 || pid2 == -1 || pid3 == -1 || pid4 == -1 || pid5 == -1){
                errno_abort("Fork");
            }

            if(pid1 == 0){
                //In the child process,
                if(strcmp(ch_arr[0], line)==0){
                    // printf("%d %d %d %d %d %d \n", pid1, pid2, pid3, pid4, pid5);
                    printf("found pokemon in pid1! %s",ch_arr[0]);
                    status = 0;
                }
                sleep(1);
                exit(0);
            }else if(pid2 == 0){
                //In the child process,
                if(strcmp(ch_arr[1], line)==0){
                    // printf("%d %d %d %d %d %d \n", pid1, pid2, pid3, pid4, pid5);
                    printf("found pokemon in pid2! %s",ch_arr[1]);
                    status = 1;
                }
                sleep(1);

                exit(0);
            }else if(pid3 == 0){
                //In the child process,
                if(strcmp(ch_arr[2], line)==0){
                    // printf("%d %d %d %d %d %d \n", pid1, pid2, pid3, pid4, pid5);
                    printf("found pokemon in pid3! %s",ch_arr[2]);
                    status = 2;
                }
                sleep(1);
                exit(0);
            }else if(pid4 == 0){
                //In the child process,
                if(strcmp(ch_arr[3], line)==0){
                    // printf("%d %d %d %d %d %d \n", pid1, pid2, pid3, pid4, pid5);
                    printf("found pokemon in pid4! %s",ch_arr[3]);
                    status = 3;
                }
                sleep(1);
                exit(0);
            }else if(pid5 == 0){
                //In the child process,
                if(strcmp(ch_arr[4], line)==0){
                    // printf("%d %d %d %d %d %d \n", pid1, pid2, pid3, pid4, pid5);
                    printf("found pokemon in pid5! %s",ch_arr[4]);
                    status = 4;
                }
                sleep(1);
                exit(0);
            }else{
                /*
                 * In the parent, call waitpid() to collect any children that
                 * have already terminated.
                 */
                do{
                    pid1 = waitpid(-1, NULL, WNOHANG);
                    pid2 = waitpid(-1, NULL, WNOHANG);
                    pid3 = waitpid(-1, NULL, WNOHANG);
                    pid4 = waitpid(-1, NULL, WNOHANG);
                    pid5 = waitpid(-1, NULL, WNOHANG);
                    //printf("%d %d %d %d %d %d \n", pid1, pid2, pid3, pid4, pid5);
                    if(pid1 == -1||pid2 == -1||pid3 == -1||pid4 == -1||pid5 == -1){
                        errno_abort("Wait for child");
                    }
                    if(status!=-1){
                        printf("Found pokemon in pos (%d)\n", status);
                        return 0;
                    }
                }while((pid1+pid2+pid3+pid4+pid5) != 0);

            }
        }
        //printf("%d", status);
        sleep(5);
    }
    return 0;

}