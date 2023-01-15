#include <stdio.h>
#include <math.h>
#include "vectorLibrary.h"

void print_vector(double array[], int size){
    for (size_t i = 0; i < size; i++)
    {
        if(i==0){
            printf("[");
        }
        if(i<size-1){
            printf("%.2f, ", array[i]);
        }
        
        if(i==size-1){
            printf("%.2f", array[i]);
            printf("]\n");
        }
    }
    
}

void print_vector_bad(double array[], int blah){
    int size = sizeof(array)/sizeof(double);
    printf("Blah is: %d | size is %d");
    for (size_t i = 0; i < size; i++)
    {
        if(i==0){
            printf("[");
        }
        if(i<size-1){
            printf("%.2f, ", array[i]);
        }
        
        if(i==size-1){
            printf("%.2f", array[i]);
            printf("]\n");
        }
    }
    
}

void add_vectors(double vector1[], double vector2[], double vector3[], int n){
    for (size_t i = 0; i < n; i++)
    {
        vector3[i] = vector1[i] + vector2[i];
    }
}

double scalar_prod(double vector1[], double vector2[], int n){
    double result = 0.0;
    for (size_t i = 0; i < n; i++)
    {
        result = result + vector1[i]*vector2[i];
    }
    
    return result;
}

double norm2(double vector[], int n){
    int result=0.0;
    for (size_t i = 0; i < n; i++)
    {
        result = result + vector[i]*vector[i];
    }
    
    //no error checking required since the number is guranteed to be >=0
    result = sqrt(result);
    
    return result;
}


