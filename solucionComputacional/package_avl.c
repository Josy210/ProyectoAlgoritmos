#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "package_avl.h"

void initAVL(PackageAVL *tree) {
    // TODO
}

// Returns height of node (0 if NULL)
int getHeight(AVLNode *node) {
    // TODO
    return 0;
}

// Returns balance factor: left height - right height
int getBalanceFactor(AVLNode *node) {
    // TODO
    return 0;
}

// Simple right rotation
AVLNode* rotateRight(AVLNode *y) {
    // TODO
    return y;
}

// Simple left rotation
AVLNode* rotateLeft(AVLNode *x) {
    // TODO
    return x;
}

// Double rotation: left then right
AVLNode* rotateLeftRight(AVLNode *node) {
    // TODO
    return node;
}

// Double rotation: right then left
AVLNode* rotateRightLeft(AVLNode *node) {
    // TODO
    return node;
}

// Rebalance node after insertion
AVLNode* balance(AVLNode *node) {
    // TODO
    return node;
}

// Insert package into AVL - returns 1 if success, 0 if duplicate
int insertPackageAVL(PackageAVL *tree, Package pkg) {
    // TODO
    return 0;
}

// Search package by code - returns node or NULL
AVLNode* searchPackageAVL(PackageAVL *tree, const char *code) {
    // TODO
    return NULL;
}

// Display packages in order by code
void displayAVLInOrder(PackageAVL *tree) {
    // TODO
}

void freeAVL(PackageAVL *tree) {
    // TODO
}
