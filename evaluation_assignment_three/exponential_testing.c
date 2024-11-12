#include "exponentials.h"
#include <stdlib.h>
#include <stdio.h>

int main(){

    printf("%d = 8\n", exponentiate(2, 3));

    printf("%d = 128\n", exponentiate(2, 7));

    printf("%d = 32768\n", exponentiate(2, 15));
    
    printf("%d = 4096\n", exponentiate(2, 12));

    printf("%d = 256\n", exponentiate(2, 8));

    printf("%d = 1\n", exponentiate(5, 0));

    printf("%d = 390625\n", exponentiate(5, 8));

    printf("%d = 16677181699666569\n", exponentiate(3, 34));

    printf("%d = 1\n", exponentiate(1, 12));

    printf("%d = 0\n", exponentiate(0,5));

    printf("%d = 3125\n", exponentiate(5,5));



}