#include "arrays.h"
#include <stdio.h>
#include <stdlib.h>

char* find_string (char* haystack, char* needle){ //borrowed these names from the standard string library's strstr function
    if((!haystack) || (!needle)){
        return NULL;
    }
    char* current_haystack = haystack;
    char* current_needle = needle;
    char* needle_start = NULL;

    while(*current_haystack != '\0'){ //iterate through the haystack

        if(*current_haystack == *current_needle){ //if the next character matches
            
            if(current_needle == needle){ //if we are on the first character of the needle string
                needle_start = current_haystack;
            }

            current_needle++;

            if(*current_needle == '\0'){ //we made it through the whole needle string
                return needle_start;
            }


        }else{ //if there is no match reset to the start of the needle
            if(current_needle != needle){

                current_needle = needle;
                continue;
            }
        }
        
        current_haystack++; 


    }

    return current_haystack;
}

char* get_substring (char* string, int32_t start, int32_t end){
    if(!string){
        return NULL;
    }
    char* output = malloc(end-start);
    for (int32_t i = 0; i <= end; i++)
    {
        if(string[i] == '\0'){
            return NULL;
        }

        if(i>=start){
            output[i-start] = string[i];
        }
    }
    return output;
}

int32_t* array_intersection(int32_t a[], int32_t size_a, int32_t b[], int32_t size_b, int32_t* intersection_size)
{   
    if((!a) || (!b)){
        return NULL;
    }
    int8_t *truth_table = calloc(size_b, sizeof(int8_t)); //create a table to keep track of which elements are in the intersection
    int32_t counter = 0;
    binary_tree* tree_a = tree_from_array(a, size_a);
    
    for (int32_t i = 0; i < size_b; i++)
    {
        if(tree_remove_value(tree_a, b[i]) == 1){
            truth_table[i] = 1;
            counter++;
        }
    }

    int32_t *output = calloc(counter, sizeof(int32_t));
    int32_t next = 0;

    for (int32_t i = 0; i < size_b; i++)
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