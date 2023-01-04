// Header file for input output functions
#include <stdio.h>
#include <string.h>
#define my_m_value 1000 //preprocessor directive approach to initialize value

// main function -
// where the execution of program begins
int main(int argc, char *argv[])
{   
    int m;
    //find all perfect numbers
    if(argc<2){
        printf("Insufficient arg input from user, prompting for value m: ");
        scanf("%d", &m);
        if(m>1){
            print_perfect_numbers(m);
        }else{
            printf("m value provided is invalid!\n");
        }
    }else{
        m = strtol(argv[1],NULL,10);    //convert argv[1] from a char pointer to an int
        //m = atoi(argv[1]);    //don't use this sus approach
        if(m>1){
            print_perfect_numbers(m);
        }else{
            printf("m value provided is invalid!\n");
        }
    }

    return 0;
}

void print_perfect_numbers(int m){
    int counter = 0;
    printf("Received argument %d!\n", m);
    printf("Hardcoded argument %d!\n", my_m_value);

    for (int i = 1; i <= m; i++)
    {
        //printf("Searching for factors for integer value = %d\n", i);
        for (int j = 1; j < i; j++)
        {
            // printf("");
            if(i % j == 0){
                // printf("%d ", j);
                counter += j;
            }
            //if on last iteration, check if perfect number and print the factors
            if(j==i-1 && counter==i){
                printf("The following number is a perfect number: %d\n",counter);
                printf("With the following factors: ");
                //assuming I'm a newb with no skills in DSA (queues), string processing (large static or dynamic string array, or string concat to temporarily store), or store
                //int factors in a static or dynamic array for printing
                counter = 0;
                for (int k = 1; k < i; k++)
                {
                    if(i % k == 0){
                        printf("%d ", k);
                    }
                    if(k+1==i){
                        printf("\n");
                    }
                }
            }            
            
        }
        counter = 0;
    }
    printf("\n");
}