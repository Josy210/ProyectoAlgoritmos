#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "returns_stack.h"

void initStack(ReturnsStack *stack) {
    // TODO
}

// Push returned package - returns 1 if success
int push(ReturnsStack *stack, Package pkg) {
    // TODO
    return 0;
}

// Pop - sets success=1 if ok, success=0 if empty
Package pop(ReturnsStack *stack, int *success) {
    Package empty = {0};
    // TODO
    return empty;
}

// Peek top without removing
Package peekStack(ReturnsStack *stack, int *success) {
    Package empty = {0};
    // TODO
    return empty;
}

void displayStack(ReturnsStack *stack) {
    // TODO
}

int isStackEmpty(ReturnsStack *stack) {
    // TODO
    return 1;
}

void freeStack(ReturnsStack *stack) {
    // TODO
}
