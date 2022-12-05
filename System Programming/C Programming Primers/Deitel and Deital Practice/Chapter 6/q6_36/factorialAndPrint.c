#include <stdio.h>


long factorial(long number); //page 181
void printArray(int arrayParam[], int arraySize); //page 265 - recursive print array

int global_a[] = {0, 1, 2, 3, 444, 5, 6, 7, 8};
int global_n = sizeof(global_a)/sizeof(global_a[0]);

//in linux terminals, one must have the script argument +
// all the positional arguments ($#) to have full list of arguments
int main(int argc, char *argv[]){
    int i;
    int ctr;
    if(argc > 1){
        for( ctr=0; ctr < argc; ctr++ ){
            //puts( argv[ctr] );
            printf("%s\n", argv[ctr] );
        }
        printf("Name of executable plus positional argument is: %d arguments\n", argc);
        //Test
        for(i=0; i<=10; i++){
            printf("%2d! = %ld\n", i, factorial(i));
        }
    }else{
        printf("Name of executable plus positional argument is: %d argument\n", argc);
    }
    
    int local_n = global_n;
    printArray(global_a,local_n);

    return 0;
}

long factorial(long number){

    if(number<=1){
        return 1;
    }else{
        return factorial(number-1)*number;
    }
}

//see page 227 for ideas
void printArray(int arrayParam[], int arraySize){
    if(arraySize <= 1){
        printf("%d]\n",arrayParam[global_n-arraySize]);
        return;
    }else if(arraySize==global_n){
        printf("[%d,",arrayParam[global_n-arraySize]);
        printArray(arrayParam, arraySize-1);
    }else{
        printf("%d,",arrayParam[global_n-arraySize]);
        printArray(arrayParam, arraySize-1);
    }
}