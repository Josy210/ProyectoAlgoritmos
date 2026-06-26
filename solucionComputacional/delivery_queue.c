#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "delivery_queue.h"
#include "types.h"

void inicializarCola(ColaPendientes *cola) {
    cola->frente = NULL;
    cola->final = NULL;
    cola->tamano = 0;
}

int enqueue(ColaPendientes *cola, Paquete paquete) {
    NodoCola *nuevo = (NodoCola *)malloc(sizeof(NodoCola));
    if (nuevo == NULL) {
        return 0;
    }

    strncpy(paquete.estado, ESTADO_ENTREGADO, MAX_ESTADO - 1);
    paquete.estado[MAX_ESTADO - 1] = '\0';
    nuevo->dato = paquete;
    nuevo->siguiente = NULL;

    if (cola->final == NULL) {
        cola->frente = nuevo;
        cola->final = nuevo;
    } else {
        cola->final->siguiente = nuevo;
        cola->final = nuevo;
    }
    cola->tamano++;
    return 1;
}

Paquete dequeue(ColaPendientes *cola, int *exito) {
    Paquete vacio = {0};
    if (colaVacia(cola)) {
        *exito = 0;
        return vacio;
    }

    NodoCola *eliminado = cola->frente;
    Paquete paquete = eliminado->dato;
    cola->frente = eliminado->siguiente;
    if (cola->frente == NULL) {
        cola->final = NULL;
    }
    free(eliminado);
    cola->tamano--;
    *exito = 1;
    return paquete;
}

Paquete peekCola(ColaPendientes *cola, int *exito) {
    Paquete vacio = {0};
    if (colaVacia(cola)) {
        *exito = 0;
        return vacio;
    }
    *exito = 1;
    return cola->frente->dato;
}

void mostrarCola(ColaPendientes *cola) {
    if (colaVacia(cola)) {
        printf("No hay paquetes pendientes en cola.\n");
        return;
    }

    for (NodoCola *actual = cola->frente; actual != NULL; actual = actual->siguiente) {
        Paquete p = actual->dato;
        printf("Codigo: %s | Cliente: %d | Destinatario: %s | Destino: %s | Estado: %s\n",
               p.codigo, p.idCliente, p.nombreDestinatario, p.destino, p.estado);
    }
}
int colaVacia(ColaPendientes *cola) {
    return cola->frente == NULL;
}

void liberarCola(ColaPendientes *cola) {
    int exito = 0;
    while (!colaVacia(cola)) {
        dequeue(cola, &exito);
    }
}
