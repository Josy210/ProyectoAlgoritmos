#ifndef ROUTES_GRAPH_H
#define ROUTES_GRAPH_H

#define MAX_PUNTOS       20
#define MAX_NOMBRE_PUNTO 50
#define INFINITO         99999

// ─── Grafo mediante matriz de adyacencia ──────────────────────────
typedef struct {
    char nombresPuntos[MAX_PUNTOS][MAX_NOMBRE_PUNTO];
    int  matrizAdyacencia[MAX_PUNTOS][MAX_PUNTOS];
    int  numPuntos;
} GrafoRutas;

// ─── Resultado de Dijkstra ────────────────────────────────────────
typedef struct {
    int distancias[MAX_PUNTOS];
    int anteriores[MAX_PUNTOS];
} ResultadoDijkstra;

// ─── Declaración de funciones ─────────────────────────────────────
void inicializarGrafo(GrafoRutas *grafo);
int  agregarPunto(GrafoRutas *grafo, const char *nombre);
int  agregarRuta(GrafoRutas *grafo, const char *origen, const char *destino, int peso);
int  buscarIndicePunto(GrafoRutas *grafo, const char *nombre);
void mostrarPuntos(GrafoRutas *grafo);
void mostrarMatrizAdyacencia(GrafoRutas *grafo);
void dijkstra(GrafoRutas *grafo, const char *origen, const char *destino);

#endif // ROUTES_GRAPH_H
