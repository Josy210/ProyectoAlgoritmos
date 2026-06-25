#ifndef PACKAGE_AVL_H
#define PACKAGE_AVL_H

#include "types.h"

// ─── Nodo del AVL ─────────────────────────────────────────────────
typedef struct NodoAVL {
    Paquete dato;
    struct NodoAVL *izquierda;
    struct NodoAVL *derecha;
    int altura;
} NodoAVL;

// ─── Árbol AVL ────────────────────────────────────────────────────
typedef struct {
    NodoAVL *raiz;
    int tamano;
} ArbolAVL;

// ─── Declaración de funciones ─────────────────────────────────────
void      inicializarAVL(ArbolAVL *arbol);
int       insertarPaqueteAVL(ArbolAVL *arbol, Paquete paquete);
NodoAVL*  buscarPaqueteAVL(ArbolAVL *arbol, const char *codigo);
void      mostrarAVLInOrder(ArbolAVL *arbol);
void      liberarAVL(ArbolAVL *arbol);

// ─── Funciones internas del AVL ───────────────────────────────────
int       obtenerAltura(NodoAVL *nodo);
int       obtenerFactorBalance(NodoAVL *nodo);
NodoAVL*  rotarDerecha(NodoAVL *y);
NodoAVL*  rotarIzquierda(NodoAVL *x);
NodoAVL*  rotarIzquierdaDerecha(NodoAVL *nodo);
NodoAVL*  rotarDerechaIzquierda(NodoAVL *nodo);
NodoAVL*  balancear(NodoAVL *nodo);

#endif // PACKAGE_AVL_H
