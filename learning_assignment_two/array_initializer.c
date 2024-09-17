/* Create a new C file that implements the initialization function. The initialization func
tion should take an array, its size, and a value as input parameters, and set each element of the
 array to that value. You should also create an associated header and separate the interface and the
 implementation as we discussed in class. Make sure to properly guard your header le.*/

 void initialize_int_array ( int array[], int array_size, int value){
    for (int i=0; i<array_size; i++){
        array[i] = value;
    }
    return;
 }