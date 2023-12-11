#include "LinkedList.h"

struct Node_int *create_node_int(int data);
void destroy_node_int(struct Node_int *node);
struct Node_int *iterate(int index, struct LinkedList_int *linked_list);

void insert_node_int(int index, int data, struct LinkedList_int *linked_list);
void remove_node_int(int index, struct LinkedList_int *linked_list);
int retrieve_data_int(int index, struct LinkedList_int *linked_list);

struct LinkedList_int linked_list_int_constructor()
{
    struct LinkedList_int linked_list;
    linked_list.head = NULL;
    linked_list.length = 0;
    linked_list.insert = insert_node_int;
    linked_list.remove = remove_node_int;
    linked_list.retrieve = retrieve_data_int;

    return linked_list;
}

struct Node_int *create_node_int(int data)
{
    struct Node_int *node = (struct Node_int *)malloc(sizeof(struct Node_int));
    node->data = 0;
    node->next = NULL;

    return node;
}

void destroy_node_int(struct Node_int *node)
{
    free(node);
}

struct Node_int *iterate(int index, struct LinkedList_int *linked_list)
{
    if (index < 0 || index >= linked_list->length)
    {
        printf("Index out of bounds\n");
        exit(9);
    }

    struct Node_int *node = linked_list->head; // Fixed the type specifier issue

    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }

    return node;
}

void insert_node_int(int index, int data, struct LinkedList_int *linked_list)
{
    if (index < 0 || index > linked_list->length)
    {
        printf("Index out of bounds\n");
        exit(9);
    }

    struct Node_int *new_node = create_node_int(data);

    if (index == 0)
    {
        new_node->next = linked_list->head;
        linked_list->head = new_node;
    }
    else
    {
        struct Node_int *prev_node = iterate(index - 1, linked_list);
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }

    linked_list->length++;
}

void remove_node_int(int index, struct LinkedList_int *linked_list)
{
    if (index < 0 || index >= linked_list->length)
    {
        printf("Index out of bounds\n");
        exit(9);
    }

    struct Node_int *node_to_remove;

    if (index == 0)
    {
        node_to_remove = linked_list->head;
        linked_list->head = node_to_remove->next;
    }
    else
    {
        struct Node_int *prev_node = iterate(index - 1, linked_list);
        node_to_remove = prev_node->next;
        prev_node->next = node_to_remove->next;
    }

    destroy_node_int(node_to_remove);
    linked_list->length--;
}

int retrieve_data_int(int index, struct LinkedList_int *linked_list)
{
    struct Node_int *node = iterate(index, linked_list);
    return node->data;
}
