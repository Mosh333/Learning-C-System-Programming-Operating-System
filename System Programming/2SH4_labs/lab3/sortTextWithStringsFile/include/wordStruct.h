#ifndef WORDSTRUCT_H_   /* Include guard */
#define WORDSTRUCT_H_

typedef struct wordStorage {
    int index;
    char *word;
    int *wordAscii;
} wordStorage;

#endif