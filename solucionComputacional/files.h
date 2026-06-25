#ifndef FILES_H
#define FILES_H

#include "types.h"
#include "package_list.h"
#include "client_bst.h"
#include "package_avl.h"
#include "routes_graph.h"

// ─── Nombres de archivos ──────────────────────────────────────────
#define ARCHIVO_CLIENTES  "clientes.txt"
#define ARCHIVO_PAQUETES  "paquetes.txt"
#define ARCHIVO_RUTAS     "rutas.txt"

// ─── Declaración de funciones ─────────────────────────────────────
void guardarClientes(ArbolClientes *arbol);
void cargarClientes(ArbolClientes *arbol);

void guardarPaquetes(ListaPaquetes *lista);
void cargarPaquetes(ListaPaquetes *lista, ArbolAVL *avl, ArbolClientes *bst);

void guardarRutas(GrafoRutas *grafo);
void cargarRutas(GrafoRutas *grafo);

#endif // FILES_H
