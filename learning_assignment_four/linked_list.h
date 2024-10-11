#ifndef LINKED_LIST_H
#define LINKED_LIST_H
 
typedef struct nodes
{
    int value;
    struct nodes* next; //need to use "struct" here as the type definition does not occur until after this line.
} node ;


typedef struct linked_lists
{
    node* head;
    int length;
} linked_list;

void linked_list_add (linked_list* list, int value); //adds value to end of the list.

linked_list* linked_list_create(int value, int length); //creates a linked list containing length copies of the value "value". Returns a pointer to the new list.

int linked_list_remove_by_value(linked_list* list, int value); //removes all instances of given value from a linked list. Returns the number of items removed from the list.

void linked_list_deallocate(linked_list* list ); //deallocates the given list.

#endif