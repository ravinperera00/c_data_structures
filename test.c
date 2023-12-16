#include "BinarySearchTree.h"
#include "Dictionary.h"
#include "Entry.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    Dictionary dictionary = dictionary_constructor(COMPARE_STR_KEYS);
    char *key = "Key1";
    int *value = malloc(sizeof(int));
    *value = 2;
    dictionary.insert(&dictionary, key, sizeof(int), value, sizeof(int));
    char *key2 = "Key2";
    int *value2 = malloc(sizeof(int));
    *value2 = 3;
    dictionary.insert(&dictionary, key2, sizeof(int), value2, sizeof(int));

    int *result = (int *)dictionary.search(&dictionary, key);

    return 0;
}