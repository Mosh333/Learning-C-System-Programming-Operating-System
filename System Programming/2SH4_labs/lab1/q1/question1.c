// Header file for input output functions
#include <stdio.h>

// main function -
// where the execution of program begins
int main()
{
    int sum1=0, sum2=0, sum3=0;
    int i=0, j=30, k=30;
    for (i = 30; i < 1001; i++)
    {
        if(i%4==0){
            // printf("val: %d\n", i);
            sum1=sum1+i;
        }
    }
    printf("sum1=%d\n",sum1);

    while (j<1001)
    {
        if(j%4==0){
            // printf("val: %d\n", j);
            sum2=sum2+j;
        }
        j++;
    }
    printf("sum2=%d\n",sum2);

    do
    {
        if(k%4==0){
            // printf("val: %d\n", k);
            sum3=sum3+k;
        }
        k++;   
    } while (k<1001);
    printf("sum3=%d\n",sum3);

    return 0;
}