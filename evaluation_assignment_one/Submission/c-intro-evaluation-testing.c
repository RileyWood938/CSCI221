/*
* CSCI 221 Intro Assignment
* Main file
* Put your testing here
*/

#include <stdio.h>
#include <stdlib.h>
#include "c-intro-evaluation-declarations.h"

// Put your testing inside this function
int main(int argc, char* argv[]){
    
    if(2>argc)
        return 1;
    //ensure that an input number has been given 

    int input = atoi(argv[1]);

    //printf("%c", choose_mover(28));

    printf("%d", fibonacci(input));
	return 0;
}