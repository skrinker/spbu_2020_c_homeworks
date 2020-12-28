#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    QueueElement* head;
    QueueElement* tail;
};

struct QueueElement {
    int priority;
    int value;
    QueueElement* next;
    QueueElement* previous;
};

Queue* createQueue()
{
    Queue* queue = (Queue*)malloc(sizeof(QueueElement));
    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

QueueElement* createQueueElement(int priority, int value)
{
    QueueElement* queueElement = (QueueElement*)malloc(sizeof(QueueElement));
    queueElement->value = value;
    queueElement->priority = priority;
    queueElement->next = NULL;
    return queueElement;
}

bool isEmpty(Queue* queue)
{
    return (queue->size == 0);
}

void enqueue(Queue* queue, int priority, int value)
{
    if (isEmpty(queue)) {
        queue->head = createQueueElement(priority, value);
    } else {
        QueueElement* current = queue->head;
        QueueElement* input = createQueueElement(priority, value);
        while (current->priority <= priority && current->next != NULL) {
            current = current->next;
        }
        input->next = current->next;
        input->previous = current;
        current->next = input;
        if (input->next == NULL) {
            queue->tail = input;
        }
    }
    queue->size++;
}

int dequeue(Queue* queue)
{
    if (isEmpty(queue)) {
        return -1;
    }
    QueueElement* removed = queue->tail;
    int value = removed->value;
    queue->tail = removed->previous;
    free(removed);
    queue->size--;
    return value;
}

void printQueue(Queue* queue)
{
    QueueElement* current = queue->head;
    while (current != NULL) {
        printf("value: %d , priority: %d \n", current->value, current->priority);
        current = current->next;
    }
}