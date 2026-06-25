#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "delivery_queue.h"

void inicializarCola(ColaPendientes *cola) {
    // TODO
}

// Encola paquete - retorna 1 si éxito
int enqueue(ColaPendientes *cola, Paquete paquete) {
    // TODO
    return 0;
}

// Desencola - exito=1 si ok, exito=0 si vacía
Paquete dequeue(ColaPendientes *cola, int *exito) {
    Paquete vacio = {0};
    // TODO
    return vacio;
}

// Consulta frente sin eliminar
Paquete peekCola(ColaPendientes *cola, int *exito) {
    Paquete vacio = {0};
    // TODO
    return vacio;
}

void mostrarCola(ColaPendientes *cola) {
    // TODO
}

int colaVacia(ColaPendientes *cola) {
    // TODO
    return 1;
}

void liberarCola(ColaPendientes *cola) {
    // TODO
}
