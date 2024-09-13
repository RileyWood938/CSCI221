#include <stdio.h>
#include <stdlib.h>


int main (int argc, char* argv[]){
    if(2>argc)
        return 1;
    //ensure that an input number has been given 

    int input = atoi(argv[1]); //turn input into an integer

    if(1>input){
        return 1;
    }else if(2>input){ //I feel like my loop should be able to handle the case n=1 but I couldn't quite get it working
        printf("1\n");
        return 0;
    }

    int current_num = 1;
    int last_num = 0;
    for(int i=0; i<input-1; i++){ //input reduced by one to account for the n=1 case being handled outside the loop
        int extra_num = last_num;
        last_num = current_num;
        current_num += extra_num;
    }

    printf("%d\n", current_num);
    return 0;
    
}

