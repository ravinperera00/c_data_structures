#ifndef NODE_H
#define NODE_H

typedef struct Node
{
    void *data;
    int size;
    struct Node *next;
    struct Node *prev;
} Node;

struct Node node_constructor(void *data, int size);
void node_destructor(struct Node *node);

#endif