#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "package_avl.h"

void inicializarAVL(ArbolAVL *arbol) {
    // TODO
}

// Retorna altura del nodo (0 si NULL)
int obtenerAltura(NodoAVL *nodo) {
    // TODO
    return 0;
}

// Retorna factor de balance: altura izquierda - altura derecha
int obtenerFactorBalance(NodoAVL *nodo) {
    // TODO
    return 0;
}

// Rotación simple a la derecha
NodoAVL* rotarDerecha(NodoAVL *y) {
    // TODO
    return y;
}

// Rotación simple a la izquierda
NodoAVL* rotarIzquierda(NodoAVL *x) {
    // TODO
    return x;
}

// Rotación doble izquierda-derecha
NodoAVL* rotarIzquierdaDerecha(NodoAVL *nodo) {
    // TODO
    return nodo;
}

// Rotación doble derecha-izquierda
NodoAVL* rotarDerechaIzquierda(NodoAVL *nodo) {
    // TODO
    return nodo;
}

// Rebalancea el nodo luego de una inserción
NodoAVL* balancear(NodoAVL *nodo) {
    // TODO
    return nodo;
}

// Inserta paquete en el AVL - retorna 1 si éxito, 0 si duplicado
int insertarPaqueteAVL(ArbolAVL *arbol, Paquete paquete) {
    // TODO
    return 0;
}

// Busca paquete por código - retorna nodo o NULL
NodoAVL* buscarPaqueteAVL(ArbolAVL *arbol, const char *codigo) {
    // TODO
    return NULL;
}

// Muestra paquetes en orden por código
void mostrarAVLInOrder(ArbolAVL *arbol) {
    // TODO
}

void liberarAVL(ArbolAVL *arbol) {
    // TODO
}
