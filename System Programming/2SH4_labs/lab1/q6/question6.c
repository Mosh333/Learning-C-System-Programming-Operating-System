// Header file for input output functions
#include <stdio.h>

// main function -
// where the execution of program begins
int main()
{   
    int a,b,c;
    //a^2+b^2=c^2
    int maxlength = 401;
    int leftHandSide = 0;
    int rightHandSide = 0;
    int counter = 0;
    for (a = 0; a < maxlength; a++)
    {
        for (b = 0; b < maxlength; b++)
        {
            for (c = 0; c < maxlength; c++)
            {
                leftHandSide = a*a + b*b;
                rightHandSide = c*c;
                if(leftHandSide==rightHandSide && a!=0 && b!=0){
                    printf("The a=%d b=%d and c=%d combinations satisfies the Pythagorean triple.\n", a, b, c);
                    counter++;
                }
            }
            
        }
        
    }
    printf("In total, there were %d combinations found under given constraint.\n", counter);

    return 0;
}