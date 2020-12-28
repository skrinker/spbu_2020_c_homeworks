#include "../library/priorityQueue/queue.h"
#include <stdio.h>

int main()
{
    Queue* queue = createQueue();
    int size = 0;
    int priority = 0;
    int value = 0;
    printf("Input number of items: \n");
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        printf("Item %d: \n", i + 1);
        printf("Value: ");
        scanf("%d", &value);
        printf("Priority: ");
        scanf("%d", &priority);
        enqueue(queue, priority, value);
    }
    printQueue(queue);
    for (int i = 0; i <= size; i++) {
        printf("%d \n", dequeue(queue));
    }

    free(queue);
    return 0;
}