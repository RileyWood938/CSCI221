#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void linked_list_add(linked_list *list, int value)
{
    node* new_node = malloc(sizeof(node));
    if(!new_node)
        return;
    new_node->next = NULL; //sets pointer of new last node to NULL
    new_node->value = value;

    if (list->length == 0)
    {
        list->head = new_node;
    }
    else
    {
        node *last_node = list->head;
        while (last_node->next)
        {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }

    list->length++;
}

linked_list *linked_list_create(int value, int length)
{
    if(length<1){return NULL;} //make sure input is in bounds

    linked_list* new_list = malloc(sizeof(linked_list)); 
    node* head = malloc(sizeof(node));

    if(!new_list|| !head) {return NULL;} //ensure malloc has succeeded

    new_list->length = 1; 
    new_list->head = head;
    head->value = value;

    if (length > 1) //add the second node
    {
        node *new_node = malloc(sizeof(node));
        if (!new_node ){return NULL;}

        new_node->value = value;
        head->next = new_node;
        new_list->length++;

        for(int i=2; i<length; i++){
            linked_list_add(new_list, value);
        }
    }
    return new_list;
}

int linked_list_remove_by_value(linked_list *list, int value)
{
    node* current_node = list->head;
    node* last_node = NULL;
    int counter = 0;
    
    
    while (current_node->next){ //loop through all but the last node of the list
        if(current_node->value == value){ 
            if(current_node == list->head){ //handle the case where the first node is of the value
                list->head = current_node->next;
                free(current_node);
                current_node = list->head;
                counter ++;
                continue;
            }else{
                node* next_node = current_node->next;
                free(current_node);
                current_node = next_node;
                last_node->next = next_node;
                counter++;
            }
        }
        last_node = current_node;
        current_node = current_node->next;

    } 
    if(current_node->value == value){ //handle the final node
        if(!last_node){ //if this is the only node in the list, next_node will never have been set
            list->head = NULL;
        }else{ //there is a node before this in the list
            last_node->next = NULL;
        }
        free(current_node);
        counter++;
    }
    list->length -= counter;
    return counter;


}

void linked_list_deallocate(linked_list *list)
{
    node* current_node = list->head;

    for (int i=1; i<list->length; i++){
        node* next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    free(current_node);
    free(list);
    return;

}
