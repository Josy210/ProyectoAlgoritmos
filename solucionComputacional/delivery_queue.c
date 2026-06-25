#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "delivery_queue.h"

void initQueue(DeliveryQueue *queue) {
    // TODO
}

// Enqueue package - returns 1 if success
int enqueue(DeliveryQueue *queue, Package pkg) {
    // TODO
    return 0;
}

// Dequeue - sets success=1 if ok, success=0 if empty
Package dequeue(DeliveryQueue *queue, int *success) {
    Package empty = {0};
    // TODO
    return empty;
}

// Peek front without removing - sets success flag
Package peekQueue(DeliveryQueue *queue, int *success) {
    Package empty = {0};
    // TODO
    return empty;
}

void displayQueue(DeliveryQueue *queue) {
    // TODO
}

int isQueueEmpty(DeliveryQueue *queue) {
    // TODO
    return 1;
}

void freeQueue(DeliveryQueue *queue) {
    // TODO
}
