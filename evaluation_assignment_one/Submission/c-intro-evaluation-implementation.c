/*
* CSCI 221 Intro Assignment
* Implementation file
* Put your code here
*/

#define alice_rate 200
#define bob_rate 260
#define bob_capacity 30
#define alice_capacity 23

#include "c-intro-evaluation-declarations.h"


// Put your choose_mover function here
unsigned int get_cost_of_carrier(unsigned int in, carrier carrier_in){
    unsigned int remainder = in%carrier_in.capacity; //find out how many boxes are left

    if(remainder != 0){ //not the most elegent here. feels like there should be an easy way to do this inline
                return carrier_in.rate*(((in-(remainder))/carrier_in.capacity)+1);
                //using in-remainder/capacity to get an even count of how many truckloads will be included. add one in the case there is any remainder
    }
    return carrier_in.rate*(((in-(remainder))/carrier_in.capacity));
}

char choose_mover(unsigned int input){
    {     //this is the loopless, extensible version. Below I will demonstrate a faster, less extensible approach

    /*
    //setup carriers alice and bob
    carrier alice;
    alice.capacity = alice_capacity;
    alice.rate = alice_rate;
    alice.name = 'a' ;

    carrier bob;
    bob.capacity = bob_capacity;
    bob.rate = bob_rate;
    bob.name = 'b';

    //printf( "alice costs: %d\n", get_cost_of_carrier(input, alice));
    //printf("Bob costs: %d\n", get_cost_of_carrier(input, bob));

    carrier* cheaper_carrier = get_cost_of_carrier(input, alice)<get_cost_of_carrier(input, bob)? &alice : &bob; //hahahahha C is so silly
    //create a pointer to the cheaper of the two carriers using ternary operation
    */
    //printf( "the cheaper option is: %c\n", cheaper_carrier->name); //print the name of the pointed-to carrier
    //return(cheaper_character->name);
    }
    { //fast loopless version:
    unsigned int bob_cost = input%bob_capacity == 0? bob_rate*(input/bob_capacity): bob_rate*(((input-(input%bob_capacity))/bob_capacity)+1); //get the cost for bob using the exact same if-else type stuff seen above but in ternary form because I've never used this before and find it really fun
    unsigned int alice_cost = input%alice_capacity == 0? alice_rate*(input/alice_capacity): alice_rate*(((input-(input%alice_capacity))/alice_capacity)+1);

    //printf("fast version says: %c\n", alice_cost<bob_cost? 'a':'b');
    return (alice_cost<bob_cost? 'a':'b');
    }
}

// Put your find_divisor function here
pair find_divisor(unsigned int in[], unsigned int in_size){
    pair output; 
        
            for(unsigned int i=0; i<in_size; i++){ //pretty simple double loop to get divisors. there might be a faster way to do this.
                for(unsigned int j=0; j<in_size; j++){
                    if(i==j) //ignore duplicates
                        continue;
                    
                    if(in[i]%in[j]==0){ //does j divide i?
                        output.first = in[i];
                        output.second = in[j];
                        return output;
                    }
                }
            }
            output.first = 0;
            output.second = 0;
            return output;
}


// Put your powers function here
unsigned int power(unsigned int x, unsigned int y){ //define function for x^y
        unsigned int output = x;
        for (unsigned int i = 1; i < y; i++)
        {
            output *= x;
        }
       return output; 
    }

unsigned int powers(unsigned int in){ //define function from problem description
        unsigned int i=2; //start on 2 as given by problem description
        unsigned int power_count = 0; //count how many powers have been found
        while(in>=power(i,2)){ //stop the while loop once i^2 is larger than input as any larger i will also be too big
            unsigned int j=2;
            while(in>=power(i,j)){ //check if i^j is less thna input. if so increment j and the number of powers found
                power_count++;
                j++;
            }
        i++;
        }
        return power_count;
    }

// Put your fibonacci function here

unsigned int fibonacci(unsigned int input){
    
    unsigned int current_num = 1;
    unsigned int last_num = 0;
    
    if(1>input){
        return 0;
    }else if(2>input){ //I feel like my loop should be able to handle the case n=1 but I couldn't quite get it working
        return 1;
    }

    for(unsigned int i=0; i<input-1; i++){ //input reduced by one to account for the n=1 case being handled outside the loop
        unsigned int extra_num = last_num;
        last_num = current_num;
        current_num += extra_num;
    }

    return current_num;
}


