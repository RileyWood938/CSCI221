#ifndef ARRAYS_H
#define ARRAYS_H

#include <stdint.h>
#include "binary_tree.h"


uint32_t* array_intersection(uint32_t a[], uint32_t size_a, uint32_t b[], uint32_t size_b, uint32_t* intersection_size); 

char* find_string (char* haystack, char* needle);

char* get_substring (char* string, uint32_t start, uint32_t end);

#endif