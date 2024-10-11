#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

binary_tree*  tree_create(){
    binary_tree* tree = malloc(sizeof(binary_tree));
    if(!tree){
        return NULL;
    }
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

binary_tree *tree_from_array(int32_t array[], int32_t size)
{
    if(!array){
        return NULL;
    }
    binary_tree* tree = malloc(sizeof(binary_tree));
    if(!tree){
        return NULL;
    }
    tree->root = NULL;
    tree->size  =0;

    for (int32_t i = 0; i < size; i++)
    {
        tree_add(tree, array[i]);
    }
    return tree;
}

int32_t tree_remove_value(binary_tree *tree, int32_t value)
{

    if(!tree){
        return NULL;
    }
    //step one: navigate to the relevent node
    tree_node* current_node = tree->root;
    tree_node* last_node = NULL;

    if(!current_node){ //the tree has no elements
        return 0;
    }

    while (1)
    {
        if(value == current_node->value){ //We are at the correct node 
            break;
        } else if(value > current_node->value){ //value we want is greater than current node
            if(current_node->right){ //move right
                last_node = current_node;
                current_node = current_node->right;
            }else{ //if there is no node right of the one we want, and the one we want larger than the one we have, the value we are looking for must be outside the tree
                return 0;
            }
        }else{ //value we want is less than current node
            if(current_node->left){ //move left
                last_node = current_node;
                current_node = current_node->left;
            }else{
                return 0;
            }
        }
    }

    //step two: bypass node via pointers 

    if(!last_node){ //handle removal of the root node

        tree_node* replacement = NULL;

        if(current_node->left){ //if there is a left node
            replacement = current_node->left;
            tree->root = replacement;
            get_rightmost_subnode(replacement)->right = current_node->right; //attach to the right hand side

        }else{
            replacement = current_node->right;
            tree->root = replacement;   
        }
            

    }else{ //all other cases
        tree_node* replacement = NULL;

        if(current_node->left){ //if there is a left node
            replacement = current_node->left;

            replace_subnode(last_node, current_node, replacement);

            get_rightmost_subnode (replacement)->right = current_node->right; //attach the removed node's right hand side


        }else if(current_node->right){ //if there is a right node and no left node
            replacement = current_node->right;
            replace_subnode(last_node, current_node, replacement);


        }else{ //there are no nodes beneath the current one

            replace_subnode(last_node, current_node, NULL);
            
        }
    }     
    

    //step three: deallocate node
    free(current_node);
    tree->size --;
    return 1;

}

void tree_deallocate(binary_tree *tree) //I much prefer the version of this that takes binary_tree** as input so it can nullify the pointer. The problem description called for binary_tree* though.
{
    if(!tree){
        return;
    }
    if(tree->root){
        tree_node_deallocate_children(tree->root);
    }
    free(tree);
    return;
}

void tree_node_deallocate_children(tree_node* node){ 
    if(!node){
        return;
    }
    if(node->left){
        tree_node_deallocate_children(node->left);
    }
    if (node->right){
        tree_node_deallocate_children(node->right);
    }
    free(node);
    return;   
}

void replace_subnode(tree_node* replacee_parent_node, tree_node* replacee, tree_node* replacement){ //redirects the parent node's pointer to the replacee to the replacement
    if (replacee_parent_node->right == replacee){
        replacee_parent_node->right = replacement;
    }
    else if (replacee_parent_node->left == replacee){
        replacee_parent_node->left = replacement;
    }
}

tree_node* get_rightmost_subnode(tree_node* target){ //returns a pointer to the rightmost subnode of the input
    tree_node* output = target;
            while(output->right){ //traverse all the way down replacement's right side
                output = output->right;
            }
    return output;
}

void tree_add(binary_tree *tree, int32_t value)
{
    if(!tree){
        return;
    }
    tree_node* current_node = tree->root;

    tree_node* new_node = malloc(sizeof(tree_node)); //handle bad malloc call
    if(!new_node){
        return;
    }

    new_node->value = value; //initialize new node
    new_node->left = NULL;
    new_node->right = NULL;


    if(!current_node){ //the tree has no elements
        tree->root = new_node;
        tree->size = 1;
        return;
    }
    while (current_node)
    {
        if(value == current_node->value){
            return;
        } else if(value > current_node->value){ //new value is greater than current node
            if(current_node->right){
                current_node = current_node->right;
            }else{
                current_node->right = new_node; 
                break;   
  
            }
        }else{ //new value is less than current node
            if(current_node->left){
                current_node = current_node->left;
            }else{
                current_node->left = new_node;
                break;   
            }
        }
    }
    
    tree->size ++;
    
}