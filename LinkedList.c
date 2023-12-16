#include "LinkedList.h"
#include <stdio.h>

struct Node *create_node(void *data);
void destroy_node(struct Node *node);
struct Node *iterate(int index, struct LinkedList *linked_list);

void insert_node(int index, void *data, struct LinkedList *linked_list);
int remove_node(int index, struct LinkedList *linked_list);
void *retrieve_data(int index, struct LinkedList *linked_list);

struct LinkedList linked_list_constructor()
{
    struct LinkedList linked_list;
    linked_list.head = NULL;
    linked_list.length = 0;
    linked_list.insert = insert_node;
    linked_list.remove = remove_node;
    linked_list.retrieve = retrieve_data;

    return linked_list;
}

struct Node *create_node(void *data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;

    return node;
}

void destroy_node(struct Node *node)
{
    free(node->data);
    free(node);
}

struct Node *iterate(int index, struct LinkedList *linked_list)
{
    if (index < 0 || index >= linked_list->length)
    {
        printf("Index out of bounds\n");
        exit(9);
    }

    struct Node *node = linked_list->head;

    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }

    return node;
}

void insert_node(int index, void *data, struct LinkedList *linked_list)
{
    if (index < 0 || index > linked_list->length)
    {
        printf("Index out of bounds\n");
        exit(9);
    }

    struct Node *new_node = create_node(data);

    if (index == 0)
    {
        new_node->next = linked_list->head;
        linked_list->head = new_node;
    }
    else
    {
        struct Node *prev_node = iterate(index - 1, linked_list);
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }

    linked_list->length++;
}

int remove_node(int index, struct LinkedList *linked_list)
{
    if (index < 0 || index >= linked_list->length)
    {
        printf("Index out of bounds\n");
        return 0;
    }

    struct Node *node_to_remove;

    if (index == 0)
    {
        node_to_remove = linked_list->head;
        linked_list->head = node_to_remove->next;
    }
    else
    {
        struct Node *prev_node = iterate(index - 1, linked_list);
        node_to_remove = prev_node->next;
        prev_node->next = node_to_remove->next;
    }

    destroy_node(node_to_remove);
    linked_list->length--;
    return 1;
}

void *retrieve_data(int index, struct LinkedList *linked_list)
{
    if (index < 0 || index >= linked_list->length)
    {
        printf("Index out of bounds\n");
        return NULL;
    }
    struct Node *node = iterate(index, linked_list);
    return node->data;
}
