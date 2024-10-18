#include "tiny_float.h"
#define BIAS 7
#define EXPONENT_MASK 120
#define SIGNIFICAND_MASK 7
#define SIGN_MASK 128
#define NAN 121
#define INFINITY 120
#include <stdio.h>
//#define DEBUG 1
//TODO: rounding, check denormalized, handle specials

uint8_t tiny_mult(uint8_t x, uint8_t y)
{
    uint8_t product = 0;
    //get the correct sign for the number
    uint8_t mask = SIGN_MASK;
    if(((mask & x)^(mask & y)) != 0){
        product |= mask; //its negative
        #if DEBUG
            printf("negative detected\n");
        #endif
    } 

    //begin by handling special encodings
    if(is_nan(x) || is_nan(y)){ //nan input always yeilds nan output
        #if DEBUG
            printf("nan input detected. returning nan\n");
        #endif
        return NAN;
    }

    if(is_infinity(x) || is_infinity(y)){
        if(x ==0 || y==0){
            #if DEBUG
                printf("infinity * 0, returning NAN");
            #endif
            return NAN;
        }
        product |= INFINITY;
        #if DEBUG
            printf("infinite input detected, returning infinity\n");
        #endif
        return product;
    }




    

    //hande exponents
    int8_t x_exponent = get_exponent(x); 
    int8_t y_exponent = get_exponent(y);
    int16_t prod_exponent = x_exponent + y_exponent;
    #if DEBUG
        printf(" x exponent: %d\n", x_exponent);
        printf(" y exponent: %d\n", y_exponent);
        printf("product exponent %x   %d \n",prod_exponent, prod_exponent);
    #endif
    


    //hande overflow/underflow
    if(prod_exponent > 7){   //overflow
        #if DEBUG
        printf("multiply exponent overflow\n");
        #endif
        return INFINITY; 
    }
    
    


    //handle multiplication of significands

    //first get the significands on their own in uint8's
    uint8_t x_significand = get_significand(x);
    
    uint8_t y_significand = get_significand(y);

    //multiply the two together
    uint8_t prod_significand = x_significand * y_significand;
    #if DEBUG
        printf("significand product %x\n", prod_significand); 
    #endif
    //since the multiplication was done with the two treated as integers (decimal shifted right 3), decimal will be six places to the left

    if(prod_exponent < -6){ //if the exponent underflowed
        while(prod_exponent < -6){
            prod_significand >>=1;
            prod_exponent ++;
        }
        prod_significand = round_uint8(prod_significand, 3);
        prod_significand<<=2;
        #if DEBUG
        printf("exponent underflow \n");
        #endif
    }else

    //if there was overflow into the left (into the 8th bit) increment the exponent and round by 1 more
    if(prod_significand>=128){ //if there is something in the 8th bit
        
        prod_significand = round_uint8(prod_significand, 4);//round bits 1, 2, 3, 4 into 5-8
        prod_significand <<= 1; //shift the implied bit out of range
        prod_exponent ++; //increment exponent

        //three leftmost bits are now the significand
        #if DEBUG
         printf("significand overflowed into the 8th bit %x\n", prod_significand);
        #endif

    }else{ //if there is nothing in the left bit

        //shift things left until something is in bit 7 or exponent becomes -6
        
        while(prod_exponent > -6 && prod_significand < 32){
            prod_exponent --;
            prod_significand <<= 1; 
            #if DEBUG
                printf("significand shifted left %x\n", prod_significand);
            #endif
        }

        prod_significand = round_uint8(prod_significand, 3);
        //round bits 1,2,3 into 4,5,6,7

        if(prod_significand >= 64 && prod_exponent ==-6){
            prod_exponent++;
            #if DEBUG
                printf("exponent incremented when implicit 1 shifted out of range");
            #endif
        }

        prod_significand <<=2;
        #if DEBUG
            printf("final significand %x\n", prod_significand);
        #endif

        //three leftmost bits are now significand

    }

    //reassemble number
    product |= (prod_significand >> 5); //add the significand
    #if DEBUG
        printf("product with significand %x \n", product);
    #endif

    if(prod_exponent != -6){ //if the output isn't denormalized, include the exponent
        product |= (prod_exponent + BIAS) <<3;
    }

    #if DEBUG
        printf("final product %x \n", product);
    #endif

    return product;
}

uint8_t is_nan(uint8_t input){
    uint8_t mask = 127;
    if((input & mask) > 120){ //make sure to ignore sign bit when checking how bit the number is
        return 1;
    }else{
        return 0;
    }
}

uint8_t is_infinity(uint8_t input){
    uint8_t mask = 127;
    if((input & mask) == INFINITY){
        return 1;
    }else{
        return 0;
    }
}

