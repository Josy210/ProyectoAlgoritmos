#ifndef DELIVERY_QUEUE_H
#define DELIVERY_QUEUE_H

#include "types.h"

// ─── Node of the queue ────────────────────────────────────────────
typedef struct QueueNode {
    Package data;
    struct QueueNode *next;
} QueueNode;

// ─── Queue (FIFO) ─────────────────────────────────────────────────
typedef struct {
    QueueNode *front;
    QueueNode *rear;
    int size;
} DeliveryQueue;

// ─── Function declarations ────────────────────────────────────────
void initQueue(DeliveryQueue *queue);
int  enqueue(DeliveryQueue *queue, Package pkg);
Package dequeue(DeliveryQueue *queue, int *success);
Package peekQueue(DeliveryQueue *queue, int *success);
void displayQueue(DeliveryQueue *queue);
int  isQueueEmpty(DeliveryQueue *queue);
void freeQueue(DeliveryQueue *queue);

#endif // DELIVERY_QUEUE_H
