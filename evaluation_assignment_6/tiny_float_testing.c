#include "tiny_float.h"
#include <stdint.h>
#include <stdio.h>
//#define ADD_DEBUG 1
//#define MULT_DEBUG 1

int main (){
    #if MULT_DEBUG
    //normal case (1.5 * 1.5) = 2.25
    uint8_t x = 60; //  0 0111 100  3c    1.100     1.5
    uint8_t y = 60; //  0 0111 100  3c    1.100     1.5
    uint8_t prod = tiny_mult(x, y);
    printf("41 = %x\n", prod); //0 1000 001 10.01 2.25 0x41

    //negative positive case (2.25 * -0.5) = -1.125
    x = 65; //0 1000 001 2.25
    y = 176; // 1 0110 000 -.5
    prod = tiny_mult(x, y);
    printf("b9 = %x\n", prod); //1 0111 001 0xb9

    //double negative case (-2.25 * -0.5) = 1.125
    x = 65; //0 1000 001 2.25
    y = 48; // 0 0110 000 -.5
    prod = tiny_mult(x, y);
    printf("39 = %x\n", prod); //0 0111 001 0x39

    //normalized * denormalized case
    x = 4;//0 0000 100      (0.5 * 2^-6)    0.0000001 1/128
    y = 64;//0 1000 000     (1.0 * 2^1)     2.0
    prod = tiny_mult (x, y);
    printf("14 = %x\n", prod); // 0 0010 000 1.0 * 2^-4  0 0010 100 0x 14

    //test rounding routine
    x = 59 ;//0b00111011; // 1 3/8
    y = 58; //0b00111010; // 1 2/8
    prod = tiny_mult (x, y);
    printf("3e = %x\n", prod); // 0 0111 110 0x3e

    //multiply by 0
    x = 0;
    y = 56; //0 0111 000
    prod = tiny_mult(x,y);
    printf("0 = %x\n", prod);

    // underflow
    x = 8;//0 0001 000      (1 * 2^-6)    0.0000001 1/128
    y = 48;//0 0110 000      (1 * 2^-1)    0.0000001 1/128
    prod = tiny_mult (x, y);
    printf("4 = %x\n", prod); // 0 0000 100

    // underflow
    x = 8;//0 0001 000      (1 * 2^-6)    0.0000001 1/128
    y = 40;//0 0101 000      (1 * 2^-2)    0.0000001 1/128
    prod = tiny_mult (x, y);
    printf("2 = %x\n", prod); // 0 0000 010

    // underflow
    x = 8;//0 0001 000      (1 * 2^-6)    0.0000001 1/128
    y = 32;//0 0100 000      (1 * 2^-3)    0.0000001 1/128
    prod = tiny_mult (x, y);
    printf("1 = %x\n", prod); // 0 0000 001
    // underflow
    x = 8;//0 0001 000      (1 * 2^-6)    0.0000001 1/128
    y = 24;//0 0011 000      (1 * 2^-4)    0.0000001 1/128
    prod = tiny_mult (x, y);
    printf("0 = %x\n", prod); // 0 0000 000

    //normalized * normalized with overflow
    x = 112;//0 1110 000 1*2^7
    y = 112;//0 1110 000 1*2^7
    prod = tiny_mult(x,y);
    printf("78 = %x\n", prod); // infinity


    // infinity times 1;
    x = 120; //0 1111 000
    y = 56;
    prod = tiny_mult(x, y);
    printf("78 = %x\n", prod);
#endif
#if ADD_DEBUG
    //time to test adding
    //normal case (1.5 + 1.5) = 3
    x = 60; //  0 0111 100  3c    1.100     1.5
    y = 60; //  0 0111 100  3c    1.100     1.5
    uint8_t sum = tiny_add(x, y);
    printf("44 = %x\n", sum); // 0 1000 100  1.5*2^(8-7) = 3  0x 44

    //test 0
    x = 0; //  0
    y = 60; //  0 0111 100  3c    1.100     1.5
    sum = tiny_add(x, y);
    printf("3c = %x\n", sum); // outputs 3c

    //test 0 + 0
    x = 0; //  0
    y = 0; //  0
    sum = tiny_add(x, y);
    printf("0 = %x\n", sum); // outputs 0

    //test normalized + denormalized
    x = 4;//0 0000 100      (0.5 * 2^-6)    0.0000001 1/128
    y = 64;//0 1000 000     (1.0 * 2^1)     2.0
    sum = tiny_add(x, y);
    printf("40 = %x\n", sum); // 0 1000 0000  1*2^1 = 2 0x40

    //test denormalized + denormalized
    x = 4;//0 0000 100      (0.5 * 2^-6)    0.0000001 1/128
    y = 4;//0 0000 100     
    sum = tiny_add(x, y);
    printf("8 = %x\n", sum); // 0 0010 000 = 1*2^-6 = 2/128 0x8

    //test overflow
    x = 112;//0 1110 000      (0.5 * 2^-6)    0.0000001 1/128
    y = 112;//0 1110 000     (1.0 * 2^1)     2.0
    sum = tiny_add(x, y);
    printf("78 = %x\n", sum); // 0 1111 000 infinity 0x78

    //test subtraction 1.5-1.5
    x = 60;//1.5
    y = 188;//-1.5
    sum = tiny_add(x, y);
    printf("80 = %x\n", sum); //1 0000 000 0 //80

    //test subtraction 1 - 1.5
    x = 56;//1
    y = 188;//-1.5
    sum = tiny_add(x, y);
    printf("b0 = %x\n", sum); //1 0110 000 -1*1*2^-1 = -0.5  0xb0

    //test subtraction 2 -1.5
    x = 64;//0 1000 000     (1.0 * 2^1)     2.0
    y = 188;//-1.5  1 0111 100 (-1*1.5*2^0) -1.5
    sum = tiny_add(x, y);
    printf("30 = %x\n", sum); // 0 0110 000  (1*2^-1) = .5  0x30

    //test double negative -1.5 - 1.5
    x= 188; //-1.5  1 0111 100 (-1*1.5*2^0) -1.5
    y = 188;//-1.5  1 0111 100 (-1*1.5*2^0) -1.5
    sum = tiny_add(x,y);
    printf("c4 = %x\n", sum); //1 1000 100   (-1*2^1*1.5)  -3 0xc4

    // infinity + 1;
    x = 120; //0 1111 000
    y = 56; //0 0111 000
    sum = tiny_add(x, y);
    printf(" 78 = %x\n", sum); // 0x 78

    //infinity - infinity;
    x = 120; //0 1111 000
    y = 248; //1 1111 000
    sum = tiny_add(x, y);
    printf("  = %x\n", sum); // 0x 78
#endif
    }