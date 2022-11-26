#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>

int main(){
    // int age;
    // printf("Enter age\n");
    // scanf("%d",&age);
    // printf("age is %d\n",age);

    // "/home/moshiur/Documents/GitHub/Learning-Advanced-C-programming/get_visual_studio_working"
    // char filename[] = "/home/moshiur/Documents/GitHub/Learning-Advanced-C-programming/get_visual_studio_working/raiyan.txt";
    // int file_fd = open(filename, O_CREAT);
    // printf("%d\n", file_fd);
    // remove(filename);


    int answer = 84 >> 1;
    printf("Answer: %d    moshiur", answer);
    pid_t id = fork();
    printf("pid value is: %d", id);
    return 0;
}
