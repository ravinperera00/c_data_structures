#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"
#include <stdbool.h>

typedef struct Queue
{
    int length;
    bool is_static;
    struct LinkedList list;
    int (*enqueue)(void *data, int size, struct Queue *queue);
    void (*dequeue)(struct Queue *queue);
    void *(*peek)(struct Queue *queue);
} Queue;

Queue queue_constructor(bool is_static, int length);
void queue_destructor(Queue *queue);

#endif // QUEUE_H