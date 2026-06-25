#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "routes_graph.h"

void inicializarGrafo(GrafoRutas *grafo) {
    // TODO
}

// Agrega punto de entrega - retorna índice o -1 si lleno/duplicado
int agregarPunto(GrafoRutas *grafo, const char *nombre) {
    // TODO
    return -1;
}

// Agrega ruta entre dos puntos con peso
// Retorna 1 si éxito, 0 si algún punto no existe
int agregarRuta(GrafoRutas *grafo, const char *origen, const char *destino, int peso) {
    // TODO
    return 0;
}

// Busca índice de punto por nombre - retorna -1 si no existe
int buscarIndicePunto(GrafoRutas *grafo, const char *nombre) {
    // TODO
    return -1;
}

void mostrarPuntos(GrafoRutas *grafo) {
    // TODO
}

void mostrarMatrizAdyacencia(GrafoRutas *grafo) {
    // TODO
}

// Calcula y muestra la ruta más corta usando Dijkstra
void dijkstra(GrafoRutas *grafo, const char *origen, const char *destino) {
    // TODO
}
