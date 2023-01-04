// Header file for input output functions
#include <stdio.h>

// main function -
// where the execution of program begins
int main()
{   
    float n;
    int temp, count;
    int min;
    printf("Please input your grade average: ");
    scanf("%f", &n);
    if(n>=(float)90.0 && n<=(float)100.0){
        printf("Your equivalent grade point is 4\n");
    }else if(n>=(float)80.0 && n<=(float)89.99){
        printf("Your equivalent grade point is 3\n");
    }else if(n>=(float)70.0 && n<=(float)79.99){
        printf("Your equivalent grade point is 2\n");
    }else if(n>=(float)60.0 && n<=(float)69.99){
        printf("Your equivalent grade point is 1\n");
    }else if(n>=(float)0.0 && n<=(float)59.99){
        printf("Your equivalent grade point is 0\n");
    }else{
        printf("Invalid input. Please try again.\n");
    }

    return 0;
}