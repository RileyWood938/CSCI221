#include "find_divisor.h"
#include "fibonacci.h"
#include "moving.h"
#include "powers.h"
#include <stdlib.h>
#include <stdio.h>

int main (){

    printf("%d\n", powers(4534));

    printf("%c\n", moving(23523));

    unsigned int testing_array[5] = {2, 5, 7, 11, 10};

    pair divisors = find_divisor(testing_array, 5);
    printf("%d , %d\n", divisors.first, divisors.second);


    printf("%d\n", fibonacci(10));

}