#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client_bst.h"
#include "types.h"

void inicializarBST(ArbolClientes *arbol) {
    arbol->raiz = NULL;
    arbol->tamano = 0;
}
static NodoBST *crearNodoBST(Cliente cliente) {
    NodoBST *nuevo = (NodoBST *)malloc(sizeof(NodoBST));
    if (nuevo == NULL) {
        return NULL;
    }
    nuevo->dato = cliente;
    nuevo->izquierda = NULL;
    nuevo->derecha = NULL;
    return nuevo;
}

static int insertarRecursivo(NodoBST **raiz, Cliente cliente) {
    if (*raiz == NULL) {
        *raiz = crearNodoBST(cliente);
        return *raiz != NULL;
    }

    if (cliente.id == (*raiz)->dato.id) {
        return 0;
    }
    if (cliente.id < (*raiz)->dato.id) {
        return insertarRecursivo(&(*raiz)->izquierda, cliente);
    }
    return insertarRecursivo(&(*raiz)->derecha, cliente);
}

int insertarCliente(ArbolClientes *arbol, Cliente cliente) {
    if (cliente.id <= 0) {
        printf("Error: el ID debe ser un numero positivo.\n");
        return 0;
    }
    if (clienteExiste(arbol, cliente.id)) {
        printf("Error: ya existe un cliente con el ID %d.\n", cliente.id);
        return 0;
    }
    int insertado = insertarRecursivo(&arbol->raiz, cliente);
    if (insertado) {
        arbol->tamano++;
    }
    return insertado;
}

NodoBST* buscarCliente(ArbolClientes *arbol, int id) {
    NodoBST *actual = arbol->raiz;
    while (actual != NULL) {
        if (id == actual->dato.id) {
            return actual;
        }
        actual = id < actual->dato.id ? actual->izquierda : actual->derecha;
    }
    return NULL;
}

int clienteExiste(ArbolClientes *arbol, int id) {
    return buscarCliente(arbol, id) != NULL;
}
static void imprimirCliente(Cliente cliente) {
    printf("ID: %d | Nombre: %s | Telefono: %s | Correo: %s | Direccion: %s\n",
           cliente.id, cliente.nombre, cliente.telefono, cliente.correo, cliente.direccion);
}

static void inOrderRec(NodoBST *nodo) {
    if (nodo == NULL) {
        return;
    }
    inOrderRec(nodo->izquierda);
    imprimirCliente(nodo->dato);
    inOrderRec(nodo->derecha);
}
static void preOrderRec(NodoBST *nodo) {
    if (nodo == NULL) {
        return;
    }
    imprimirCliente(nodo->dato);
    preOrderRec(nodo->izquierda);
    preOrderRec(nodo->derecha);
}

static void postOrderRec(NodoBST *nodo) {
    if (nodo == NULL) {
        return;
    }
    postOrderRec(nodo->izquierda);
    postOrderRec(nodo->derecha);
    imprimirCliente(nodo->dato);
}


void mostrarInOrder(ArbolClientes *arbol) {
    if (arbol->raiz == NULL) {
        printf("No hay clientes registrados.\n");
        return;
    }
    inOrderRec(arbol->raiz);
}

void mostrarPreOrder(ArbolClientes *arbol) {
    if (arbol->raiz == NULL) {
        printf("No hay clientes registrados.\n");
        return;
    }
    preOrderRec(arbol->raiz);
}

void mostrarPostOrder(ArbolClientes *arbol) {
    if (arbol->raiz == NULL) {
        printf("No hay clientes registrados.\n");
        return;
    }
    postOrderRec(arbol->raiz);
}
static void liberarRec(NodoBST *nodo) {
    if (nodo == NULL) {
        return;
    }
    liberarRec(nodo->izquierda);
    liberarRec(nodo->derecha);
    free(nodo);
}
void liberarBST(ArbolClientes *arbol) {
    liberarRec(arbol->raiz);
    arbol->raiz = NULL;
    arbol->tamano = 0;
}
