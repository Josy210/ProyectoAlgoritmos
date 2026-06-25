#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "package_list.h"
#include "delivery_queue.h"
#include "returns_stack.h"
#include "client_bst.h"
#include "package_avl.h"
#include "routes_graph.h"
#include "files.h"

// ─── Estructuras globales ─────────────────────────────────────────
ListaPaquetes   listaPaquetes;
ColaPendientes  colaEntregas;
PilaDevoluciones pilaDevoluciones;
ArbolClientes   arbolClientes;
ArbolAVL        arbolAVL;
GrafoRutas      grafoRutas;

// ─── Prototipos de submenús ───────────────────────────────────────
void menuClientes();
void menuPaquetes();
void menuEntregas();
void menuDevoluciones();
void menuRutas();
void menuReportes();

// ─── Menú principal ───────────────────────────────────────────────
int main(void) {
    // Inicializar todas las estructuras
    inicializarListaPaquetes(&listaPaquetes);
    inicializarCola(&colaEntregas);
    inicializarPila(&pilaDevoluciones);
    inicializarBST(&arbolClientes);
    inicializarAVL(&arbolAVL);
    inicializarGrafo(&grafoRutas);

    // Cargar datos desde archivos
    cargarClientes(&arbolClientes);
    cargarPaquetes(&listaPaquetes, &arbolAVL, &arbolClientes);
    cargarRutas(&grafoRutas);

    int opcion;
    do {
        printf("\n========== ROUTEPACK ==========\n");
        printf("1. Gestionar clientes\n");
        printf("2. Gestionar paquetes\n");
        printf("3. Cola de entregas\n");
        printf("4. Devoluciones\n");
        printf("5. Rutas\n");
        printf("6. Reportes\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: menuClientes();     break;
            case 2: menuPaquetes();     break;
            case 3: menuEntregas();     break;
            case 4: menuDevoluciones(); break;
            case 5: menuRutas();        break;
            case 6: menuReportes();     break;
            case 0:
                guardarClientes(&arbolClientes);
                guardarPaquetes(&listaPaquetes);
                guardarRutas(&grafoRutas);
                printf("Hasta luego!\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 0);

    // Liberar memoria
    liberarListaPaquetes(&listaPaquetes);
    liberarCola(&colaEntregas);
    liberarPila(&pilaDevoluciones);
    liberarBST(&arbolClientes);
    liberarAVL(&arbolAVL);

    return 0;
}

// ─── Submenús (TODO: implementar cada opción) ─────────────────────

void menuClientes() {
    // TODO: insertar, buscar, mostrar inorder/preorder/postorder
}

void menuPaquetes() {
    // TODO: registrar, mostrar, buscar, actualizar estado, eliminar
}

void menuEntregas() {
    // TODO: encolar, peekCola, procesar (dequeue + preguntar si fue exitosa)
}

void menuDevoluciones() {
    // TODO: mostrar pila, peekPila, desapilar y reencolar
}

void menuRutas() {
    // TODO: agregar punto, agregar ruta, mostrar puntos, mostrar matriz, ruta más corta
}

void menuReportes() {
    // TODO: totales por estado, clientes en BST, paquetes en AVL, ruta más corta
}
