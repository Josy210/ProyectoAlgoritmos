#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "returns_stack.h"

void inicializarPila(PilaDevoluciones *pila) {
    // TODO
}

// Apila paquete devuelto - retorna 1 si éxito
int apilar(PilaDevoluciones *pila, Paquete paquete) {
    // TODO
    return 0;
}

// Desapila - exito=1 si ok, exito=0 si vacía
Paquete desapilar(PilaDevoluciones *pila, int *exito) {
    Paquete vacio = {0};
    // TODO
    return vacio;
}

// Consulta tope sin eliminar
Paquete peekPila(PilaDevoluciones *pila, int *exito) {
    Paquete vacio = {0};
    // TODO
    return vacio;
}

void mostrarPila(PilaDevoluciones *pila) {
    // TODO
}

int pilaVacia(PilaDevoluciones *pila) {
    // TODO
    return 1;
}

void liberarPila(PilaDevoluciones *pila) {
    // TODO
}
