#include "arrays.h"
#include <stdio.h>
#include <stdlib.h>

char* find_string (char* haystack, char* needle){ //borrowed these names from the standard string library's strstr function
    if((!haystack) || (!needle)){
        return NULL;
    }
    char* current_haystack = haystack;
    char* current_needle = needle;
    char* needle_start = haystack;

    while(*current_haystack != '\0'){ //iterate through the haystack

        if(*current_haystack == *current_needle){ //if the current character matches
            
            if(current_needle == needle){ //and we are on the first character of the needle string
                needle_start = current_haystack; //note the placement in the haystack where we are starting the needle string
            }

            current_needle++; //iterate the needle

            if(*current_needle == '\0'){ //then if we are at the end of the needle
                return needle_start; //return the position where we started this iteration through the needle
            }


        }else{ //if there is no match reset to the start of the needle, and resume our search where we last started going through the needle
            if(current_needle != needle){
                current_needle = needle;
                current_haystack = needle_start;
            }
        }
        
        current_haystack++; 


    }

    return current_haystack;
}

char* get_substring (char* string, uint32_t start, uint32_t end){ 
    if(!string){
        return NULL;
    }
    if(start > end){
        return NULL;
    }
    char* output = malloc((end-start));
    for (uint32_t i = 0; i < end; i++) 
    {
        if(string[i] == '\0'){
            return NULL;
        }

        if(i>=start){
            output[i-start] = string[i];
        }
    }
    output[end-start] = '\0';
    return output;
}

uint32_t* array_intersection(uint32_t a[], uint32_t size_a, uint32_t b[], uint32_t size_b, uint32_t* intersection_size)
{   
    if((!a) || (!b)){
        return NULL;
    }
    uint8_t *truth_table = calloc(size_b, sizeof(uint8_t)); //create a table to keep track of which elements are in the intersection
    uint32_t counter = 0;
    binary_tree* tree_a = tree_from_array(a, size_a);
    
    for (uint32_t i = 0; i < size_b; i++)
    {
        if(tree_remove_value(tree_a, b[i]) == 1){
            truth_table[i] = 1;
            counter++;
        }
    }

    uint32_t *output = calloc(counter, sizeof(uint32_t));
    uint32_t next = 0;

    for (uint32_t i = 0; i < size_b; i++)
    {
        if(truth_table[i] == 1){
            output[next] = b[i];
            next++;
        }
    }
    free(truth_table);
    *intersection_size = counter;
    return output;
    
    



    // int8_t *truth_table = calloc(size_a, sizeof(int8_t)); //create a table to keep track of which elements are in the intersection
    // int32_t counter = 0;

    // for(int i=0; i<size_a; i++){ //iterate throguh both arrays to populate the truth table
    //     for(int j=0; j<size_b; j++){
    //         if(a[i]==b[j]){
    //             truth_table[i] = 1;
    //             counter++;
    //             break;
    //         }
    //     }
    // }
    
    // if(counter<=0){ //if the intersection is nothing return early
    //     return NULL;
    // }

    // int32_t *intersection = calloc(counter, sizeof(int32_t)); //create the output array now that we know its size
    
    // int32_t next = 0;

    // for(int i=0; i<size_a; i++){ //reiterate through the first array and put all elemetns flagged by the truth table into the intersection
    //     if(truth_table[i] ==1 ){
    //         intersection[next] = a[i];
    //         next++;
    //     }
    // }

    // *intersection_size = counter;
    // return intersection;

}