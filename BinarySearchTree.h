#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "Node.h"

typedef struct BinarySearchTree
{
    Node *root;
    int (*compare)(void *data_one, void *data_two);
    void *(*search)(struct BinarySearchTree *tree, void *data);
    void (*insert)(struct BinarySearchTree *tree, void *data, int size);
    void (*remove)(struct BinarySearchTree *tree, void *data);
} BinarySearchTree;

BinarySearchTree binary_search_tree_constructor(int (*compare)(void *data_one, void *data_two));

#endif