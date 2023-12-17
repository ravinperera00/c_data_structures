#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdlib.h>
#include "Node.h"

typedef struct LinkedList
{
    Node *head;
    int length;

    void (*insert)(int index, void *data, int size, struct LinkedList *linked_list);
    int (*remove)(int index, struct LinkedList *linked_list);
    void *(*retrieve)(int index, struct LinkedList *linked_list);
} LinkedList;

LinkedList linked_list_constructor();
void linked_list_destructor(LinkedList *linked_list);

#endif