#include "Queue.h"
#include <stdio.h>
#include <stdbool.h>

int main()
{
    struct Queue queue = queue_constructor(true, 1);
    int *data1 = (int *)malloc(sizeof(int));
    int *data2 = (int *)malloc(sizeof(int));
    *data1 = 55;
    *data2 = 66;

    queue.enqueue(data1, &queue);
    queue.enqueue(data2, &queue);

    printf("%d\n", *((int *)(queue.peek(&queue))));
    queue.dequeue(&queue);
    int *peek_val = (int *)(queue.peek(&queue));
    if (peek_val != NULL)
    {
        printf("%d\n", *peek_val);
    }

    queue.dequeue(&queue);

    return 0;
}