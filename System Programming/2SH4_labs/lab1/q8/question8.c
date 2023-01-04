// Header file for input output functions
#include <stdio.h>
#include <string.h>
#define my_m_value 1000 //preprocessor directive approach to initialize value

// main function -
// where the execution of program begins
int main(int argc, char *argv[])
{   
    char *option;
    //find all perfect numbers
    if(argc<2){
        printf("Insufficient arg input from user, prompting for value m: ");
        scanf("%c", &option);
        if(option=='a'){
            print_seven_digits_backward();
        }else if(option=='b'){
            print_integer_backward();
        }
    }else{
        option = argv[1][0];
        //m = atoi(argv[1]);    //don't use this sus approach
        if(option=='a'){
            print_seven_digits_backward();
        }else if(option=='b'){
            print_integer_backward();
        }
    }

    return 0;
}

void print_seven_digits_backward(){
    printf("print_seven_digits_backward\n");
}

void print_integer_backward(){
    printf("print_integer_backward\n");
}