#include "moving.h"

//define a function to get the cost of taking n boxes with any carrier
int get_cost(int in, carrier carrier_in){

    int remainder = in%carrier_in.capacity; 
    int number_of_trips = ((in-(remainder))/carrier_in.capacity);
    int total_cost =  carrier_in.rate * number_of_trips;
    
    if(remainder != 0){//since there is a remainder we make one extra trip
                total_cost += carrier_in.rate;
    }
    return total_cost;
}

char moving (int input){    
    

    //setup carriers alice and bob. This seems like it could be automated with an initializer but no objects in C :(
    carrier alice;
    alice.capacity = alice_capacity;
    alice.rate = alice_rate;
    alice.name = 'a' ;

    carrier bob;
    bob.capacity = bob_capacity;
    bob.rate = bob_rate;
    bob.name = 'b';

    carrier* cheaper_carrier = get_cost(input, alice)<get_cost(input, bob)? &alice : &bob;

    return (cheaper_carrier->name);
}