#include "BinarySearchTree.h"
#include "Node.h"
#include <stdlib.h>

Node *create_node(void *data, int size);
void destroy_node(Node *node);
Node *iterate(BinarySearchTree *tree, Node *cursor, void *data, int *direction);
void *search(BinarySearchTree *tree, void *data);
void insert(BinarySearchTree *tree, void *data, int size);

BinarySearchTree binary_search_tree_constructor(int (*compare)(void *data1, void *data2))
{
    BinarySearchTree binary_search_tree;
    binary_search_tree.root = NULL;
    binary_search_tree.compare = compare;
    binary_search_tree.search = search;
    binary_search_tree.insert = insert;

    return binary_search_tree;
}

Node *create_node(void *data, int size)
{
    Node *node = (Node *)malloc(sizeof(Node));
    *node = node_constructor(data, size);

    return node;
}

void destroy_node(Node *node)
{
    node_destructor(node);
}

Node *iterate(BinarySearchTree *tree, Node *cursor, void *data, int *direction)
{
    if (cursor == NULL)
    {
        return NULL;
    }

    int comparison = tree->compare(cursor->data, data);

    if (comparison == 1)
    {
        if (cursor->next != NULL)
        {
            return iterate(tree, cursor->next, data, direction);
        }
        else
        {
            *direction = 1;
            return cursor;
        }
    }
    else if (comparison == -1)
    {
        if (cursor->prev != NULL)
        {
            return iterate(tree, cursor->prev, data, direction);
        }
        else
        {
            *direction = -1;
            return cursor;
        }
    }
    else
    {
        *direction = 0;
        return cursor;
    }
}

void *search(BinarySearchTree *tree, void *data)
{
    int direction = 0;
    Node *cursor = iterate(tree, tree->root, data, &direction);

    if (direction == 0)
    {
        return cursor->data;
    }
    else
    {
        return NULL;
    }
}

void insert(BinarySearchTree *tree, void *data, int size)
{
    int direction = 0;
    Node *cursor = iterate(tree, tree->root, data, &direction);

    if (direction == 0)
    {
        cursor->data = data;
    }
    else
    {
        Node *new_node = create_node(data, size);

        if (direction == 1)
        {
            cursor->next = new_node;
        }
        else
        {
            cursor->prev = new_node;
        }
    }
}