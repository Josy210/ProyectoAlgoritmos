#ifndef ROUTES_GRAPH_H
#define ROUTES_GRAPH_H

#define MAX_POINTS 20
#define MAX_POINT_NAME 50
#define INF 99999

// ─── Graph using adjacency matrix ─────────────────────────────────
typedef struct {
    char pointNames[MAX_POINTS][MAX_POINT_NAME];
    int  adjMatrix[MAX_POINTS][MAX_POINTS];
    int  numPoints;
} RouteGraph;

// ─── Dijkstra result ──────────────────────────────────────────────
typedef struct {
    int distances[MAX_POINTS];
    int previous[MAX_POINTS];
} DijkstraResult;

// ─── Function declarations ────────────────────────────────────────
void initGraph(RouteGraph *graph);
int  addPoint(RouteGraph *graph, const char *name);
int  addRoute(RouteGraph *graph, const char *from, const char *to, int weight);
int  findPointIndex(RouteGraph *graph, const char *name);
void displayPoints(RouteGraph *graph);
void displayAdjacencyMatrix(RouteGraph *graph);
void dijkstra(RouteGraph *graph, const char *origin, const char *destination);

#endif // ROUTES_GRAPH_H
