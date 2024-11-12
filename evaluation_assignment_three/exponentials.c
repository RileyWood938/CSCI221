#include "exponentials.h"

unsigned int exponentiate(unsigned int x, unsigned int y)
{ //this function calculates x^y by squaring x and halving y repeatedly until y=1. In cases where y is odd, it includes an extra copy of the original value x that is multiplied back in at the end.
    if(1 > y){ //handle that case y=0
        return 1;
    }
    int remainder = 1;
    int output = x;
    while (y > 1)
    {
        if (y % 2) //if Y odd
        {
            remainder *= output; // when you reach this statement, remainer *= x works only on the first iteration. After that the number of exponentiations you are removing incrases with the current step of the loop. fortunately, output has the correct associated number of exponentiations we have removed so we can multiply that many more into the remainder each time
        }
        output *= output; //square output 
        y /= 2; 
    } 
    return remainder * output;
}