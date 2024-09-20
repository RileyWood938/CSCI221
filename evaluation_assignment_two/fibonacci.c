#include "fibonacci.h"


int fibonacci (int input){

    if(1>input){
        return 1;
    }
    
    int current = 1;
    int previous = 0;

    for(int i=0; i<input-1; i++){ //input reduced by one to account for the n=1 case being handled outside the loop
        int swap = previous;
        previous = current;
        current += swap;
    }

    return(current);
    
}

