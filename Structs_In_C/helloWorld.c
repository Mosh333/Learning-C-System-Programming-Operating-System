#include<stdio.h>
#include<string.h>

struct Student
{
    char name[25];
    int age;
    char branch[10];
    char gender;
};

int main(){
    struct Student newStud;
    newStud.age = 15;
    strcpy(newStud.branch,"Test");
    newStud.gender = 'F';
    strcpy(newStud.name, "Sarah");

    printf("%s, %d, %s, %c", newStud.name, newStud.age, newStud.branch, newStud.gender);

    printf("\n");

    return 0;
}