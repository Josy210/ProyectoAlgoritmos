#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "routes_graph.h"

void initGraph(RouteGraph *graph) {
    // TODO
}

// Add delivery point - returns index or -1 if full/duplicate
int addPoint(RouteGraph *graph, const char *name) {
    // TODO
    return -1;
}

// Add route between two points with weight
// Returns 1 if success, 0 if points don't exist
int addRoute(RouteGraph *graph, const char *from, const char *to, int weight) {
    // TODO
    return 0;
}

// Find point index by name - returns -1 if not found
int findPointIndex(RouteGraph *graph, const char *name) {
    // TODO
    return -1;
}

void displayPoints(RouteGraph *graph) {
    // TODO
}

void displayAdjacencyMatrix(RouteGraph *graph) {
    // TODO
}

// Calculate and display shortest path using Dijkstra
void dijkstra(RouteGraph *graph, const char *origin, const char *destination) {
    // TODO
}
