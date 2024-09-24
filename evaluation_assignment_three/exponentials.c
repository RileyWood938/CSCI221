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
        if (y % 2 == 1) //if Y odd
        {
            remainder = x * remainder; 
            //could add a "y--;"" here if you wanted things to be more readable/consistant. Not required for my architecture and compiler. It also reduces effeciency so I chose to omit it
        }
        output = output * output; //square output
        y = y / 2;
    } 
    return remainder * output;
}