#include "powers.h"



int power(int x, int y){ //define function for x^y
        int output = x;
        for (int i = 1; i < y; i++)
        {
            output *= x;
        }
       return output; 
    }

int powers(int in){ //define function from problem description
        int i=2; //start on 2 as given by problem description
        int power_count = 0; 
        while(in>=power(i,2)){ //stop the while loop once i^2 is larger than input as any larger i will also be too big
            int j=2;
            while(in>=power(i,j)){ //check if i^j is less thna input. if so increment j and the number of powers found
                power_count++;
                j++;
            }
        i++;
        }
        return power_count;
    }

