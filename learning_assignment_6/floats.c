#include "floats.h"
#include <inttypes.h>
#include <stdio.h>

encoding_type get__encoding_type(float input)
{
    uint32_t* input_bits = (uint32_t*) &input;
    printf("%f\n", *(float*)input_bits);
    printf("%x\n", *input_bits);

    uint32_t mask = 255;
    mask = mask<<23;

    if((*input_bits & mask) != 0){
        if(((*input_bits & mask) ^mask) == 0){
            return special;
        }
        return normalized;
    }

    return denormalized;
}
