#include "Dictionary.h"
#include "BinarySearchTree.h"
#include "LinkedList.h"
#include "Entry.h"
#include <stdlib.h>
#include <string.h>

void insert_dictionary(Dictionary *dictionary, void *key, int key_size, void *value, int value_size);
void *search_dictionary(Dictionary *dictionary, void *key, int key_size);

Dictionary dictionary_constructor(int (*compare)(void *data_one, void *data_two))
{
    Dictionary dictionary;
    dictionary.binary_search_tree = binary_search_tree_constructor(compare);
    dictionary.keys = linked_list_constructor();
    dictionary.insert = insert_dictionary;
    dictionary.search = search_dictionary;

    return dictionary;
}

void insert_dictionary(Dictionary *dictionary, void *key, int key_size, void *value, int value_size)
{
    Entry entry = entry_constructor(key, key_size, value, value_size);
    dictionary->binary_search_tree.insert(&dictionary->binary_search_tree, &entry, sizeof(Entry));
    dictionary->keys.insert(dictionary->keys.length, key, key_size, &dictionary->keys);
}

void *search_dictionary(Dictionary *dictionary, void *key, int key_size)
{
    int dummy_value = 0;
    struct Entry searchable = entry_constructor(key, key_size, &dummy_value, sizeof(dummy_value));
    void *result = dictionary->binary_search_tree.search(&dictionary->binary_search_tree, &searchable);
    if (result == NULL)
    {
        return NULL;
    }
    return ((Entry *)result)->value;
}

int COMPARE_STR_KEYS(void *entry_one, void *entry_two)
{
    if (strcmp((char *)(((struct Entry *)entry_one)->key), (char *)(((struct Entry *)entry_two)->key)) > 0)
    {
        return 1;
    }
    else if (strcmp((char *)(((struct Entry *)entry_one)->key), (char *)(((struct Entry *)entry_two)->key)) < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}