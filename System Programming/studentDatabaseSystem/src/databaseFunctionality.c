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

    int temp1;
    char temp2[15], temp3[15];
    

    FILE *fptr;
    char buff[256];
    int size;
    printf("Filename is: %s\n", filename);
    #ifdef _WIN32
        fptr = fopen(".\\src\\studentDatabase.txt","r"); //w+ for reading+writing
    #elif __unix__
        fptr = fopen("./src/studentDatabase.txt","r"); //w+ for reading+writing
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
    //     // student *oneStudent = (struct student*)calloc(1,sizeof(student));
    //     //rand() % 10000 + 1
    //     // oneStudent->studentId = rand() % 10000 + 1;
    //     // strcpy(oneStudent->firstName, "moshiur");
    //     // strcpy(oneStudent->lastName, "howlader");

    //     // printf("%p, %p, %d, %s, %s\n", &oneStudent, &oneStudent->studentId, oneStudent->studentId, oneStudent->firstName, oneStudent->lastName);

    //     // printf("%p, %p, %p, %p, %p\n", &studentList[i], *oneStudent, oneStudent, &studentList, &studentList[i]->firstName);
    //     printf("%p, %p, %s, %s\n", &studentList[i], &studentList, &studentList[i]->firstName, &studentList[i]->lastName);

    //     // printf("%d\n",i);
    //     // int randVal = rand() % 10000 + 1;
    //     // printf("%d\n", randVal);
    //     // int val = 5;
    //     // studentList[i]->studentId = 2;
    //     // printf("%d, %d, %d\n", &studentList, &studentList[i], &studentList[i]->studentId);
    //     // &studentList[i]->firstName = "moshiur";
    //     // &studentList[i]->lastName = "howlader";
    //     // &studentList[i]->gradeProj1 = 86;
    //     // &studentList[i]->gradeProj2 = 94;
    //     // &studentList[i]->gradeFinal = (&studentList[i]->gradeProj1 + &studentList[i]->gradeProj2)/2;

    //     // printf("%d\n", &studentList[i]->firstName);

        fscanf(fptr,"%i %s %s", &temp1, temp2, temp3);
        printf("%i %s %s\n", temp1, temp2, temp3);

    }
    
    //student *pointer = *student1;
    //student **data = &pointer;

    // printf("%s", buff);
    // fgets(buff,5,fptr);
    // printf("%s\n", buff);

    fclose(fptr);     //doing free(fptr); works sometimes, other times a segmentation fault

    return studentList;
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