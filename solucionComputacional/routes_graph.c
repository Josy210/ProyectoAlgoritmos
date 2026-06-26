#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "routes_graph.h"

void inicializarGrafo(GrafoRutas *grafo) {
    grafo->numPuntos = 0;
    for (int i = 0; i < MAX_PUNTOS; i++) {
        grafo->nombresPuntos[i][0] = '\0';
        for (int j = 0; j < MAX_PUNTOS; j++) {
            grafo->matrizAdyacencia[i][j] = 0;
        }
    }
}

// Busca índice de punto por nombre
int buscarIndicePunto(GrafoRutas *grafo, const char *nombre) {
    for (int i = 0; i < grafo->numPuntos; i++) {
        if (strcmp(grafo->nombresPuntos[i], nombre) == 0)
            return i;
    }
    return -1;
}

// Agrega punto de entrega
int agregarPunto(GrafoRutas *grafo, const char *nombre) {
    if (grafo->numPuntos >= MAX_PUNTOS) {
        printf("Error: se alcanzo el maximo de puntos\n");
        return -1;
    }

    if (buscarIndicePunto(grafo, nombre) != -1) {
        printf("Error: el punto %s ya existe\n", nombre);
        return -1;
    }

    int indice = grafo->numPuntos;
    strcpy(grafo->nombresPuntos[indice], nombre);
    grafo->numPuntos++;
    printf("Punto %s agregado correctamente.\n", nombre);
    return indice;

}

// Agrega ruta entre dos puntos con peso
int agregarRuta(GrafoRutas *grafo, const char *origen, const char *destino, int peso) {
    if (peso <= 0) {
        printf("Error: el peso debe ser mayor a cero\n");
        return 0;
    }

    int i = buscarIndicePunto(grafo, origen);
    int j = buscarIndicePunto(grafo, destino);

    if (i == -1) {
        printf("Error: el punto %s no existe\n", origen);
        return 0;
    }
    if (j == -1) {
        printf("Error: el punto %s no existe\n", destino);
        return 0;
    }
    grafo->matrizAdyacencia[i][j] = peso;
    grafo->matrizAdyacencia[j][i] = peso;
    printf("Ruta agregada: %s <--> %s, distancia: %d\n", origen, destino, peso);
    return 1;
}


void mostrarPuntos(GrafoRutas *grafo) {
    if (grafo->numPuntos == 0) {
        printf("No hay puntos registrados.\n");
        return;
    }
    printf("\n===== PUNTOS DE ENTREGA =====\n");
    for (int i = 0; i < grafo->numPuntos; i++) {
        printf("%d. %s\n", i + 1, grafo->nombresPuntos[i]);
    }
    printf("Total: %d punto(s)\n", grafo->numPuntos);

}

void mostrarMatrizAdyacencia(GrafoRutas *grafo) {
    if (grafo->numPuntos == 0) {
        printf("No hay puntos registrados.\n");
        return;
    }
    printf("\n===== MATRIZ DE ADYACENCIA =====\n");
    printf("%-15s", " ");
    for (int i = 0; i < grafo->numPuntos; i++)
        printf("%-15s", grafo->nombresPuntos[i]);
    printf("\n");

    for (int i = 0; i < grafo->numPuntos; i++) {
        printf("%-15s", grafo->nombresPuntos[i]);
        for (int j = 0; j < grafo->numPuntos; j++) {
            printf("%-15d", grafo->matrizAdyacencia[i][j]);
        }
        printf("\n");
    }
}

// Calcula y muestra la ruta más corta usando Dijkstra
void dijkstra(GrafoRutas *grafo, const char *origen, const char *destino) {
    // TODO
}
