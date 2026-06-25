#ifndef DELIVERY_QUEUE_H
#define DELIVERY_QUEUE_H

#include "types.h"

// ─── Nodo de la cola ──────────────────────────────────────────────
typedef struct NodoCola {
    Paquete dato;
    struct NodoCola *siguiente;
} NodoCola;

// ─── Cola (FIFO) ──────────────────────────────────────────────────
typedef struct {
    NodoCola *frente;
    NodoCola *final;
    int tamano;
} ColaPendientes;

// ─── Declaración de funciones ─────────────────────────────────────
void    inicializarCola(ColaPendientes *cola);
int     enqueue(ColaPendientes *cola, Paquete paquete);
Paquete dequeue(ColaPendientes *cola, int *exito);
Paquete peekCola(ColaPendientes *cola, int *exito);
void    mostrarCola(ColaPendientes *cola);
int     colaVacia(ColaPendientes *cola);
void    liberarCola(ColaPendientes *cola);

#endif // DELIVERY_QUEUE_H
