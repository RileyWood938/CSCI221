#include "numbers.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    
    int16_t a = negate(1);
    printf("original: %d\n", 1);
    printf("negation: %d\n", a);
    a = negate(INT16_MAX);
    printf("original: %d\n", INT16_MAX);
    printf("negation: %d\n", a);
    a = negate(0);
        printf("original: %d\n", 0);

    printf("negation: %d\n", a);
    a = negate(INT16_MIN);
    printf("original: %d\n", INT16_MIN);
        printf("negation: %d\n", a);

    printf("============\n");


    printf("conditionals:\n%d\n", conditional(0, 1345, 350)); //test case where x=0
    printf("%d\n", conditional(INT32_MIN, INT32_MIN, INT32_MAX)); //test edge cases
    printf("%d\n", conditional(INT32_MAX, INT32_MAX, INT32_MIN));
    printf("%d\n", conditional(-10000, -145, -4530)); //test negative x
    printf("%d\n", conditional(1, 145, 340)); //test normal use of x
    printf("============\n");
    printf("addition: \n");
    printf("diff signs: %ld\n", my_add(INT32_MAX,INT32_MIN));


    printf("both positive: %ld\n",   my_add(12, 11));
    printf("both negative: %ld\n",   my_add(-12, -11));

    printf("overflow: %ld\n",  my_add(INT32_MAX,1));
        printf("overflow: %ld\n",  my_add(INT32_MAX,INT32_MAX));
    printf("underflow %ld\n", my_add(INT32_MIN,INT32_MIN));
    printf("underflow %ld\n", my_add(INT32_MIN,-1));
    

    printf("0 + int min: %ld\n", my_add(0,INT32_MIN));
    printf("0 + int max: %ld\n",  my_add(0,INT32_MAX));



}