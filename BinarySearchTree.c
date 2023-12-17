#include "BinarySearchTree.h"
#include "Node.h"
#include <stdlib.h>

Node *iterate_binary_tree(BinarySearchTree *tree, Node *cursor, void *data, int *direction, Node **prev_cursor);
Node *create_node_binary_tree(void *data, int size);
void destroy_node_binary_tree(Node *node);
void *search_binary_tree(BinarySearchTree *tree, void *data);
void insert_binary_tree(BinarySearchTree *tree, void *data, int size);
void remove_node_binary_tree(BinarySearchTree *tree, void *data);
void destroy_tree(Node *node);

BinarySearchTree binary_search_tree_constructor(int (*compare)(void *data1, void *data2))
{
    BinarySearchTree binary_search_tree;
    binary_search_tree.root = NULL;
    binary_search_tree.compare = compare;
    binary_search_tree.search = search_binary_tree;
    binary_search_tree.insert = insert_binary_tree;
    binary_search_tree.remove = remove_node_binary_tree;
    binary_search_tree.destroy = destroy_tree;

    return binary_search_tree;
}

Node *create_node_binary_tree(void *data, int size)
{
    Node *node = (Node *)malloc(sizeof(Node));
    *node = node_constructor(data, size);

    return node;
}

void destroy_node_binary_tree(Node *node)
{
    node_destructor(node);
}

void destroy_tree(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    destroy_tree(node->next);
    destroy_tree(node->prev);
    destroy_node_binary_tree(node);
}

Node *iterate_binary_tree(BinarySearchTree *tree, Node *cursor, void *data, int *direction, Node **prev_cursor)
{
    if (cursor == NULL || tree->root == NULL)
    {
        return NULL;
    }

    int comparison = tree->compare(cursor->data, data);

    if (comparison == 1)
    {
        if (cursor->next != NULL)
        {
            if (prev_cursor != NULL)
            {
                *prev_cursor = cursor;
            }
            return iterate_binary_tree(tree, cursor->next, data, direction, prev_cursor);
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
            if (prev_cursor != NULL)
            {
                *prev_cursor = cursor;
            }
            return iterate_binary_tree(tree, cursor->prev, data, direction, prev_cursor);
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

void *search_binary_tree(BinarySearchTree *tree, void *data)
{
    int direction = 0;
    Node *cursor = iterate_binary_tree(tree, tree->root, data, &direction, NULL);

    if (direction == 0 && cursor != NULL)
    {
        return cursor->data;
    }
    else
    {
        return NULL;
    }
}

void insert_binary_tree(BinarySearchTree *tree, void *data, int size)
{
    int direction = 0;
    Node *cursor = iterate_binary_tree(tree, tree->root, data, &direction, NULL);

    if (!tree->root)
    {
        Node *new_node = create_node_binary_tree(data, size);
        tree->root = new_node;
    }
    else
    {
        Node *new_node = create_node_binary_tree(data, size);

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

void remove_node_binary_tree(BinarySearchTree *tree, void *data)
{
    int direction = 0;
    Node *prev_cursor = NULL;
    Node *cursor = iterate_binary_tree(tree, tree->root, data, &direction, &prev_cursor);
    Node *prev_node = prev_cursor;
    if (direction == 0)
    {
        if (prev_cursor == NULL)
        {
            tree->root = NULL;
            destroy_node_binary_tree(cursor);
        }
        else if (cursor->next == NULL && cursor->prev == NULL)
        {
            if (prev_node->data < cursor->data)
            {
                prev_node->next = NULL;
            }
            else
            {
                prev_node->prev = NULL;
            }
            destroy_node_binary_tree(cursor);
        }
        else if (cursor->next == NULL)
        {

            if (cursor->prev > prev_node->next)
            {
                prev_node->next = cursor->prev;
            }
            else
            {
                prev_node->prev = cursor->prev;
            }
            destroy_node_binary_tree(cursor);
        }
        else if (cursor->prev == NULL)
        {
            Node *prev_node = prev_cursor;
            if (cursor->next > prev_node->next)
            {
                prev_node->next = cursor->next;
            }
            else
            {
                prev_node->prev = cursor->next;
            }
            destroy_node_binary_tree(cursor);
        }
        else
        {
            Node *prev_node = prev_cursor;
            prev_node->next = cursor->next;
            cursor->next->prev = cursor->prev;
            destroy_node_binary_tree(cursor);
        }
    }
}