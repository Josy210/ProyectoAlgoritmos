#ifndef CLIENT_BST_H
#define CLIENT_BST_H

#include "types.h"

// ─── Nodo del BST ─────────────────────────────────────────────────
typedef struct NodoBST {
    Cliente dato;
    struct NodoBST *izquierda;
    struct NodoBST *derecha;
} NodoBST;

// ─── Árbol BST ────────────────────────────────────────────────────
typedef struct {
    NodoBST *raiz;
    int tamano;
} ArbolClientes;

// ─── Declaración de funciones ─────────────────────────────────────
void     inicializarBST(ArbolClientes *arbol);
int      insertarCliente(ArbolClientes *arbol, Cliente cliente);
NodoBST* buscarCliente(ArbolClientes *arbol, int id);
int      clienteExiste(ArbolClientes *arbol, int id);
void     mostrarInOrder(ArbolClientes *arbol);
void     mostrarPreOrder(ArbolClientes *arbol);
void     mostrarPostOrder(ArbolClientes *arbol);
void     liberarBST(ArbolClientes *arbol);

#endif // CLIENT_BST_H
