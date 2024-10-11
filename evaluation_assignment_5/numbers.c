#include "numbers.h"
#include <stdio.h>
#include <stdlib.h>

/*
uint32_t power(uint32_t base, uint32_t exp)
{
    uint32_t result = 1;
    while (exp)
    {
        if (exp % 2)
           result *= base;
        exp /= 2;
        base *= base;
    }
    return result;
}

char *convert_10_to_2(uint32_t input)
{
    char* output = malloc(32);
    char* current_character = output;
    for (int8_t i = 1; i < 32; i++)
    {
        *current_character = '0';
        current_character++;
    }
    *current_character = '\0';
    current_character --;

    while(input > 1){
        if(input % 2 == 0){
            input /= 2;
            current_character--;
        }else{
            input --;
            input /=2;
            *current_character = 1;
            current_character--;
        }
    }

    return output;
}
*/

int64_t my_add(int32_t a, int32_t b)
{

    if (a > 0 && b > 0) //when both inputs are positive, we know the result will be positive, and that any overflow will be captured by the 0 that begins all positive numbers in the two's compliment system.
    { 
        uint32_t sum = (uint32_t)a + (uint32_t)b; //treat everything as unsigned so that when it is extended it will fill with all 0s
        int64_t output = ((uint64_t)(sum));
        return output;
    }
    if (a < 0 && b < 0) //when both inputs are negative we know the result will be negative, We can ignore any overflow as long as we fill the first 32 bits of the output with 1's.
    {
        uint32_t sum = (uint32_t)a + (uint32_t)b; //add them, using unsigned to avoid any issues with extending to 64 bits
        int64_t output = -1;
        int64_t mask = -1; 
        output &= ((uint64_t)(sum)) | (mask<<32); //use a mask of 32 1's to force the result to be negative
        return output;
    }

    // if the numbers are differrent signs, the result will not overflow so we can add as normal and then extend the result.
    int32_t sum = a + b;
    return (int64_t)sum;

    /*
        uint32_t a_unsigned = 0;
        uint32_t b_unsigned = 0;
        a_unsigned |= a;
        b_unsigned |= b;
        uint64_t output_unsigned = 0;
        int64_t output_signed = 0;
        uint32_t sum_unsigned = 0;

        if(a<0 && b<0){ //underflow only occurrs when both are negative
            sum_unsigned = a_unsigned + b_unsigned; //problem is with this conversion
            //uint64_t d = c;
            output_unsigned |= sum_unsigned;
            uint64_t mask = UINT64_MAX;
            output_unsigned |= mask << 33;
            output_signed |= output_unsigned;
            return output_signed;
        }


        if(a>0 && b>0){ //all overflow will be caught here
            sum_unsigned = a_unsigned + b_unsigned;
            output_unsigned = sum_unsigned ;
            output_signed |= output_unsigned;
            return output_signed;
        }

        int32_t sum = a + b;
        if(sum<0){
            output_unsigned = sum & (output_unsigned-1) ;
            return output_unsigned;
        }else{
            output_unsigned = sum | output_unsigned ;
            return output_unsigned;
        }

    */

    /*
        int32_t carry = 0;
        int64_t output = 0;
        for (int32_t i = 0; i < 31; i++)
        {
            uint32_t mask = 1;
            mask = mask<<i;
            uint32_t a_masked = (a&mask);
            uint32_t b_masked = (b&mask);

            output = add_bits(a_masked, b_masked, &carry, output, mask);

        } //at this point we have added the first 31 bits of the number and we now approach the 32nd. Since this bit contains two's compliment info we need to be careful to preserve it
        uint32_t mask = 1;
        mask = mask << 31;
        uint32_t a_masked = (a & mask);
        uint32_t b_masked = (b & mask);

        if ((a_masked & b_masked) != 0){ // they are both 1
            // fill with 1s
            output = add_bits(a_masked, b_masked, &carry, output, mask);
            int64_t new_mask = -1;
            output |= (new_mask<<32);
            return output;

        }
        else if ((a_masked | b_masked) == 0){
            // they are both 0s
            //output = add_bits(a_masked, b_masked, &carry, output, mask);
             if(carry != 0){
                 output |= mask;
             }
            return output;
        }
        else
        { // add them
                return output;
                output = add_bits(a_masked, b_masked, &carry, output, mask);
                if(carry){
                    //output |= mask;
                }else{
                    int64_t new_mask = -1;
                    output |= (new_mask<<32);
                    return output;
                }

        }

        if(carry){
            uint64_t mask = 1;
            mask = mask<<63;
            output |= mask;
        }

        return output;
    */
}

int16_t negate(int16_t input)
{
    int16_t output;
    output = ~input;
    output++;
    return output;
}

int32_t conditional(int32_t x, int32_t y, int32_t z)
{
    int32_t x_eval = x | x << 1; // repeatedly bitshift left to ensure that the leftmost bit will be 1 if any bit in the string is 1
    x_eval |= x_eval << 2;
    x_eval |= x_eval << 4;
    x_eval |= x_eval << 8;
    x_eval |= x_eval << 16;

    x_eval |= x_eval >> 1; // do the same in reverse. this process will give a string of all 1's if there is a 1 at any position
    x_eval |= x_eval >> 2;
    x_eval |= x_eval >> 4;
    x_eval |= x_eval >> 8;
    x_eval |= x_eval >> 16;

    y &= x_eval;  // y=y if x had a 1 in any position, otherwise y=0
    z &= ~x_eval; // z=z if x had a 1 in any position, otherwise y=0

    return y | z; // since either y or z will be zero, or can combine them
}
