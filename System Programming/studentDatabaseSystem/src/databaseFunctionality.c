#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "../include/databaseFunctionality.h"
#include "../include/studentStruct.h"


//debugging segmentation fault with GDB: https://www.rose-hulman.edu/class/csse/csse132/1819a/debugging-segfaults.html
struct student **create_class_list(char *filename, int *sizePtr){
    //google "C double pointer to struct"
    //helpful readme: https://www.tek-tips.com/viewthread.cfm?qid=735393
    //https://stackoverflow.com/questions/4470950/why-cant-we-use-double-pointer-to-represent-two-dimensional-arrays
    //https://cboard.cprogramming.com/c-programming/179285-returning-double-pointer-help.html
    
    printf("%d\n", *sizePtr);
    srand(time(NULL));    

    FILE *fptr;
    printf("Reading from file called: %s\n", filename);
    #ifdef _WIN32
        fptr = fopen(filename,"r"); //w+ for reading+writing
    #elif __unix__
        fptr = fopen(filename,"r"); //w+ for reading+writing
    #else
        printf("Other OS\n");
    #endif

    if(fptr == NULL){
        printf("Error!");
        exit(1);
    }
    
    printf("Contents of the file are: \n");
    fscanf(fptr,"%d",sizePtr);     //or &sizePtr
    printf("Number of students are: %d\n", *sizePtr);   //and sizePtr

    student **studentList = (struct student**)calloc(*sizePtr,sizeof(student));
    for (int i = 0; i < *sizePtr; i++)
    {
    //     //must allocate and initialize for each student to be stored in **studentList
        student *oneStudent = (struct student*)calloc(1,sizeof(student));

        //alternative approach to define dynamically at run time:
        // oneStudent->studentId = rand() % 10000 + 1;
        // printf("%d ", oneStudent->studentId);
        // strcpy(oneStudent->firstName, "moshiur");
        // strcpy(oneStudent->lastName, "howlader");

        //copy paste from file
        fscanf(fptr,"%i %s %s", &oneStudent->studentId, oneStudent->firstName, oneStudent->lastName);
        //map the oneStudent to be in the memory location of studentList at ith index byte offset hence storage oneStudent at the given location
        studentList[i] = oneStudent;

        printf("%p, %p, %d, %s, %s\n", &(studentList[i]), &oneStudent, studentList[i]->studentId, studentList[i]->firstName, studentList[i]->lastName);

    }

    fclose(fptr);     //doing free(fptr); works sometimes, other times a segmentation fault

    return studentList;
}

int find(int idNo, student **list, int size){
    int foundIndex = -1;

    for (size_t i = 0; i < size; i++)
    {
        if(list[i]->studentId == idNo){
            foundIndex = i;
            break;
        }
    }
    
    return foundIndex;
}

void input_grades( char *filename, student **list, int size){
    //input grades data from *filename into **list
    FILE *fptr;
    int searchResult;
    int idNo[size];
    int projGrade1[size];
    int projGrade2[size];
    // int gradeData[size][3];     //size number of rows and 3 columns for idNo, projGrade1, and projGrade2
    printf("Reading from file called: %s\n", filename);
    #ifdef _WIN32
        fptr = fopen(filename,"r"); //w+ for reading+writing
    #elif __unix__
        fptr = fopen(filename,"r"); //w+ for reading+writing
    #else
        printf("Other OS\n");
    #endif

    //iterate each entry in the grades filename
    for (int i = 0; i < size; i++)
    {
        fscanf(fptr,"%d %d %d", &idNo[i], &projGrade1[i], &projGrade2[i]);
        printf("loaded up data: %d, %d, %d\n", idNo[i], projGrade1[i], projGrade2[i]);
        
        searchResult = find(idNo[i], list, size);
        if(searchResult != -1){
            list[searchResult]->gradeProj1 = projGrade1[i];
            list[searchResult]->gradeProj2 = projGrade2[i];
            printf("Grades: %d %d\n", list[searchResult]->gradeProj1, list[searchResult]->gradeProj2);
        }
    }
    
}

void compute_final_course_grades(student **list, int size){
    //calloc() should have at least initialized the fields with 0
    //so the function should still compute even if the input_grades() hasn't been called
    //error checking and exception handling can be made but skipping this

    for (size_t i = 0; i < size; i++)
    {
        list[i]->gradeFinal = (float)(list[i]->gradeProj1 + list[i]->gradeProj2)/2.0;
    }
    
}

