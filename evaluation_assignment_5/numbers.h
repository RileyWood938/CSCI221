#ifndef NUMBERS_H
#define NUMBERS_H
#include <stdint.h>

int16_t negate(int16_t input); //returns the addative inverse of input. in the case input is the max value for uint16_t, returns 1.

int32_t conditional(int32_t x, int32_t y, int32_t z);

//char* convert_10_to_2 (uint32_t input);

int64_t my_add(int32_t a, int32_t b);

//int64_t add_bits(uint32_t a, uint32_t b, int32_t* carry, int64_t output, uint32_t mask);

//int64_t linker_return_int ();

#endif