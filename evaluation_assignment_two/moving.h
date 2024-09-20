#ifndef MOVING_H
#define MOVING_H

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


//define a function to get the cost of taking n boxes with any carrier
int get_cost(int, carrier);

char moving (int);

#endif