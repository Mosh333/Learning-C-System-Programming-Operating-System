#ifndef VECTORLIBRARY_H_   /* Include guard */
#define VECTORLIBRARY_H_


void print_vector(double array[], int size);
void print_vector_bad(double array[], int blah);

void add_vectors(double vector1[], double vector2[], double vector3[], int n);

double scalar_prod(double vector1[], double vector2[], int n);

double norm2(double vector[], int n);


#endif