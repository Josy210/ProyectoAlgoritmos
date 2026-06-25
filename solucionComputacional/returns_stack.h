#ifndef RETURNS_STACK_H
#define RETURNS_STACK_H

#include "types.h"

// ─── Node of the stack ────────────────────────────────────────────
typedef struct StackNode {
    Package data;
    struct StackNode *next;
} StackNode;

// ─── Stack (LIFO) ─────────────────────────────────────────────────
typedef struct {
    StackNode *top;
    int size;
} ReturnsStack;

// ─── Function declarations ────────────────────────────────────────
void initStack(ReturnsStack *stack);
int  push(ReturnsStack *stack, Package pkg);
Package pop(ReturnsStack *stack, int *success);
Package peekStack(ReturnsStack *stack, int *success);
void displayStack(ReturnsStack *stack);
int  isStackEmpty(ReturnsStack *stack);
void freeStack(ReturnsStack *stack);

#endif // RETURNS_STACK_H