uint8_t round_uint8 (uint8_t input, uint8_t bits_to_remove){ //takes the number to be rounded and the number of bits to remove from the right
    uint8_t mask = 0;
    uint8_t output = input;
    for (uint8_t i = 0; i < bits_to_remove; i++)
    {
        uint8_t temp_mask = 1;
        temp_mask <<= i;
        mask |= temp_mask;
    }
    uint8_t least_significant_bit_mask = 1;
    least_significant_bit_mask <<= bits_to_remove;
    
    //this if/else logic could be simplified but would be more confusing to explain if it was, so i have left it to the compiler to simplify

    if((input & mask) < (least_significant_bit_mask>>1)){ //if we are less than halfway 
        //round down
        output &= (~mask); //make all the bits we are rounding 0
        #if DEBUG
            printf("rounding down (no tie)\n");
        #endif

    }else if((input & mask)>(least_significant_bit_mask>>1)){     //if we are more than halfway 
        //round up
        output &= (~mask); //make bits we are rounding 0
        output += least_significant_bit_mask; //increment lsb
        #if DEBUG
            printf("rounding up (no tie)\n");
        #endif

    }else{    //if we are exactly halfway, round to make lsb 0
        if((input & least_significant_bit_mask) == least_significant_bit_mask){ //lsb is currently 1
            //round up
            output &= (~mask); //make bits we are rounding 0
            output += least_significant_bit_mask; //increment lsb
            #if DEBUG
                printf("rounding up after tie\n");
            #endif

        }else{
            //round down
            output &= (~mask); //make all the bits we are rounding 0
            #if DEBUG
                printf("rounding down after tie\n");
            #endif

        }
    }
    return output;
}

uint16_t round_uint16 (uint16_t input, uint16_t bits_to_remove){ //takes the number to be rounded and the number of bits to remove from the right
    
    //this should really be a generic function since it does the same dang thing as uint8 but unfortunately c
    uint16_t mask = 0;
    uint16_t output = input;
    for (uint16_t i = 0; i < bits_to_remove; i++)
    {
        uint16_t temp_mask = 1;
        temp_mask <<= i;
        mask |= temp_mask;
    }
    uint16_t least_significant_bit_mask = 1;
    least_significant_bit_mask <<= bits_to_remove;
    
    if((input & mask) < (least_significant_bit_mask>>1)){ //if we are less than halfway 
        //round down
        output &= (~mask); //make all the bits we are rounding 0
        #if DEBUG
         printf("rounding down (no tie)\n");
        #endif

    }else if((input & mask)>(least_significant_bit_mask>>1)){     //if we are more than halfway 
        //round up
        output &= (~mask); //make bits we are rounding 0
        output += least_significant_bit_mask; //increment lsb
        #if DEBUG
        printf("rounding up (no tie)\n");
        #endif

    }else{    //if we are exactly halfway, round to make lsb 0
        if((input & least_significant_bit_mask) == least_significant_bit_mask){ //lsb is currently 1
            //round up
            output &= (~mask); //make bits we are rounding 0
            output += least_significant_bit_mask; //increment lsb
            #if DEBUG
            printf("rounding up after tie\n");
            #endif

        }else{
            //round down
            output &= (~mask); //make all the bits we are rounding 0
            #if DEBUG
            printf("rounding down after tie\n");
            #endif

        }
    }
    return output;
}

int8_t get_exponent(uint8_t input){
    uint8_t mask = EXPONENT_MASK;
    int8_t output = 0;
    output |= (mask & input) >>3;
    switch (get__encoding_type(input)){
    case normalized:
        output = output - BIAS; //transform encoding to exp
        break;
    case denormalized:
        output = 1 - BIAS;
        break;
    case special:
        //not sure yet
        break;
    default:
        break;
    }
    return output;
}

uint8_t get_significand(uint8_t input){
    uint8_t output = input & SIGNIFICAND_MASK;
    if(get__encoding_type(input) == normalized){ //add the leading 1 if it is normalized
        output += 8;
        #if DEBUG
            printf("significand normalized encoding %x\n", output);

    }else{
        printf("ignificand denormalized encoding %x\n", output);
        #endif
    }
    return output;
}

encoding_type get__encoding_type(uint8_t input)
{
    uint8_t mask = EXPONENT_MASK;

    if((input & mask) != 0){
        if(((input & mask) ^mask) == 0){
            return special;
        }
        return normalized;
    }

    return denormalized;
}

