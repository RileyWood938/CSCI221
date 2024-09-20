#include "find_divisor.h"
#include <stdlib.h>
#include <stdio.h>

int main (){
    int testing_array[] = {2, 5, 7, 11, 10};
    pair divisors = find_divisor(testing_array, 5);
    printf("%d , %d\n", divisors.first, divisors.second);
}