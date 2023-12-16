#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdlib.h>
#include "Node.h"

struct LinkedList
{
    struct Node *head;
    int length;

    void (*insert)(int index, void *data, struct LinkedList *linked_list);
    int (*remove)(int index, struct LinkedList *linked_list);
    void *(*retrieve)(int index, struct LinkedList *linked_list);
};

struct LinkedList linked_list_constructor();

#endif