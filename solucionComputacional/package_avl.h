#ifndef PACKAGE_AVL_H
#define PACKAGE_AVL_H

#include "types.h"

// ─── AVL node ─────────────────────────────────────────────────────
typedef struct AVLNode {
    Package data;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
} AVLNode;

// ─── AVL tree ─────────────────────────────────────────────────────
typedef struct {
    AVLNode *root;
    int size;
} PackageAVL;

// ─── Function declarations ────────────────────────────────────────
void     initAVL(PackageAVL *tree);
int      insertPackageAVL(PackageAVL *tree, Package pkg);
AVLNode* searchPackageAVL(PackageAVL *tree, const char *code);
void     displayAVLInOrder(PackageAVL *tree);
void     freeAVL(PackageAVL *tree);

// ─── Internal AVL helpers (used inside package_avl.c only) ───────
int      getHeight(AVLNode *node);
int      getBalanceFactor(AVLNode *node);
AVLNode* rotateRight(AVLNode *y);
AVLNode* rotateLeft(AVLNode *x);
AVLNode* rotateLeftRight(AVLNode *node);
AVLNode* rotateRightLeft(AVLNode *node);
AVLNode* balance(AVLNode *node);

#endif // PACKAGE_AVL_H