void output_final_course_grades(char *filename, student **list, int size){
    //output a new file called *filename with the student ID and the corresponding final grade
    //assumes the list already has the data for the final grades populated
    FILE *fptr;

    // int gradeData[size][3];     //size number of rows and 3 columns for idNo, projGrade1, and projGrade2
    printf("Writing student ID and final grade to a file called: %s\n", filename);
    #ifdef _WIN32
        fptr = fopen(filename,"w"); //w+ for reading+writing
    #elif __unix__
        fptr = fopen(filename,"w"); //w+ for reading+writing
    #else
        printf("Other OS\n");
    #endif
    
    fprintf(fptr,"%d\n",size);

    for (size_t i = 0; i < size; i++)
    {
        if(i==size-1){
            fprintf(fptr,"%d %f", list[i]->studentId, list[i]->gradeFinal);
        }else{
            fprintf(fptr,"%d %f\n", list[i]->studentId, list[i]->gradeFinal);
        }
    }

    fclose(fptr);

}

void print_list( student **list, int size){
    for (size_t i = 0; i < size; i++)
    {
        printf("ID: %d, name: %s %s, project 1 grade: %d, project 2 grade: %d, final grade: %.2f\n", list[i]->studentId, list[i]->firstName, list[i]->lastName, list[i]->gradeProj1, list[i]->gradeProj2, list[i]->gradeFinal);
    }
}

void withdraw(int idNo, student **list, int *sizePtr){
    //https://stackoverflow.com/questions/33170802/c-does-freeing-an-array-of-pointers-also-free-what-theyre-pointing-to
    int searchResult = -1;
        
    searchResult = find(idNo, list, *sizePtr);
    if(searchResult != -1){
        //remove and deallocate the student from the list
        
        printf("------------------------------------------------------\n");
        printf("Removing student ID = %d\n", idNo);
        free(list[searchResult]);

        for (size_t i = searchResult; i < *sizePtr-1; i++)
        {
            list[i] = list[i+1];
        }
        
        //pointer xD: https://stackoverflow.com/questions/8208021/how-to-increment-a-pointer-address-and-pointers-value
        (*sizePtr)--;

        for (size_t i = 0; i < *sizePtr; i++)
        {
            printf("%d %d %d %d %s %s %f\n", list[i]->studentId, list[i]->gradeProj1, list[i]->gradeProj2, list[i]->studentId, list[i]->firstName, list[i]->lastName, list[i]->gradeFinal);
        }




        printf("size is: %d\n", *sizePtr);
        
    }else{
        printf("The student with ID=%d does not exist in the list.\n", idNo);
    }

}


//to be completedd
void practiceSyntax(){
    printf("Hello World :)!\n");
    student stud1;
    student studentList[100];

    // not allowed cuz memory allocation and stuff
    // stud1.firstName = "moshiur";
    // stud1.lastName = "howlader";

    //strcpy is implemented with memcpy apparently
    //https://codebrowser.dev/glibc/glibc/string/strcpy.c.html
    //https://opensource.apple.com/source/xnu/xnu-2050.9.2/libsyscall/wrappers/memcpy.c.auto.html
    strcpy(stud1.firstName, "moshiur");
    strcpy(stud1.lastName, "howlader");

    stud1.gradeProj1 = 100;
    stud1.gradeProj2 = 100;
    stud1.gradeFinal = 100.0;

    strcpy(studentList[0].firstName, stud1.firstName);
    strcpy(studentList[0].lastName, stud1.lastName);

    studentList[0].gradeProj1 = stud1.gradeProj1;
    studentList[0].gradeProj2 = stud1.gradeProj2;
    studentList[0].gradeFinal = stud1.gradeFinal;

    printf("The student %s %s has the following marks: %d, %d, %f\n", stud1.firstName, stud1.lastName, stud1.gradeProj1, stud1.gradeProj2, stud1.gradeFinal);
    printf("The student %s %s has the following marks: %d, %d, %f\n", studentList[0].firstName, studentList[0].lastName, studentList[0].gradeProj1, studentList[0].gradeProj2, studentList[0].gradeFinal);

}


void illustratePointerMechanics(){
    int *ptr;             //Create a pointer that points to random memory address

    *ptr = 20;            //Dereference that pointer, 
                          // and assign a value to random memory address.
                          //Depending on external (not inside your program) state
                          // this will either crash or SILENTLY CORRUPT another 
                          // data structure in your program.  

    printf("%d\n", *ptr);   //Print contents of same random memory address
                          // May or may not crash, depending on who owns this address

    int *ptr2;              //Create pointer to random memory address

    int q = 50;            //Create local variable with contents int 50

    ptr2 = &q;              //Update address targeted by above created pointer to point
                            // to local variable your program properly created

    printf("%d\n", *ptr2);    //Happily print the contents of said local variable (q)

    return;
}