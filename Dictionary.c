#include "Dictionary.h"
#include "Entry.h"
#include <stdlib.h>
#include <string.h>

void insert_dictionary(Dictionary *dictionary, void *key, int key_size, void *value, int value_size);
void *search_dictionary(Dictionary *dictionary, void *key);

Dictionary dictionary_constructor(int (*compare)(void *data_one, void *data_two))
{
    Dictionary dictionary;
    dictionary.binary_search_tree = binary_search_tree_constructor(compare);
    dictionary.insert = insert_dictionary;
    dictionary.search = search_dictionary;

    return dictionary;
}

void insert_dictionary(Dictionary *dictionary, void *key, int key_size, void *value, int value_size)
{
    Entry entry = entry_constructor(key, key_size, value, value_size);
    dictionary->binary_search_tree.insert(&dictionary->binary_search_tree, &entry, sizeof(Entry));
}

void *search_dictionary(Dictionary *dictionary, void *key)
{
    void *entry = dictionary->binary_search_tree.search(&dictionary->binary_search_tree, key);
    if (entry == NULL)
    {
        return NULL;
    }
    return ((Entry *)entry)->value;
}

int COMPARE_STR_KEYS(void *item_one, void *item_two)
{
    Entry *entry_one = (Entry *)item_one;
    char *entry_two = (char *)item_two;

    if (strcmp(entry_one->key, entry_two) == 0)
    {
        return 0;
    }
    else if (strcmp(entry_one->key, entry_two) > 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}