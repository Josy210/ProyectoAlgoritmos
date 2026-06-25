#ifndef RETURNS_STACK_H
#define RETURNS_STACK_H

#include "types.h"

// ─── Nodo de la pila ──────────────────────────────────────────────
typedef struct NodoPila {
    Paquete dato;
    struct NodoPila *siguiente;
} NodoPila;

// ─── Pila (LIFO) ──────────────────────────────────────────────────
typedef struct {
    NodoPila *tope;
    int tamano;
} PilaDevoluciones;

// ─── Declaración de funciones ─────────────────────────────────────
void    inicializarPila(PilaDevoluciones *pila);
int     apilar(PilaDevoluciones *pila, Paquete paquete);
Paquete desapilar(PilaDevoluciones *pila, int *exito);
Paquete peekPila(PilaDevoluciones *pila, int *exito);
void    mostrarPila(PilaDevoluciones *pila);
int     pilaVacia(PilaDevoluciones *pila);
void    liberarPila(PilaDevoluciones *pila);

#endif // RETURNS_STACK_H
