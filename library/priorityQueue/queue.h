#ifndef SPBU_2020_C_QUEUE_H
#define SPBU_2020_C_QUEUE_H

#include <stdbool.h>

typedef struct Queue Queue;
typedef struct QueueElement QueueElement;

Queue* createQueue();
QueueElement* createQueueElement(int priority, int value);
bool isEmpty(Queue* queue);
void enqueue(Queue* queue, int priority, int value);
int dequeue(Queue* queue);
void printQueue(Queue* queue);
void removeQueue(Queue* queue);

#endif