#include "binary_tree.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    binary_tree* tree = tree_create();
    if(!tree){
        return 1;
    }

    tree_add(tree, 1); //its not easy to display these trees so I am using gdb to check test cases are working correctly
    tree_add(tree, 5);
    tree_add(tree, 5);

    tree_add(tree, 2);
    tree_add(tree, 7);
    tree_add(tree, 0);

    int32_t array[] = {9, 11, 13};
    binary_tree* tree_2 = tree_from_array(array, 3);
    tree_remove_value(tree_2, 9);
    tree_remove_value(tree_2, 11);
    tree_remove_value(tree_2, 13);

    tree_add(tree_2, 100);

    tree_deallocate(tree_2);
    if(tree_2){
        printf("tree\n");
    }
}