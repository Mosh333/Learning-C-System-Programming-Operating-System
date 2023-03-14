// Header file for input output functions
#include <stdio.h>

// main function -
// where the execution of program begins
int main()
{   
    int n;
    float numerator = 4.0;
    float denominator = 1.0;
    float accumulator = 0;
    float sign = -1;
    int temp, count;
    int min;
    printf("Please input the iteration count to compute π (Pi): ");
    scanf("%d", &n);
    if(n>=1){
        for (size_t i = 0; i < n; i++)
        {
            sign = -1*sign;     //flip the sign
            
            accumulator = accumulator + sign*(numerator/denominator);
            denominator = denominator + 2;
        }
        printf("The value of π (Pi) after %d iteration is: %f\n", n, accumulator);
    }else{
        printf("Please input the correct integer count >= 1\n");
    }

    return 0;
}