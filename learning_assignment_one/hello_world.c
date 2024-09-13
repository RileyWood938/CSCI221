 #include <stdio.h>
 #include <stdlib.h>
 //standard IO includes

#define array_size 2024

typedef enum roles{
    student = 0,
    instructor,
    teaching_assistant, 
    observer
    //numbers uptick automatically
} role;

typedef union grades{
    char letter_grade[2];
    int percentage_grade;
} grade;

typedef struct class_members{
    int reed_id;
    role role_in_class;
    grade grade_in_class;
} class_member;


 int main (int argc, char *argv[]) {
    //main function is entry point. args represents potential inputs from command line running code

    printf("Hello World!");
    //print output

    int test_array[array_size];


    //for(int i=0; i<sizeof(testArray)/4; i++){
    //for(int i=0; i<sizeof(test_array)/sizeof(test_array[0]); i++){
            //better form here is to use the element size rather than a hard coded value
    for(int i=0; i<array_size; i++){
        // sounds like its better to track the size myself
        test_array[i] = 0;
    }

    return 0;
    //end program with success code
 }