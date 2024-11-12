#include "arrays.h"
#include <stdio.h>
#include <stdlib.h>

//ISSUES:
//node struct stores wrong type - FIXED
//tree struct is signed data - FIXED
//insert does not free node if we are inserting something already in the tree - FIXED
// from array list length is signed - FIXED
//from array outputs null if input is null rather than outputting an empty tree - FIXED
//delete returns null when tree is invalid rather than 0 - FIXED
//finding a string fails when searching for "oops" in "ooops" - FIXED
//Copying a substring does not check for the case when end is before start, nor attach the terminal character - FIXED

//notes for charlie office hrs:
// I dont understand the r defect - use 2^n -1

void print_int_array(uint32_t* array, uint32_t size){
    for (uint32_t i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf(";");
}

int main(){
    uint32_t array_a[] = {1, 2, 2, 3, 4, 5, 6};
    uint32_t array_b[] = {1, 2, 3, 4};
    uint32_t* array_null = NULL;
    uint32_t array_c[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    uint32_t* intersection = NULL;
    uint32_t intersection_size = 0;
    intersection = array_intersection(array_a, 6, array_b, 4, &intersection_size);
    print_int_array(intersection, intersection_size);
    intersection = array_intersection(array_a, 6, array_c, 10, &intersection_size);
    print_int_array(intersection, intersection_size);
    intersection = array_intersection(array_a, 7, array_null, 829049, &intersection_size);

    char string[] = "ooops";
    char needle[] = "ops";
    printf("%s;", string);
    printf("%s;", find_string(string, needle));
    char needle2[] = "oops";
    printf("%s;", find_string(string, needle2));
    char needle3[] = "apples";
    printf("%s;", find_string(string, needle3));


    printf("%s;", get_substring(string, 1, 8));
    printf("%s;", get_substring(string, 1, 4));


}