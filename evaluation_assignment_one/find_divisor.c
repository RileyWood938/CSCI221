#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    //since this returns an array I am using the approach where memory is allocated by the function but must be deallocated by the caller
    int* find_divisors(int in[], int in_size){
        int* output = malloc(2 * sizeof(int)); //allocate up some memory for the output. This was confusing and I needed lots of googling to figure it out
       
       
        for(int i=0; i<in_size; i++){ //pretty simple double loop to get divisors. there might be a faster way to do this.
            for(int j=0; j<in_size; j++){
                if(i==j)
                    continue;
                
                if(in[i]%in[j]==0){
                    output[0] = in[i];
                    output[1] = in[j];
                    return output;
                }
            }
        }
        output[0] = 0;
        output[1] = 0;
        return output;
    }

    int test_divisor_one[4] = {2, 7, 19, 16};
    int* divisors = find_divisors(test_divisor_one, 4);
    printf("Divisors are: %d %d", divisors[0], divisors[1]);
}