#include "hello_world.h"
#include "array_initializer.h"
#include <stdio.h>
#include <stdlib.h>


int main (/*int argc, char *argv[]*/) {
    //main function is entry point. args represents potential inputs from command line running code

    printf("Hello World!");
    //print output

    int test_array[array_size];

    initialize_int_array(test_array, array_size, 0);

    //for(int i=0; i<sizeof(testArray)/4; i++){
    //for(int i=0; i<sizeof(test_array)/sizeof(test_array[0]); i++){
            //better form here is to use the element size rather than a hard coded value
    //for(int i=0; i<array_size; i++){
        // sounds like its better to track the size myself
    //    test_array[i] = 0;
    //}


    return 0;
    //end program with success code
 }