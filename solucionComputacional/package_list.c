#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "package_list.h"

static int textoNoVacio(const char *texto) {
    return texto != NULL && texto[0] != '\0';
}

static int estadoValido(const char *estado) {
    return strcmp(estado, ESTADO_REGISTRADO) == 0 ||
           strcmp(estado, ESTADO_PENDIENTE) == 0 ||
           strcmp(estado, ESTADO_EN_RUTA) == 0 ||
           strcmp(estado, ESTADO_ENTREGADO) == 0 ||
           strcmp(estado, ESTADO_DEVUELTO) == 0;
}

static int prioridadValida(const char *prioridad) {
    return strcmp(prioridad, PRIORIDAD_BAJA) == 0 ||
           strcmp(prioridad, PRIORIDAD_MEDIA) == 0 ||
           strcmp(prioridad, PRIORIDAD_ALTA) == 0;
}

static int paqueteValido(Paquete paquete) {
    return textoNoVacio(paquete.codigo) &&
           paquete.idCliente > 0 &&
           textoNoVacio(paquete.nombreDestinatario) &&
           textoNoVacio(paquete.destino) &&
           paquete.peso > 0.0f &&
           prioridadValida(paquete.prioridad) &&
           estadoValido(paquete.estado);
}


// Inicializa la lista vacía
void inicializarListaPaquetes(ListaPaquetes *lista) {
    lista->cabeza = NULL;
    lista->tamano = 0;
}

// Inserta paquete
int insertarPaquete(ListaPaquetes *lista, Paquete paquete) {
    if (paquete.peso <= 0) {
        printf("Error: el peso debe ser mayor a cero.\n");
        return 0;
    }
    if (buscarPaquetePorCodigo(lista, paquete.codigo) != NULL) {
        printf("Error: ya existe un paquete con el codigo %s\n", paquete.codigo);
        return 0;
    }

    NodoPaquete *nuevo = (NodoPaquete*)malloc(sizeof(NodoPaquete));
    if (nuevo == NULL) {
        printf("Error: no hay memoria disponible\n");
        return 0;
    }

    nuevo->dato = paquete;

    nuevo->siguiente = lista->cabeza;
    lista->cabeza = nuevo;
    lista->tamano++;

    return 1;
}

// Busca paquete por código
NodoPaquete* buscarPaquetePorCodigo(ListaPaquetes *lista, const char *codigo) {
    NodoPaquete *actual = lista->cabeza;
    while (actual != NULL) {
        if (strcmp(actual->dato.codigo, codigo) == 0) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return NULL;
}

// Actualiza estado
int actualizarEstadoPaquete(ListaPaquetes *lista, const char *codigo, const char *nuevoEstado) {
    if (!estadoValido(nuevoEstado)) {
        printf("Error: estado invalido\n");
        return 0;
    }
    NodoPaquete *nodo = buscarPaquetePorCodigo(lista, codigo);
    if (nodo == NULL) {
        printf("Error: no existe un paquete con el codigo %s\n", codigo);
        return 0;
    }
    strcpy(nodo->dato.estado, nuevoEstado);
    printf("Estado actualizado correctamente.\n");
    return 1;
}

// Elimina paquete
int eliminarPaquete(ListaPaquetes *lista, const char *codigo) {
    if (lista->cabeza == NULL) {
        printf("Error: la lista esta vacia\n");
        return 0;
    }

    NodoPaquete *actual = lista->cabeza;
    NodoPaquete *anterior = NULL;

    while (actual != NULL && strcmp(actual->dato.codigo, codigo) != 0) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("Error: no existe un paquete con el codigo %s\n", codigo);
        return 0;
    }
    if (anterior == NULL) {
        lista->cabeza = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    free(actual);
    lista->tamano--;
    printf("Paquete eliminado correctamente.\n");
    return 1;
}

// Muestra todos los paquetes
void mostrarTodosPaquetes(ListaPaquetes *lista) {
    if (lista->cabeza == NULL) {
        printf("No hay paquetes registrados.\n");
        return;
    }

    NodoPaquete *actual = lista->cabeza;
    int contador = 1;

    printf("\n===== LISTA DE PAQUETES =====\n");
    while (actual != NULL) {
        printf("--- Paquete %d ---\n", contador);
        printf("Codigo:        %s\n", actual->dato.codigo);
        printf("ID Cliente:    %d\n", actual->dato.idCliente);
        printf("Destinatario:  %s\n", actual->dato.nombreDestinatario);
        printf("Destino:       %s\n", actual->dato.destino);
        printf("Peso:          %.2f kg\n", actual->dato.peso);
        printf("Prioridad:     %s\n", actual->dato.prioridad);
        printf("Estado:        %s\n", actual->dato.estado);
        printf("\n");
        actual = actual->siguiente;
        contador++;
    }
    printf("Total: %d paquete(s)\n", lista->tamano);
}

// Cuenta y muestra paquetes agrupados por estado
void contarPaquetesPorEstado(ListaPaquetes *lista) {
    if (lista->cabeza == NULL) {
        printf("No hay paquetes registrados.\n");
        return;
    }

    int registrados = 0, pendientes = 0, enRuta = 0, entregados = 0, devueltos = 0;

    NodoPaquete *actual = lista->cabeza;
    while (actual != NULL) {
        if (strcmp(actual->dato.estado, ESTADO_REGISTRADO) == 0)  registrados++;
        else if (strcmp(actual->dato.estado, ESTADO_PENDIENTE) == 0)  pendientes++;
        else if (strcmp(actual->dato.estado, ESTADO_EN_RUTA) == 0)    enRuta++;
        else if (strcmp(actual->dato.estado, ESTADO_ENTREGADO) == 0)  entregados++;
        else if (strcmp(actual->dato.estado, ESTADO_DEVUELTO) == 0)   devueltos++;
        actual = actual->siguiente;
    }

    printf("\n===== PAQUETES POR ESTADO =====\n");
    printf("Registrados:        %d\n", registrados);
    printf("Pendientes:         %d\n", pendientes);
    printf("En ruta:            %d\n", enRuta);
    printf("Entregados:         %d\n", entregados);
    printf("Devueltos:          %d\n", devueltos);
    printf("Total:              %d\n", lista->tamano);
}

// Libera toda la memoria
void liberarListaPaquetes(ListaPaquetes *lista) {
    NodoPaquete *actual = lista->cabeza;
    while (actual != NULL) {
        NodoPaquete *siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    lista->cabeza = NULL;
    lista->tamano = 0;
}
