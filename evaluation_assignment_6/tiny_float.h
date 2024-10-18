#ifndef TINY_FLOAT_H
#define TINY_FLOAT_H

#include <stdint.h>

typedef enum encoding_types{
    special = -1,
    denormalized = 0,
    normalized = 1
}encoding_type;

uint8_t tiny_mult(uint8_t x, uint8_t y);

int8_t get_exponent(uint8_t input);

encoding_type get__encoding_type(uint8_t input);

uint8_t get_significand(uint8_t input);

uint8_t tiny_add(uint8_t x, uint8_t y);

uint8_t round_uint8(uint8_t input, uint8_t bits_to_remove);

uint8_t is_infinity(uint8_t input);

uint8_t is_nan (uint8_t input);

#endif