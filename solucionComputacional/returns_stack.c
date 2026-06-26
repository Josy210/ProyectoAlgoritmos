#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "returns_stack.h"

void inicializarPila(PilaDevoluciones *pila) {
    pila->tope = NULL;
    pila->tamano = 0;
}

int apilar(PilaDevoluciones *pila, Paquete paquete) {
    NodoPila *nuevo = (NodoPila *)malloc(sizeof(NodoPila));
    if (nuevo == NULL) {
        return 0;
    }

    strncpy(paquete.estado, estadoDevuelto, maxEstado - 1);
    paquete.estado[maxEstado - 1] = '\0';
    nuevo->dato = paquete;
    nuevo->siguiente = pila->tope;
    pila->tope = nuevo;
    pila->tamano++;
    return 1;
}

Paquete desapilar(PilaDevoluciones *pila, int *exito) {
    Paquete vacio = {0};
    if (pilaVacia(pila)) {
        *exito = 0;
        return vacio;
    }

    NodoPila *eliminado = pila->tope;
    Paquete paquete = eliminado->dato;
    pila->tope = eliminado->siguiente;
    free(eliminado);
    pila->tamano--;
    *exito = 1;
    return paquete;
}

Paquete peekPila(PilaDevoluciones *pila, int *exito) {
    Paquete vacio = {0};
    if (pilaVacia(pila)) {
        *exito = 0;
        return vacio;
    }
    *exito = 1;
    return pila->tope->dato;
}

void mostrarPila(PilaDevoluciones *pila) {
    if (pilaVacia(pila)) {
        printf("No hay paquetes devueltos.\n");
        return;
    }

    for (NodoPila *actual = pila->tope; actual != NULL; actual = actual->siguiente) {
        Paquete p = actual->dato;
        printf("Codigo: %s | Cliente: %d | Destinatario: %s | Destino: %s | Estado: %s\n",
               p.codigo, p.idCliente, p.nombreDestinatario, p.destino, p.estado);
    }
}


int pilaVacia(PilaDevoluciones *pila) {
    return pila->tope == NULL;
}

void liberarPila(PilaDevoluciones *pila) {
    int exito = 0;
    while (!pilaVacia(pila)) {
        desapilar(pila, &exito);
    }
}