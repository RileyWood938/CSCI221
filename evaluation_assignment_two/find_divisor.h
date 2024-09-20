#ifndef FIND_DIVISOR_H
#define FIND_DIVISOR_H

typedef struct pair_{
	unsigned int first;
	unsigned int second;
}pair;

pair make_pair (unsigned int, unsigned int); //help I dont know how to not mke initializers for things that seem like they should be objects

pair find_divisor(unsigned int input[], unsigned int input_size); 

#endif