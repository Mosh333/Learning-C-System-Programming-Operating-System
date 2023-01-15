#include <stdio.h>
#include <math.h>
#include "sparseVector.h"

// as per https://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c
// unless working with pointers or strings, just pass the length
int countComponents(int source[], int length)
{
    int counter = 0;
    /*  below does not work, see SO link above
    printf("size is: %d\n", sizeof(source)/sizeof(int));
    */

    for (size_t i = 0; i < length; i++)
    {
        if (source[i] != 0)
        {
            counter++;
        }
    }

    return counter;
}

void efficient(const int source[], int val[], int pos[], int size)
{
    printf("The original array: ");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", source[i]);
    }
    printf("\n");

    int counter = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (source[i] != 0)
        {
            val[counter] = source[i];
            pos[counter] = i;
            printf("Val %d is at position %d\n", val[counter], pos[counter]);
            counter++;
        }
    }

    printf("The val array is: ");
    for (size_t i = 0; i < counter; i++)
    {
        printf("%d ", val[i]);
    }
    printf("\nThe pos array is: ");
    for (size_t i = 0; i < counter; i++)
    {
        printf("%d ", pos[i]);
    }
    printf("\n");
}

void reconstruct(int source[], int m, const int val[], const int pos[], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        source[i] = 0;
    }

    for (size_t i = 0; i < m; i++)
    {
        source[pos[i]] = val[i];
    }

    printf("Reconstructed array: ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", source[i]);
    }
}

