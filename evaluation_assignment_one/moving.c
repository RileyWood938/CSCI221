#include <stdio.h>
#include <stdlib.h>

#define alice_rate 200
#define bob_rate 260
#define bob_capacity 30
#define alice_capacity 23

//define  astruct to store information about our carriers. very overengineered but allows for good extensibility
typedef struct carriers{
    int rate;
    int capacity;
    char name;
} carrier;

int main (int argc, char *argv[]){    
    if(argc < 2){
        return 1;
        //terminate if no input was given
    }
    int input = atoi(argv[1]); 

    //this is the loopless, extensible version. at the bottom I will demonstrate a faster, less extensible approach

    //setup carriers alice and bob
    carrier alice;
    alice.capacity = alice_capacity;
    alice.rate = alice_rate;
    alice.name = 'a' ;

    carrier bob;
    bob.capacity = bob_capacity;
    bob.rate = bob_rate;
    bob.name = 'b';


    //define a function to get the cost of taking n boxes with any carrier
    int get_cost(int in, carrier carrier_in){
        int remainder = in%carrier_in.capacity; //find out how many boxes are left

        if(remainder != 0){ //not the most elegent here. feels like there should be an easy way to do this inline
                    return carrier_in.rate*(((in-(remainder))/carrier_in.capacity)+1);
                    //using in-remainder/capacity to get an even count of how many truckloads will be included. add one in the case there is any remainder
        }
        return carrier_in.rate*(((in-(remainder))/carrier_in.capacity));
    }

    printf( "alice costs: %d\n", get_cost(input, alice));
    printf("Bob costs: %d\n", get_cost(input, bob));

    carrier* cheaper_carrier = get_cost(input, alice)<get_cost(input, bob)? &alice : &bob; //hahahahha C is so silly
    //create a pointer to the cheaper of the two carriers using ternary operation

    printf( "the cheaper option is: %c\n", cheaper_carrier->name); //print the name of the pointed-to carrier

    
    //------------------------------------------
    //fast loopless version:
    int bob_cost = input%bob_capacity == 0? bob_rate*(input/bob_capacity): bob_rate*(((input-(input%bob_capacity))/bob_capacity)+1); //get the cost for bob using the exact same if-else type stuff seen above but in ternary form because I've never used this before and find it really fun
    int alice_cost = input%alice_capacity == 0? alice_rate*(input/alice_capacity): alice_rate*(((input-(input%alice_capacity))/alice_capacity)+1);

    printf("fast version says: %c\n", alice_cost<bob_cost? 'a':'b');

}