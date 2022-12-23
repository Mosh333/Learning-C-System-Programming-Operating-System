#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../include/databaseFunctionality.h"
#include "../include/studentStruct.h"




//to be completedd
void output_final_course_grades(){
    printf("Hello Raina :)!\n");
   student stud1;

    // not allowed cuz memory allocation and stuff
    // stud1.firstName = "moshiur";
    // stud1.lastName = "howlader";

    strcpy(stud1.firstName, "moshiur");
    strcpy(stud1.lastName, "howlader");

    stud1.gradeProj1 = 100;
    stud1.gradeProj2 = 100;
    stud1.gradeFinal = 100.0;

    printf("The student %s %s has the following marks: %d, %d, %f\n", stud1.firstName, stud1.lastName, stud1.gradeProj1, stud1.gradeProj2, stud1.gradeFinal);

}