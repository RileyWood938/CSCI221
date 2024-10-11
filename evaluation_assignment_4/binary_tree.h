#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdint.h>

typedef struct tree_nodes
{
    int32_t value;
    struct tree_nodes* left;
    struct tree_nodes* right;
} tree_node;

typedef struct binary_trees
{
    tree_node* root;
    int32_t size;
}binary_tree;

binary_tree* tree_create(); //returns a pointer to an empty binary tree

void tree_add(binary_tree* tree, int value); //addsa  value to the given binary tree

binary_tree* tree_from_array(int32_t array[], int32_t size); //creates a binary tree from the incoming array

int32_t tree_remove_value(binary_tree* tree, int32_t value); //removes a value from the given tree. returns the number of removed nodes

void tree_deallocate(binary_tree* tree); //deallocates a binary tree

void tree_node_deallocate_children(tree_node* node); //recursively deallocates a node and all its children

void replace_subnode(tree_node* replacee_parent_node, tree_node* replacee, tree_node* replacement); //redirects the parent node's pointer to the replacee to the replacement

tree_node* get_rightmost_subnode(tree_node* target); //returns a pointer to the rightmost subnode of the input
#endif