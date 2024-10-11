#ifndef ARRAYS_H
#define ARRAYS_H

#include <stdint.h>
#include "binary_tree.h"


int32_t* array_intersection(int32_t a[], int32_t size_a, int32_t b[], int32_t size_b, int32_t* intersection_size); 

char* find_string (char* haystack, char* needle);

char* get_substring (char* string, int32_t start, int32_t end);

#endif