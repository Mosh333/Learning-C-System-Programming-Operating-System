#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <getopt.h>
#include "fileAttributes.c"
#include "directoryTraversal.c"

/*
    df -> report file system disk usage
    ls -> list directories and file information
    ln -> make (sym)link between files

    Q) What are inodes in Linux/Unix?
    A) Inodes known as index node is a data structure in a Unix-style file system
    object such as file or a directory. Each inode stores attributes and disk block
    locations of the object's data. File system object attributes can include
    metadata, ownership data, permission data.
*/

// More details about Unix File (System) - Chapter 2.6.3:
// https://w3.cs.jmu.edu/kirkpams/OpenCSF/Books/csf/html/UnixFile.html

/*
    To run the program:
        Incorrectly:
            - rm ./lab5; gcc main.c -o lab5; ./lab5 -d /blah/blah -f /ha/ha
        Correctly:
            - rm ./lab5; gcc main.c -o lab5; ./lab5 -f /path/for/my/file.txt
            - rm ./lab5; gcc main.c -o lab5; ./lab5 -d /path/for/my/directory
*/

int main(int argc, char *argv[])
{
    int d_flag = 0;
    int f_flag = 0;
    char filepath[50];
    char directorypath[50];
    int flags, opt;
    int nsecs, tfnd;

    nsecs = 0;
    tfnd = 0;
    flags = 0;

    if(argc!=3){
        fprintf(stderr, "     Please enter -f or -d to indicate implementation version! \n\
     Example: 'gcc main.c -o fileExe; ./fileExe -f /absolute_path/to/file.txt' or\n\
     'gcc main.c -o directoryExe; ./directoryExe -d /absolute_path/to/directory/as_starting_point'\n");
        exit(EXIT_FAILURE);
    }

    //view getopt_core.h for flag options when working with getopt()
    //original sample code from: https://man7.org/linux/man-pages/man3/getopt.3.html
    while ((opt = getopt(argc, argv, "df:")) != -1)
    {
        switch (opt)
        {
        case 'd':
            // printf("Must print directory traversal!\n");
            if(strcmp(argv[1],"-d")==0){
                // printf("In the first position!\n");
                if(strcmp(argv[2],"-f")!=0){
                    strcpy(directorypath,argv[2]);
                    // printf("Directory argument is: %s\n", directorypath);
                }
            }else if(strcmp(argv[3],"-d")==0){
                // printf("In the second position!\n");
                if(strcmp(argv[4],"-f")!=0){
                    strcpy(directorypath,argv[4]);
                    // printf("Directory argument is: %s\n", directorypath);
                }
            }
            d_flag = 1;
            break;
        case 'f':
            // printf("Must print file information!\n");
            if(strcmp(argv[1],"-f")==0){
                // printf("In the first position!\n");
                if(strcmp(argv[2],"-d")!=0){
                    strcpy(filepath,argv[2]);
                    // printf("File argument is: %s\n", filepath);
                }
            }else if(strcmp(argv[3],"-f")==0){
                // printf("In the second position!\n");
                if(strcmp(argv[4],"-d")!=0){
                    strcpy(filepath,argv[4]);
                    // printf("File argument is: %s\n", filepath);
                }
            }
            f_flag = 1;

            break;
        default: /* '?' */
            fprintf(stderr, "Usage: %s [-d /absolute/path/to/directory] or [-f /absolute/path/to/filename] name\n",
                    argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    if(d_flag+f_flag!=1){
        fprintf(stderr, "Usage: %s [-d /absolute/path/to/directory] or [-f /absolute/path/to/filename] name\n",
                argv[0]);
        exit(EXIT_FAILURE);
    }

    if(d_flag==1){
        printFileAttributes(directorypath);
        printDirectoryTraversal(directorypath);
    }

    if(f_flag==1){
        printFileAttributes(filepath);
    }

    // printf("d_flag=%d; f_flag=%d; tfnd=%d; nsecs=%d; optind=%d\n",
    //        d_flag, f_flag, tfnd, nsecs, optind);

    // printf("argument #0: %s\n", argv[0]);
    // printf("argument #1: %s\n", argv[1]);
    // printf("argument #2: %s\n", argv[2]);
    // printf("argument #3: %s\n", argv[3]);
    // printf("argument #4: %s\n", argv[4]);

    /* Other code omitted */

    exit(EXIT_SUCCESS);

}