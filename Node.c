#include "Node.h"
#include <stdlib.h>
#include <string.h>

Node node_constructor(void *data, int size)
{
    Node node;
    node.data = malloc(size);
    memcpy(node.data, data, size);
    node.size = size;
    node.next = NULL;
    node.prev = NULL;

    return node;
}

void node_destructor(Node *node)
{
    free(node->data);
    free(node);
}