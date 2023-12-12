#include "LinkedList.h"
#include <stdio.h>

int main()
{
    struct LinkedList linked_list = linked_list_constructor();
    int *data1 = (int *)malloc(sizeof(int));
    int *data2 = (int *)malloc(sizeof(int));
    *data1 = 55;
    *data2 = 66;

    linked_list.insert(0, data1, &linked_list);
    linked_list.insert(1, data2, &linked_list);

    printf("%d\n", *(int *)(linked_list.retrieve(0, &linked_list)));
    printf("%d\n", *(int *)(linked_list.retrieve(1, &linked_list)));

    linked_list.remove(0, &linked_list);
    linked_list.remove(0, &linked_list);

    return 0;
}