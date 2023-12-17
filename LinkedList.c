#include "LinkedList.h"
#include "Node.h"
#include <stdio.h>

Node *create_node_linked_list(void *data, int size);
void destroy_node_linked_list(Node *node);
Node *iterate_linked_list(int index, LinkedList *linked_list);

void insert_node(int index, void *data, int size, LinkedList *linked_list);
int remove_node_linked_list(int index, LinkedList *linked_list);
void *retrieve_data(int index, LinkedList *linked_list);

LinkedList linked_list_constructor()
{
    LinkedList linked_list;
    linked_list.head = NULL;
    linked_list.length = 0;
    linked_list.insert = insert_node;
    linked_list.remove = remove_node_linked_list;
    linked_list.retrieve = retrieve_data;

    return linked_list;
}

Node *create_node_linked_list(void *data, int size)
{
    Node *node = (Node *)malloc(sizeof(Node));
    *node = node_constructor(data, size);

    return node;
}

void destroy_node_linked_list(Node *node)
{
    node_destructor(node);
}

Node *iterate_linked_list(int index, LinkedList *linked_list)
{
    if (index < 0 || index >= linked_list->length)
    {
        exit(9);
    }

    Node *node = linked_list->head;

    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }

    return node;
}

void insert_node(int index, void *data, int size, LinkedList *linked_list)
{
    if (index < 0 || index > linked_list->length)
    {
        exit(9);
    }

    Node *new_node = create_node_linked_list(data, size);

    if (index == 0)
    {
        new_node->next = linked_list->head;
        linked_list->head = new_node;
    }
    else
    {
        Node *prev_node = iterate_linked_list(index - 1, linked_list);
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }

    linked_list->length++;
}

int remove_node_linked_list(int index, LinkedList *linked_list)
{
    if (index < 0 || index >= linked_list->length)
    {
        return 0;
    }

    Node *node_to_remove;

    if (index == 0)
    {
        node_to_remove = linked_list->head;
        linked_list->head = node_to_remove->next;
    }
    else
    {
        Node *prev_node = iterate_linked_list(index - 1, linked_list);
        node_to_remove = prev_node->next;
        prev_node->next = node_to_remove->next;
    }

    destroy_node_linked_list(node_to_remove);
    linked_list->length--;
    return 1;
}

void *retrieve_data(int index, LinkedList *linked_list)
{
    if (index < 0 || index >= linked_list->length)
    {
        return NULL;
    }
    Node *node = iterate_linked_list(index, linked_list);
    return node->data;
}
