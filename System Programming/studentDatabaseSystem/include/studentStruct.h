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

#endif