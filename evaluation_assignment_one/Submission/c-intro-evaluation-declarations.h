#ifndef HEADER_H
#define Header_H
/*
* CSCI 221 Intro Assignment
* Header file
* You should not need to edit this file 
* unless you are creating additional functions
*/

typedef struct pair_{
	unsigned int first;
	unsigned int second;
}pair;

typedef struct carriers{//define a struct to store information about our carriers. Very overengineered but allows for good extensibility
    int rate;
    int capacity;
    char name;
} carrier; 

unsigned int get_cost_of_carrier(unsigned int, carrier);

char choose_mover(unsigned int);

pair find_divisor(unsigned int[], unsigned int);

unsigned int power(unsigned int, unsigned int);

unsigned int powers(unsigned int);

unsigned int fibonacci(unsigned int);

#endif