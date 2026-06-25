#ifndef PACKAGE_LIST_H
#define PACKAGE_LIST_H

#include "types.h"

// ─── Nodo de la lista enlazada ────────────────────────────────────
typedef struct NodoPaquete {
    Paquete dato;
    struct NodoPaquete *siguiente;
} NodoPaquete;

// ─── Lista enlazada ───────────────────────────────────────────────
typedef struct {
    NodoPaquete *cabeza;
    int tamano;
} ListaPaquetes;

// ─── Declaración de funciones ─────────────────────────────────────
void         inicializarListaPaquetes(ListaPaquetes *lista);
int          insertarPaquete(ListaPaquetes *lista, Paquete paquete);
NodoPaquete* buscarPaquetePorCodigo(ListaPaquetes *lista, const char *codigo);
int          actualizarEstadoPaquete(ListaPaquetes *lista, const char *codigo, const char *nuevoEstado);
int          eliminarPaquete(ListaPaquetes *lista, const char *codigo);
void         mostrarTodosPaquetes(ListaPaquetes *lista);
void         contarPaquetesPorEstado(ListaPaquetes *lista);
void         liberarListaPaquetes(ListaPaquetes *lista);

#endif // PACKAGE_LIST_H
