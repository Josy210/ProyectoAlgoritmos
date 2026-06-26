#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "package_avl.h"

void inicializarAVL(ArbolAVL *arbol) {
    arbol->raiz = NULL;
    arbol->tamano = 0;
}

// Retorna altura del nodo
int obtenerAltura(NodoAVL *nodo) {
    if (nodo == NULL) return 0;
    return nodo->altura;
}

// Retorna factor de balance: altura izquierda - altura derecha
int obtenerFactorBalance(NodoAVL *nodo) {
    if (nodo == NULL) return 0;
    return obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha);
}

void actualizarAltura(NodoAVL *nodo) {
    if (nodo == NULL) return;
    int altIzq = obtenerAltura(nodo->izquierda);
    int altDer = obtenerAltura(nodo->derecha);
    nodo->altura = 1 + (altIzq > altDer ? altIzq : altDer);
}

// Rotación simple a la derecha
NodoAVL* rotarDerecha(NodoAVL *y) {
    NodoAVL *x = y->izquierda;
    NodoAVL *subarbol = x->derecha;

    x->derecha = y;
    y->izquierda = subarbol;

    actualizarAltura(y);
    actualizarAltura(x);
    return x;
}

// Rotación simple a la izquierda
NodoAVL* rotarIzquierda(NodoAVL *x) {
    NodoAVL *y = x->derecha;
    NodoAVL *subarbol = y->izquierda;

    y->izquierda = x;
    x->derecha = subarbol;

    actualizarAltura(x);
    actualizarAltura(y);
    return y;
}

// Rotación doble izquierda-derecha
NodoAVL* rotarIzquierdaDerecha(NodoAVL *nodo) {
    nodo->izquierda = rotarIzquierda(nodo->izquierda);
    return rotarDerecha(nodo);
}

// Rotación doble derecha-izquierda
NodoAVL* rotarDerechaIzquierda(NodoAVL *nodo) {
    nodo->derecha = rotarDerecha(nodo->derecha);
    return rotarIzquierda(nodo);
}

// Rebalancea el nodo luego de una inserción
NodoAVL* balancear(NodoAVL *nodo) {
    actualizarAltura(nodo);
    int factor = obtenerFactorBalance(nodo);

    if (factor > 1) {
        if (obtenerFactorBalance(nodo->izquierda) >= 0)
            return rotarDerecha(nodo);
        else
            return rotarIzquierda(nodo);
    }

    return nodo;
}
static NodoAVL* insertarNodo(NodoAVL *nodo, Paquete paquete, int *exito) {
    if (nodo == NULL) {
        NodoAVL *nuevo = (NodoAVL*)malloc(sizeof(NodoAVL));
        if (nuevo == NULL) {
            printf("Error: no hay memoria disponible\n");
            *exito = 0;
            return NULL;
        }
        nuevo->dato = paquete;
        nuevo->izquierda = NULL;
        nuevo->derecha = NULL;
        nuevo->altura = 1;
        *exito = 1;
        return nuevo;
    }
    int comparacion = strcmp(paquete.codigo, nodo->dato.codigo);

    if (comparacion < 0)
        nodo->izquierda = insertarNodo(nodo->izquierda, paquete, exito);
    else if (comparacion > 0)
        nodo->derecha = insertarNodo(nodo->derecha, paquete, exito);
    else {
        printf("Error: ya existe un paquete con el codigo %s\n", paquete.codigo);
        *exito = 0;
        return nodo;
    }
    return balancear(nodo);
}

// Inserta paquete en el AVL
int insertarPaqueteAVL(ArbolAVL *arbol, Paquete paquete) {
    int exito = 0;
    arbol->raiz = insertarNodo(arbol->raiz, paquete, &exito);
    if (exito) arbol->tamano++;
    return exito;
}


// Busca paquete por código - retorna nodo o NULL
NodoAVL* buscarPaqueteAVL(ArbolAVL *arbol, const char *codigo) {    NodoAVL *actual = arbol->raiz;
    while (actual != NULL) {
        int comparacion = strcmp(codigo, actual->dato.codigo);
        if (comparacion == 0)
            return actual;
        else if (comparacion < 0)
            actual = actual->izquierda;
        else
            actual = actual->derecha;
    }
    return NULL;
}

static void inOrder(NodoAVL *nodo, int *contador) {
    if (nodo == NULL) return;
    inOrder(nodo->izquierda, contador);
    (*contador)++;
    printf("--- Paquete %d ---\n", *contador);
    printf("Codigo:        %s\n", nodo->dato.codigo);
    printf("ID Cliente:    %d\n", nodo->dato.idCliente);
    printf("Destinatario:  %s\n", nodo->dato.nombreDestinatario);
    printf("Destino:       %s\n", nodo->dato.destino);
    printf("Peso:          %.2f kg\n", nodo->dato.peso);
    printf("Prioridad:     %s\n", nodo->dato.prioridad);
    printf("Estado:        %s\n", nodo->dato.estado);
    printf("\n");
    inOrder(nodo->derecha, contador);
}

// Muestra paquetes en orden por código
void mostrarAVLInOrder(ArbolAVL *arbol) {
    if (arbol->raiz == NULL) {
        printf("No hay paquetes en el AVL.\n");
        return;
    }
    printf("\n===== PAQUETES ORDENADOS POR CODIGO =====\n");
    int contador = 0;
    inOrder(arbol->raiz, &contador);
    printf("Total: %d paquete(s)\n", arbol->tamano);
}

static void liberarNodos(NodoAVL *nodo) {
    if (nodo == NULL) return;
    liberarNodos(nodo->izquierda);
    liberarNodos(nodo->derecha);
    free(nodo);
}

void liberarAVL(ArbolAVL *arbol) {
    liberarNodos(arbol->raiz);
    arbol->raiz = NULL;
    arbol->tamano = 0;
}
