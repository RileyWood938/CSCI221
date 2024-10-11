#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>


void print_list(linked_list* list){ //testing function to print a linked list's contents. 
    node* current_node = list->head;

    for (int i = 0; i < list->length; i++)
    {
        printf("%d  ", current_node->value);
        current_node = current_node->next;
    }
    printf(";  ");
    
}
int main(){

    linked_list* list = linked_list_create(4, 3); //test normal creation of list
    linked_list_add(list, 8); //normal use case of add
    linked_list_add(list, 3);
    linked_list_add(list, 4);
    print_list(list);
    linked_list_remove_by_value(list, 8); //test normal removal of elements
    print_list(list);
    linked_list_remove_by_value (list, 4); //test removal of starting and terminal elements
    print_list(list);
    linked_list_deallocate(list); //test list deallocation

    list = linked_list_create(1, 1); //test creation of single-item list
    print_list(list);
    linked_list_remove_by_value(list, 9);//test removing value not present in list
    print_list(list);
    linked_list_remove_by_value(list, 1); //test removing only element in list
    print_list(list);
    linked_list_add(list, 1); //test adding to empty list
    print_list(list);
    linked_list_deallocate(list); //test deallocating
}

