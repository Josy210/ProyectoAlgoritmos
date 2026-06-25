#ifndef CLIENT_BST_H
#define CLIENT_BST_H

#include "types.h"

// ─── BST node ─────────────────────────────────────────────────────
typedef struct BSTNode {
    Client data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

// ─── BST tree ─────────────────────────────────────────────────────
typedef struct {
    BSTNode *root;
    int size;
} ClientBST;

// ─── Function declarations ────────────────────────────────────────
void    initBST(ClientBST *tree);
int     insertClient(ClientBST *tree, Client client);
BSTNode* searchClient(ClientBST *tree, int id);
int     clientExists(ClientBST *tree, int id);
void    displayInOrder(ClientBST *tree);
void    displayPreOrder(ClientBST *tree);
void    displayPostOrder(ClientBST *tree);
void    freeBST(ClientBST *tree);

#endif // CLIENT_BST_H