void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2)
{
    // uniquePos will be the size of
    int uniquePos = 0;
    int searchPos = 0;
    int pos1Pointer = 0;
    int pos2Pointer = 0;
    int pos1Exhausted = -1;
    int pos2Exhausted = -1;
    if (k1 == 0 || k2 == 0)
    {
        printf("Both k1 and k2 must be at least 1!\n");
        // the below branches finds the number of uniquePos
        // find the number of uniquePos in this branch statement
        // way I written below, you set uniquePos to max of (k1,k2) then iterate through the smaller pos[] list to determine the additional
        // number of uniquePos there is in addition to the max(k1,k2)
        // in retrospect, you can just set uniquePos to either or then search then increment and it would work
    }
    else
    {
        // uniquePos must be at most k1+k2 entries
        // if there are duplicates between the two, the pair counts as one entry
        uniquePos = k1 + k2;
        // printf("uniquePos is: %d k1 %d k2 %d\n", uniquePos, k1, k2);

        for (size_t i = 0; i < k1; i++)
        {
            searchPos = pos1[i];
            for (size_t j = 0; j < k2; j++)
            {
                // printf("pos1 %d pos2 %d searchPos %d\n", pos1[i], pos2[j], searchPos);
                if (pos2[j] == searchPos)
                {
                    // duplicate
                    uniquePos--;
                }
            }
        }

        // both pos arrays are gurantteed to have at least one entry

        // printf("Val3 array is: \n");

        for (size_t i = 0; i < uniquePos; i++)
        {
            // printf("pos1[x]: %d pos2[y]: %d pos1Pointer %d  pos2Pointer %d val1[x] %d val2[y] %d k1 %d k2 %d ", pos1[pos1Pointer], pos2[pos2Pointer], pos1Pointer, pos2Pointer, val1[pos1Pointer], val2[pos2Pointer], k1, k2);

            if (pos1Exhausted == 1)
            {
                // previous iteration, we have reached the max index for pos1
                // compare logic is modified here
                // printf("In pos1Exhausted\n");
                if (pos1[pos1Pointer] < pos2[pos2Pointer])
                {
                    // confirm that pos1's last entry indeed is less thatn pos2's current entry,
                    // if so, safe to continue appending the rest of pos2 into pos3
                    val3[i] = val2[pos2Pointer];
                    pos3[i] = pos2[pos2Pointer];
                    pos2Pointer++;
                }
            }
            else if (pos2Exhausted == 1)
            {
                // previous iteration, we have reached the max index for pos2
                // compare logic is modified here
                // printf("In pos2Exhausted\n");
                if (pos2[pos2Pointer] < pos1[pos1Pointer])
                {
                    // confirm that pos1's last entry indeed is less thatn pos2's current entry,
                    // if so, safe to continue appending the rest of pos2 into pos3
                    val3[i] = val1[pos1Pointer];
                    pos3[i] = pos1[pos1Pointer];
                    pos1Pointer++;
                }
                // below is for posExhausted<1
            }
            else if (pos1[pos1Pointer] == pos2[pos2Pointer])
            {
                // equal positions, superimpose or add them up
                val3[i] = val1[pos1Pointer] + val2[pos2Pointer];
                pos3[i] = pos1[pos1Pointer];
                // printf("val3 became: %d ", val3[i]);
                if (pos1Pointer + 1 < k1)
                {
                    // ensure to not be out of bound
                    pos1Pointer++;
                }
                if (pos2Pointer + 1 < k2)
                {
                    // ensure to not be out of bound
                    pos2Pointer++;
                }
                if (pos1Pointer == k1 - 1)
                {
                    // relying on incrementing twice to get a twice in a row event
                    //-1 -> 0 -> 1
                    pos1Exhausted++;
                }
                if (pos2Pointer == k2 - 1)
                {
                    // relying on incrementing twice to get a twice in a row event
                    //-1 -> 0 -> 1
                    pos2Exhausted++;
                }

                // printf(" branch a\n");
            }
            else if (pos1[pos1Pointer] < pos2[pos2Pointer])
            {
                val3[i] = val1[pos1Pointer];
                pos3[i] = pos1[pos1Pointer];
                // printf("val3 became: %d ", val3[i]);
                // printf("    val3 became: %d because pos1[pos1Pointer] %d pos2[pos2Pointer] %d", val3[i], pos1[pos1Pointer], pos2[pos2Pointer]);
                if (pos1Pointer + 1 < k1)
                {
                    // ensure to not be out of bound
                    pos1Pointer++;
                }
                if (pos1Pointer == k1 - 1)
                {
                    // relying on incrementing twice to get a twice in a row event
                    //-1 -> 0 -> 1
                    pos1Exhausted++;
                }
                // printf(" branch b\n");
            }
            else if (pos2[pos2Pointer] < pos1[pos1Pointer])
            {
                val3[i] = val2[pos2Pointer];
                pos3[i] = pos2[pos2Pointer];
                // printf("val3 became: %d ", val3[i]);
                if (pos2Pointer + 1 < k2)
                {
                    // ensure to not be out of bound
                    pos2Pointer++;
                }
                if (pos2Pointer == k2 - 1)
                {
                    // relying on incrementing twice to get a twice in a row event
                    //-1 -> 0 -> 1
                    pos2Exhausted++;
                }
                // printf(" branch c\n");
            }
        }

        // printf("\n");
        printf("val1 array: ");
        for (size_t i = 0; i < k1; i++)
        {
            printf("%d ", val1[i]);
        }
        printf("\n");
        printf("val2 array: ");
        for (size_t i = 0; i < k2; i++)
        {
            printf("%d ", val2[i]);
        }
        printf("\n");
        printf("pos1 array: ");
        for (size_t i = 0; i < k1; i++)
        {
            printf("%d ", pos1[i]);
        }
        printf("\n");
        printf("pos2 array: ");
        for (size_t i = 0; i < k2; i++)
        {
            printf("%d ", pos2[i]);
        }
        printf("\n");
        printf("val3: ");
        for (size_t i = 0; i < uniquePos; i++)
        {
            printf("%d ", val3[i]);
        }
        printf("\n");
        printf("pos3: ");
        for (size_t i = 0; i < uniquePos; i++)
        {
            printf("%d ", pos3[i]);
        }
    }

    printf("\nUnique Pos Entries: %d", uniquePos);
}