#include "Queue.h"
#include <stdio.h>
#include <stdbool.h>

int enqueue(void *data, struct Queue *queue)
{
    if (queue->is_static && queue->list.length == queue->length)
    {
        printf("Queue is full\n");
        return 0;
    }
    queue->list.insert(queue->list.length, data, &queue->list);
    return 1;
}

void dequeue(struct Queue *queue)
{
    if (!(queue->list.remove(0, &queue->list)))
    {
        printf("Nothing to dequeue\n");
    }
}

void *peek(struct Queue *queue)
{
    void *data = queue->list.retrieve(0, &queue->list);
    if (data == NULL)
    {
        printf("Nothing to peek\n");
        return NULL;
    }
    return data;
}

struct Queue queue_constructor(bool is_static, int length)
{
    struct Queue queue;
    queue.length = length;
    queue.is_static = is_static;
    queue.list = linked_list_constructor();
    queue.enqueue = enqueue;
    queue.dequeue = dequeue;
    queue.peek = peek;

    return queue;
}