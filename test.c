#include "BinarySearchTree.h"
#include "Dictionary.h"
#include "Entry.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(void *data_one, void *data_two)
{
    Entry *entry_one = (Entry *)data_one;
    int *int_one = (int *)entry_one->key;
    int *int_two = (int *)data_two;

    if (*int_one < *int_two)
    {
        return 1;
    }
    else if (*int_one > *int_two)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    Dictionary dictionary = dictionary_constructor(compare);
    int *key = malloc(sizeof(int));
    *key = 1;
    int *value = malloc(sizeof(int));
    *value = 2;
    dictionary.insert(&dictionary, key, sizeof(int), value, sizeof(int));
    int *key2 = malloc(sizeof(int));
    *key2 = 2;
    int *value2 = malloc(sizeof(int));
    *value2 = 3;
    dictionary.insert(&dictionary, key2, sizeof(int), value2, sizeof(int));

    int *result = (int *)dictionary.search(&dictionary, key);

    return 0;
}