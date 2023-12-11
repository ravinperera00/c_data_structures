#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdlib.h>
#include "Node.h"

struct LinkedList
{
    struct Node_int *head;
    int length;

    void (*insert)(int index, int data, struct LinkedList *linked_list);
    void (*remove)(int index, struct LinkedList *linked_list);
    int (*retrieve)(int index, struct LinkedList *linked_list);
};

struct LinkedList linked_list_int_constructor();

#endif