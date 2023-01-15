#include <stdio.h>
#include <math.h>

#define N 26

void letter_freq(const char word[], int freq[]){
    //counter number of unique alphabet letter
    int i=0;
    char letter;
    
    while(word[i]!='\0'){

        //use "case" rather than "if" since access is O(1) rather than O(n) (think circuit mux switch)
        letter = word[i];
        switch (letter)
        {
        case 'a':
        case 'A':
            freq[0]++;
            break;
        case 'b':
        case 'B':
            freq[1]++;
            break;
        case 'c':
        case 'C':
            freq[2]++;
            break;
        case 'd':
        case 'D':
            freq[3]++;
            break;
        case 'e':
        case 'E':
            freq[4]++;
            break;
        case 'f':
        case 'F':
            freq[5]++;
            break;
        case 'g':
        case 'G':
            freq[6]++;
            break;
        case 'h':
        case 'H':
            freq[7]++;
            break;
        case 'i':
        case 'I':
            freq[8]++;
            break;
        case 'j':
        case 'J':
            freq[9]++;
            break;
        case 'k':
        case 'K':
            freq[10]++;
            break;        
        case 'l':
        case 'L':
            freq[11]++;
            break;
        case 'm':
        case 'M':
            freq[12]++;
            break;
        case 'n':
        case 'N':
            freq[13]++;
            break;
        case 'o':
        case 'O':
            freq[14]++;
            break;
        case 'p':
        case 'P':
            freq[15]++;
            break;
        case 'q':
        case 'Q':
            freq[16]++;
            break;
        case 'r':
        case 'R':
            freq[17]++;
            break;
        case 's':
        case 'S':
            freq[18]++;
            break;
        case 't':
        case 'T':
            freq[19]++;
            break;
        case 'u':
        case 'U':
            freq[20]++;
            break;
        case 'v':
        case 'V':
            freq[21]++;
            break;
        case 'w':
        case 'W':
            freq[22]++;
            break;
        case 'x':
        case 'X':
            freq[23]++;
            break;
        case 'y':
        case 'Y':
            freq[24]++;
            break;
        case 'z':
        case 'Z':
            freq[25]++;
            break;
        //other cases which should not happen
        default:
        
            break;
        }

        i++;
    }

    return;    
}

void print_letter_freq(const char word[], int freq[]){
    int letter=97;
    printf("begin\n");
    printf("Letter frequency for the word \"%s\" is:\n", word);
    for (size_t i = 0; i < N; i++)
    {
        if(i<N-1){
            printf("%d The count of '%c' and '%c' is %d\n", i, (char)(letter-32), (char)letter,  freq[i]);
        }else{
            //omit new line for 'z'/'Z'
            printf("%d The count of '%c' and '%c' is %d", i, (char)(letter-32), (char)letter, freq[i]);
        }
        
        letter++;
    }

    printf("\nend");
    return;
}