uint8_t tiny_add(uint8_t x, uint8_t y)
{
    uint8_t output = 0;
    //handle the special cases
    if(is_nan(x) || is_nan(y)){
        #if DEBUG
        printf("nan input detected. returning nan\n");
        #endif
        return NAN;
    }

    //if one is infinite
    if(is_infinity(x) || is_infinity(y)){
        if(is_infinity(x) && is_infinity(y)){ //both are infinity
            
            uint8_t mask = SIGN_MASK;
            if(((mask & x)^(mask & y)) != 0){ //they are diff. signs so they make NAN
                return NAN;
            }else{
                return x; //they share a sign and are both infinity ie: they are the same so just return one
            }
        }else{ //one is infinity and one is a normal number
            return x>y?x:y; //return the bigger one (the infinity)
        }
    
    }


    //hande exponents (choose the greatest)
    int8_t x_exponent = get_exponent(x); 
    int8_t y_exponent = get_exponent(y);
    int8_t largest_exponent = x_exponent > y_exponent? x_exponent: y_exponent; 
    uint8_t sum_exponent = 0;

    //put significands into uint16s 
    uint16_t x_significand = get_significand(x); 
    x_significand <<= 11;
    uint16_t y_significand = get_significand(y);
    y_significand <<=11;

    //move the smaller one right until it is aligned properly
    if(x_exponent > y_exponent){
        #if DEBUG
        printf("y significand smaller, shifted right %d bits.", (x_exponent - y_exponent));
        #endif
        y_significand >>= x_exponent - y_exponent;
        #if DEBUG
        printf(" %x\n", y_significand);
        #endif
    
    }else{
        #if DEBUG
        printf("x significand smaller, shifted right %d bits.",(y_exponent - x_exponent));
        #endif
        x_significand >>= y_exponent - x_exponent;
        #if DEBUG
        printf(" %x\n", x_significand);
        #endif
    }

    //add or subtract based on sign bits

    uint16_t sum_significand = 0;
    uint8_t sum_sign = 0; //1 if negative, 0 if positive
    uint8_t sign_mask = SIGN_MASK;

    if((x & sign_mask)^(y & sign_mask)){     //subtract the smaller from the larger if signs are diff
        if(x_significand>y_significand){
            #if DEBUG
            printf("subtracting x-y\n");
            #endif
            sum_significand = x_significand-y_significand;
            if(x&sign_mask){    //if larger one was negative, invert output
                sum_sign++;
            }
        }else{
            #if DEBUG
            printf("subtracting y-x\n");
            #endif
            sum_significand = y_significand-x_significand;
            if(y&sign_mask){
                sum_sign ++;
            }
        }
    }else{     //if signs are same add
        #if DEBUG
        printf("adding x+y\n");
        #endif
        sum_significand = x_significand + y_significand;
        if(x&sign_mask){     //if both were negative invert output (only check x here since we already know they share a sign)
            sum_sign++;
        }
    }
    #if DEBUG
    printf("significand after operation %x\n", sum_significand); 
    #endif

    //if there is a 1 in bit 16, increment exponent, left shift 1 bit then round to 3 bits (16, 15, 14)
    if(sum_significand >= 32768){
        #if DEBUG
        printf("exponent overflowed\n");
        #endif
        largest_exponent ++;
        sum_significand <<= 1;
        sum_significand = round_uint16(sum_significand, 13); 
        //we know that this will be normalized so we can round to just 3 bits and proceed
        sum_exponent = largest_exponent + BIAS;

    }else{     //if there is a 0 in bit 16, left shift. 
        #if DEBUG
        printf("exponent did not overflow\n");
        #endif
        sum_significand <<=1;
        while(sum_significand < 32768 && largest_exponent > -6){     //then, repeat the proces of left shifting if there is a 0 and decrementing until either exponent is -6 or there is a 1
            sum_significand <<=1;
            largest_exponent --;
            #if DEBUG
            printf("left shifting significand\n");
            #endif
        }
        if(sum_significand >= 32768){ //if we get the implied 1
            #if DEBUG
            printf("significand has normalized encoding %x\n", sum_significand);
            #endif
            sum_significand <<=1;
            sum_significand = round_uint16(sum_significand, 12);
            // if(largest_exponent == -6){
            //     largest_exponent++;
            // }
            sum_exponent = largest_exponent + BIAS;

        }else{ //we are in denormalized
            #if DEBUG
            printf("significand has denormalized encoding %x\n", sum_significand);
            #endif

            sum_significand <<=1;
            sum_significand = round_uint16(sum_significand, 12);
            sum_exponent = 0;
        }
    }

    #if DEBUG
    printf("final_significand %x\n", sum_significand);
    printf("final exponent: %x\n", sum_exponent);
    #endif
    //reassemble number
    output |= sum_sign<<7;
    output |= sum_exponent <<3;
    output |= sum_significand>>13;
    return output;
}
