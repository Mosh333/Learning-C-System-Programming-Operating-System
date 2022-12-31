#ifndef DATABASEFUNCTIONALITY_H_   /* Include guard */
#define DATABASEFUNCTIONALITY_H_

#include "studentStruct.h"

struct student **create_class_list( char *, int * );

int find(int idNo, student **list, int size);

void input_grades( char *filename, student **list, int size );

void compute_final_course_grades(student **list, int size);

void output_final_course_grades(char *filename, student **list, int size);

void print_list( student **list, int size);

void withdraw(int idNo, student **list, int *sizePtr);

void destroy_list(student **list, int *sizePtr);

void practiceSyntax();

void illustratePointerMechanics();

#endif