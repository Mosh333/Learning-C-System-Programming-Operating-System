// Header file for input output functions
#include <stdio.h>
#include <math.h>
#include <string.h>
#define my_m_value 1000 //preprocessor directive approach to initialize value

// main function -
// where the execution of program begins
int main(int argc, char *argv[])
{   
    char *option;
    int inputInt;
    //find all perfect numbers
    if(argc<2){
        printf("Insufficient arg input from user, prompting for value m: ");
        scanf("%c", &option, &inputInt);
        if(option=='a'){
            print_seven_digits_backward(inputInt);
        }else if(option=='b'){
            print_integer_backward(inputInt);
        }
    }else{
        option = argv[1][0];
        inputInt = atoi(argv[2]);
        //m = atoi(argv[1]);    //don't use this sus approach
        printf("Option %c\n", option);
        if(option=='a'){
            printf("here!\n");
            print_seven_digits_backward(inputInt);
        }else if(option=='b'){
            print_integer_backward(inputInt);
        }
    }

    return 0;
}

void print_seven_digits_backward(int value){
    int sign=1;
    int digits, tempDigit;
    int flipDigits=0;

    digits = value;
    printf("digits is %d.\n", digits);
    if(value<0){
        digits = -1*value;
        sign = -1;
    }

    if(digits<1000000 || digits>9999999){
        printf("Not a 7 digit number, please try again!\n");
    }else{
        for (int i = 0; i < 7; i++)
        {
            tempDigit = digits%10;
            flipDigits = flipDigits*10 + tempDigit;
            digits = digits/10;
        }
        if(sign==-1){
            flipDigits = -1*flipDigits;
        }
    }
    if(sign==1){
        printf("Flip of %d is %d\n", value, flipDigits);
    }else{
        printf("Flip of %d is %d\n", value, flipDigits);
    }
}

void print_integer_backward(int value){
    int sign=1;
    int digits, tempDigit;
    int flipDigits=0;

    digits = value;
    printf("digits is %d.\n", digits);
    if(value<0){
        digits = -1*value;
        sign = -1;
    }


    while(digits!=0){
        tempDigit = digits%10;
        flipDigits = flipDigits*10 + tempDigit;
        digits = digits/10;
    }
    if(sign==-1){
        flipDigits = -1*flipDigits;
    }

    if(sign==1){
        printf("Flip of %d is %d\n", value, flipDigits);
    }else{
        printf("Flip of %d is %d\n", value, flipDigits);
    }
}