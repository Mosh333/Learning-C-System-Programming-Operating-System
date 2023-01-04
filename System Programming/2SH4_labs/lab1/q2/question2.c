// Header file for input output functions
#include <stdio.h>

// main function -
// where the execution of program begins
int main()
{   
    int n, temp;
    int min;
    while(1){
        printf("Enter a positive integer n: ");
        scanf("%d", &n);
        if(n>0){
            for (size_t i = 0; i < n; i++)
            {
                printf("Enter the %dth integer: ", i+1);
                scanf("%d", &temp);
                if(i==0){
                    min=temp;
                }else{
                    if(temp<min){
                        min=temp;
                    }
                }
            }
            printf("Minimum value entered is: %d\n", min);            
            break;
        }
    }

    return 0;
}


// // C program for the above approach
// #include <stdio.h>
// int getIntegerOnly();
 
// // Driver Code
// int main()
// {
//     int x = 0;
//     while(1){
//         x = getIntegerOnly();
//         printf("\nvalue entered is: %d", x);
//     }

// }
 
// // Function to check if the user
// // entered value is integer or not
 
// int getIntegerOnly()
// {
//     int num = 0, ch;
//     printf("Enter the input: ");
//     do {
//         ch = getchar();
         
//         // Checks the ASCII code of '
//         // digits 0 to 9
//         if (ch >= 48 && ch <= 57) {
//             printf("%c", ch);
 
//             // To make a digit
//             num = num * 10 + (ch - 48);
//         }
 
//         // 13 is carriage return it breaks
//         // and return the input
//         if (ch == '\n')
//             break;
//     } while (1);
 
//     return (num);
// }