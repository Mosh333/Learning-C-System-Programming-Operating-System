#ifndef STUDENTSTRUCT_H_   /* Include guard */
#define STUDENTSTRUCT_H_

typedef struct student {
    int studentId;
    char firstName[15];
    char lastName[15];
    int gradeProj1;
    int gradeProj2;
    float gradeFinal;
} student;

//this does not make sense btw
// typedef struct studentList {
//     struct studentList[1000];   //able to store 1000 students max
// } studentList;

//you just do this in C: student studentList[n] to define an array of N of student structures!

#endif