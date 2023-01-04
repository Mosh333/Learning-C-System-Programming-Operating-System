// Header file for input output functions
#include <stdio.h>
#include <math.h>

//run like gcc question3.c -lm -o q3; ./q3
//need the -lm flag

// main function -
// where the execution of program begins
int main()
{   
    int n, temp, count;
    int min;
    while(1){
        printf("Please input an integer (0 to end): ");
        scanf("%d", &n);
        if(n!=0){
            if(n<0){
                n=(-1)*n;
            }
            count=(n==0)?1:log10(n)+1;
            if(count==5){
                printf("Your input is a five-digit number: %d\n", n);
            }
        }else if(n==0){
            printf("Thank you for using my software. Bye!\n");
            return 0;
        }
    }

    return 0;
}