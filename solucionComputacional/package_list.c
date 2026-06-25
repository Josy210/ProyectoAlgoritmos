#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "package_list.h"

// Inicializa la lista vacía
void inicializarListaPaquetes(ListaPaquetes *lista) {
    // TODO
}

// Inserta paquete - retorna 1 si éxito, 0 si código duplicado
int insertarPaquete(ListaPaquetes *lista, Paquete paquete) {
    // TODO
    return 0;
}

// Busca paquete por código - retorna nodo o NULL
NodoPaquete* buscarPaquetePorCodigo(ListaPaquetes *lista, const char *codigo) {
    // TODO
    return NULL;
}

// Actualiza estado - retorna 1 si éxito, 0 si no encontrado
int actualizarEstadoPaquete(ListaPaquetes *lista, const char *codigo, const char *nuevoEstado) {
    // TODO
    return 0;
}

// Elimina paquete - retorna 1 si éxito, 0 si no encontrado
int eliminarPaquete(ListaPaquetes *lista, const char *codigo) {
    // TODO
    return 0;
}

// Muestra todos los paquetes
void mostrarTodosPaquetes(ListaPaquetes *lista) {
    // TODO
}

// Cuenta y muestra paquetes agrupados por estado
void contarPaquetesPorEstado(ListaPaquetes *lista) {
    // TODO
}

// Libera toda la memoria
void liberarListaPaquetes(ListaPaquetes *lista) {
    // TODO
}
