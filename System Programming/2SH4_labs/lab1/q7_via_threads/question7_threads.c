// Header file for input output functions
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <omp.h>

struct thread_worker_data
{
   int	m;
   int  N;
   int offset;  //either 1, 2 ... to N
}thread_worker_data;

struct thread_worker_data **initThreadArray(int m, int N);
void *print_perfect_numbers(struct thread_worker_data *thread_args);
void *hello_world(struct thread_worker_data *thread_args);

//okay this is not easy, I need to think about how I would go about defining print_perfect_numbers(.) function
//and passinng multiple arguments, and figuring out how many arguments to pass
//how to distribute the workload evenly
//eg print_perfect_numbers(33550336) = first quarter are light work, second quarter is slightly heavier work, third quarter is significantly heaving work, last quarter is heavy work

//as I suspected: https://stackoverflow.com/questions/1352749/multiple-arguments-to-function-called-by-pthread-create
//to pass multiple arguments, best practice is to create and pass a struct
//https://hpc-tutorials.llnl.gov/posix/passing_args/
//interesting resource: https://github.com/manasesjesus/pthreads

//summary of this program
//take following parameters for thread_worker_data struct:
//m = max integer to search from 1
//N = number of threads and increment value from offset
//offset = the offset value from 1 to N, which will increment up to N-3, N-2 ... N
//splice the work via neighbouring slices of work and passing to the N thread to compute and print perfect number combinations

//couple combinations tried:
// 1) clear; rm ./q7; gcc question7_threads.c -lm -o q7; ./q7 33550336 $(ulimit -u)
// 2) clear; rm ./q7; gcc question7_threads.c -lm -o q7; ./q7 33550336 $(ulimit -u)/2
// 3) clear; rm ./q7; gcc question7_threads.c -lm -o q7; ./q7 33550336 1
// 4) clear; rm ./q7; gcc question7_threads.c -lm -o q7; ./q7 33550336 1000
// and bunch of entries for m<=8128. It doesn't want to converge or finish running for entries 10^7 in size.
// So conclusion is Pthread is slicing up the resources to hard and with too much overhead to make mathemtical
// computation like this not worthwhile.
// Also doesn't help that my program is O(n^3) essentially. If I remove the pretty printing stuff, I can get it
// down to O(n^2). Let's try doing that and see if that helps. Nope tried that with tempArrays and still taking lots of time.
//Time to give up on this program :) - Was a fun exercise implementing this though!

/* Sample Output for reference:
$ gcc question7_threads.c -lm -o q7; ./q7 49600 10
The following number is a perfect number: 28
With the following factors: 1 2 4 7 14      
********************
The following number is a perfect number: 6
With the following factors: 1 2 3
********************
The following number is a perfect number: 496
With the following factors: 1 2 4 8 16 31 62 124 248
********************
The following number is a perfect number: 8128
With the following factors: 1 2 4 8 16 32 64 127 254 508 1016 2032 4064
********************

*/

// main function -
// where the execution of program begins
int main(int argc, char *argv[])
{   
    struct thread_worker_data **thread_args;   //will have [NTHREADS+2] indexes
    int rc, i;
    int m, N;

    //find all perfect numbers
    if(argc<2){
        printf("Insufficient arg input from user, prompting for value m: ");
        scanf("%d %d", &m, &N);
        pthread_t threads[N];
        
        if(m>1 && m >= N){
            /* spawn the threads */
            thread_args = initThreadArray(m,N);
            
            for (i=0; i<N; i++)
            {
                // printf("main() spawning thread %d\n", i);
                rc = pthread_create(&threads[i], NULL, print_perfect_numbers, (void *) thread_args[i]);
            }

            /* wait for threads to finish */
            for (i=0; i<N; ++i) {
                rc = pthread_join(threads[i], NULL);
            }

            free(thread_args);
        }else{
            printf("m value provided is invalid!\n");
        }
    }else{
        m = strtol(argv[1],NULL,10);    //convert argv[1] from a char pointer to an int
        N = strtol(argv[2],NULL,10);
        pthread_t threads[N];
        //m = atoi(argv[1]);    //don't use this sus approach
        if(m>1 && m >= N){    //optionally:  && m >= 2*N, does not make sense to spawn more threads than the number of possible jobs m
            /* spawn the threads */
            thread_args = initThreadArray(m,N);
            
            for (i=0; i<N; i++)
            {
                // printf("main() spawning thread %d\n", i);
                rc = pthread_create(&threads[i], NULL, print_perfect_numbers, (void *) thread_args[i]);
            }

            /* wait for threads to finish */
            for (i=0; i<N; ++i) {
            rc = pthread_join(threads[i], NULL);
            }

            free(thread_args);
            // print_perfect_numbers(m);
        }else{
            printf("m value provided is invalid!\n");
            printf("m=%d 2*N=%d\n", m, 2*N);
        }
    }

    return 0;
}

void *hello_world(struct thread_worker_data *thread_args){
    printf("Hello World! I have %d %d %d\n", thread_args->m, thread_args->N, thread_args->offset);
}

void *print_perfect_numbers(struct thread_worker_data *thread_args){
    // int tempArray[50];
    // int tempCounter = 0;
    int counter = 0;
    int i=thread_args->offset;
    // printf("********************\n");
    // printf("print_perfect_numbers() instance with following args: %d %d %d\n", thread_args->m, thread_args->N, thread_args->offset);
    // printf("Received argument %d!\n", m);
    // printf("Hardcoded argument %d!\n", my_m_value);

    while(i<=thread_args->m){
        // printf("%d ", i);
        for (int j = 1; j < i; j++){
            if(i % j == 0){
                // tempArray[tempCounter] = j;
                // tempCounter++;
                counter += j;
            }
            if(j==i-1 && counter==i){
                printf("The following number is a perfect number: %d\n",counter);
                printf("With the following factors: ");
                //assuming I'm a newb with no skills in DSA (queues), string processing (large static or dynamic string array, or string concat to temporarily store), or store
                //int factors in a static or dynamic array for printing
                // counter = 0;
                // for (int k = 0; k < tempCounter; k++)
                // {
                //     printf("%d ", tempArray[k]);
                // }
                
                for (int k = 1; k < i; k++)
                {
                    if(i % k == 0){
                        printf("%d ", k);
                    }
                    if(k+1==i){
                        printf("\n");
                    }
                }
                printf("********************\n");
            }
        }
        counter = 0;
        // tempCounter = 0;
        i = i + thread_args->N;
    }
}

struct thread_worker_data **initThreadArray(int m, int N) {
    //this is where the training from 2SH4 lab 3 came in:
    //https://stackoverflow.com/questions/11656532/returning-an-array-using-c

    struct thread_worker_data **thread_worker_list = calloc(N,sizeof(thread_worker_data));

    for (size_t i = 0; i < N; i++)
    {
        struct thread_worker_data *thread_data = calloc(1,sizeof(thread_worker_data));
        thread_data->m = m;
        thread_data->N = N;
        thread_data->offset = i+1;
        thread_worker_list[i] = thread_data;
        // printf("%d %d %d\n", thread_worker_list[i]->m, thread_worker_list[i]->N, thread_worker_list[i]->offset);
    }
    
    return thread_worker_list;
}