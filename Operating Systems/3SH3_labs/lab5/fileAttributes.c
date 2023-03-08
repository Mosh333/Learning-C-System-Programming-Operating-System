#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>    
#include <string.h>
#include <time.h>

/*
Sample output from stat():
$ stat ./testDir/file1.txt 
  File: ./testDir/file1.txt
  Size: 0               Blocks: 0          IO Block: 4096   regular empty file
Device: 803h/2051d      Inode: 1196357     Links: 1
Access: (0664/-rw-rw-r--)  Uid: ( 1000/ moshiur)   Gid: ( 1000/ moshiur)
Access: 2023-03-05 18:05:47.106652298 -0500
Modify: 2023-03-05 18:05:46.918648604 -0500
Change: 2023-03-05 18:05:46.918648604 -0500
 Birth: 2023-03-05 18:05:46.918648604 -0500
*/

void printFileAttributes(const char *resourcePath)
{
    // this function has to get inode data for a file, directory and a symbolic link give a path

    if (access(resourcePath, F_OK) == 0)
    {
        // file exists
        struct stat fileStat;
        printf("The following are the file attributes for: %s\n", resourcePath);

        stat(resourcePath, &fileStat);
        struct passwd *userDB = getpwuid(fileStat.st_uid);
        struct group *groupDB = getgrgid(fileStat.st_uid);
        unsigned int filePermission = (__uintmax_t) fileStat.st_mode; 
        
        //set user id (4), set group id (2) and sticky (1) and sum them so we can print in Unix style octal format (with four digits)
        //https://www.gnu.org/software/libc/manual/html_node/Permission-Bits.html
        //https://stackoverflow.com/a/6632830
        //https://stackoverflow.com/a/32729366
        unsigned int userId = fileStat.st_mode & S_ISUID;
        unsigned int groupId = fileStat.st_mode & S_ISGID;
        unsigned int stickyBit = fileStat.st_mode & S_ISVTX;
        //printf("userId, groupId, stickyBit %d %d %d\n", userId, groupId, stickyBit);
        //we don't need to left shift by 12 bits because we are manually printing
        //but if we grabbed the userId and groupId with the fileStat.st_uid or fileStat.st_gid
        //we wouldn't need to "shift" up the bits by 12 but for the sticky bit, a 12 bit left shift will be mostly likely needed
        //unless a system call can help us get that in octal format
        unsigned int firstDigitInFourDigitPermission = (__uintmax_t) (userId+groupId+stickyBit);

        //difference between 775 and 0775: https://askubuntu.com/questions/976168/difference-between-three-and-four-digit-file-permissions/976170#976170
        printf("Mode (permissions): %o%o (octal)\n", firstDigitInFourDigitPermission, filePermission&0b111111111); 
        printf("Number of links: %ld\n", fileStat.st_nlink);
        printf("Owner Name: %s\n", userDB->pw_name);        //numerical representation via: fileStat.st_uid or userDB->pw_uid
        printf("Group Name: %s\n", groupDB->gr_name);        //numerical representation via: fileStat.st_gid or groupDB->gr_gid
        printf("Size in bytes: %ld bytes\n", fileStat.st_size);
        printf("Size in blocks: %ld\n", fileStat.st_blocks);
        printf("Last modification time: %s", ctime(&fileStat.st_mtime));
        printf("Name: %s\n", resourcePath);

        //To print the symbolic link path x -> y
        //to read the link: https://stackoverflow.com/questions/3984948/how-to-figure-out-if-a-file-is-a-link
        //https://stackoverflow.com/questions/4572805/is-there-a-way-to-see-the-actual-contents-of-a-symlink

        /*
            Pseudocode might be:
                if(is a symlink):
                    print(symlink -> actualFile Pointed to)
        */
    }
    else
    {
        // file doesn't exist
        printf("The file/directory/symlink does not exist!\n");
    }

}