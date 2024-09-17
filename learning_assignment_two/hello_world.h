 #ifndef HELLO_WORLD_H
 #define HELLO_WORLD_H
 

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

#endif
 