#include "arrays.h"
#include <stdio.h>
#include <stdlib.h>

void print_int_array(int32_t* array, int32_t size){
    for (int32_t i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf(";");
}

int main(){
    int32_t array_a[] = {1, 2, 2, 3, 4, 5, 6};
    int32_t array_b[] = {1, 2, 3, 4};
    int32_t* array_null = NULL;
    int32_t array_c[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    int32_t* intersection = NULL;
    int32_t intersection_size = 0;
    intersection = array_intersection(array_a, 6, array_b, 4, &intersection_size);
    print_int_array(intersection, intersection_size);
    intersection = array_intersection(array_a, 6, array_c, 10, &intersection_size);
    print_int_array(intersection, intersection_size);
    intersection = array_intersection(array_a, 7, array_null, 829049, &intersection_size);

    char string[] = "apple";
    char needle[] = "pl";
    printf("%s;", string);
    printf("%s;", find_string(string, needle));

    printf("%s;", get_substring(string, 1, 8));
    printf("%s;", get_substring(string, 1, 4));


}