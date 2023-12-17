#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "BinarySearchTree.h"
#include "LinkedList.h"

typedef struct Dictionary
{
    BinarySearchTree binary_search_tree;
    LinkedList keys;
    void (*insert)(struct Dictionary *dictionary, void *key, int key_size, void *value, int value_size);
    void *(*search)(struct Dictionary *dictionary, void *key, int key_size);
} Dictionary;

Dictionary dictionary_constructor(int (*compare)(void *key1, void *key2));
Dictionary dictionary_destructor(Dictionary *dictionary);
int COMPARE_STR_KEYS(void *item_one, void *item_two);

#endif // DICTIONARY_H