#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "BinarySearchTree.h"

typedef struct Dictionary{
    BinarySearchTree binary_search_tree;
    void (*insert)(struct Dictionary* dictionary, void* key, int key_size, void* value, int value_size);
    void* (*search)(struct Dictionary* dictionary, void* key);
}Dictionary;

Dictionary dictionary_constructor(int (*compare)(void* key1, void* key2));
Dictionary dictionary_destructor(Dictionary *dictionary);

#endif // DICTIONARY_H