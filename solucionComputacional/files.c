#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "files.h"

// ─── Clientes ─────────────────────────────────────────────────────

void guardarClientes(ArbolClientes *arbol) {
    // TODO: recorrer BST inorder y escribir cada cliente en ARCHIVO_CLIENTES
}

void cargarClientes(ArbolClientes *arbol) {
    // TODO: leer ARCHIVO_CLIENTES línea por línea e insertar cada cliente en el BST
}

// ─── Paquetes ─────────────────────────────────────────────────────

void guardarPaquetes(ListaPaquetes *lista) {
    // TODO: recorrer lista y escribir cada paquete en ARCHIVO_PAQUETES
}

void cargarPaquetes(ListaPaquetes *lista, ArbolAVL *avl, ArbolClientes *bst) {
    // TODO: leer ARCHIVO_PAQUETES e insertar cada paquete en lista y AVL
    // Validar que el cliente exista en el BST antes de insertar
}

// ─── Rutas ────────────────────────────────────────────────────────

void guardarRutas(GrafoRutas *grafo) {
    // TODO: escribir puntos y matriz de adyacencia en ARCHIVO_RUTAS
}

void cargarRutas(GrafoRutas *grafo) {
    // TODO: leer ARCHIVO_RUTAS y reconstruir el grafo
}
