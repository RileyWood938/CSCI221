#include "floats.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    printf("0:");
    printf("%d\n", get__encoding_type(0.0f));
    
    printf("big number:");
    printf("%d\n", get__encoding_type(398475823.0f));
    
    printf("small number:");
    printf("%d\n", get__encoding_type(0.375));
        
    printf("infinity:");
    printf("%d\n", get__encoding_type(INFINITY));

}