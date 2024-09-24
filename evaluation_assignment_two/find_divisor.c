#include "find_divisor.h"

pair make_pair (unsigned int x, unsigned int y){
    pair output;
    output.first = x;
    output.second = y;
    return output;
}

pair find_divisor(unsigned int input[], unsigned int input_size){
            for(unsigned int i=0; i<input_size; i++){ //pretty simple double loop to get divisors. There might be a faster way to do this.
                for(unsigned int j=0; j<input_size; j++){
                    if(i==j) //ignore duplicates
                        continue;
                    if(input[i]%input[j]==0){ //does j divide i?
                        return make_pair(input[j], input[i]);
                    }
                }
            }
        return make_pair(0,0);
}
