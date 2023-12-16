#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"
#include <stdbool.h>

struct Queue
{
    int length;
    bool is_static;
    struct LinkedList list;
    int (*enqueue)(void *data, struct Queue *queue);
    void (*dequeue)(struct Queue *queue);
    void *(*peek)(struct Queue *queue);
};

struct Queue queue_constructor(bool is_static, int length);

#endif // QUEUE_H