#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int opcion;
    do {
        printf("\n===== GESTIONAR CLIENTES =====\n");
        printf("1. Registrar cliente\n");
        printf("2. Buscar cliente\n");
        printf("3. Mostrar clientes (InOrder)\n");
        printf("4. Mostrar clientes (PreOrder)\n");
        printf("5. Mostrar clientes (PostOrder)\n");
        printf("0. Volver\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                Cliente c;
                printf("ID: ");
                scanf("%d", &c.id);
                printf("Nombre: ");
                scanf(" %[^\n]", c.nombre);
                printf("Telefono: ");
                scanf(" %[^\n]", c.telefono);
                printf("Correo: ");
                scanf(" %[^\n]", c.correo);
                printf("Direccion: ");
                scanf(" %[^\n]", c.direccion);
                insertarCliente(&arbolClientes, c);
                break;
            }
            case 2: {
                int id;
                printf("ID a buscar: ");
                scanf("%d", &id);
                NodoBST *resultado = buscarCliente(&arbolClientes, id);
                if (resultado != NULL) {
                    printf("Cliente encontrado:\n");
                    printf("Nombre: %s\n", resultado->dato.nombre);
                    printf("Telefono: %s\n", resultado->dato.telefono);
                    printf("Correo: %s\n", resultado->dato.correo);
                    printf("Direccion: %s\n", resultado->dato.direccion);
                } else {
                    printf("Cliente no encontrado.\n");
                }
                break;
            }
            case 3: mostrarInOrder(&arbolClientes);   break;
            case 4: mostrarPreOrder(&arbolClientes);  break;
            case 5: mostrarPostOrder(&arbolClientes); break;
            case 0: break;
            default: printf("Opcion invalida.\n");
        }
    } while (opcion != 0);
}

void menuPaquetes() {
    int opcion;
    do {
        printf("\n===== GESTIONAR PAQUETES =====\n");
        printf("1. Registrar paquete\n");
        printf("2. Mostrar todos los paquetes\n");
        printf("3. Buscar paquete por codigo\n");
        printf("4. Actualizar estado de paquete\n");
        printf("5. Eliminar paquete\n");
        printf("0. Volver\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                Paquete p;
                printf("Codigo: ");
                scanf(" %[^\n]", p.codigo);
                printf("ID Cliente: ");
                scanf("%d", &p.idCliente);
                if (!clienteExiste(&arbolClientes, p.idCliente)) {
                    printf("Error: el cliente no existe.\n");
                    break;
                }
                printf("Nombre destinatario: ");
                scanf(" %[^\n]", p.nombreDestinatario);
                printf("Destino: ");
                scanf(" %[^\n]", p.destino);
                printf("Peso (kg): ");
                scanf("%f", &p.peso);
                printf("Prioridad (Baja/Media/Alta): ");
                scanf(" %[^\n]", p.prioridad);
                strcpy(p.estado, ESTADO_REGISTRADO);
                if (insertarPaquete(&listaPaquetes, p))
                    insertarPaqueteAVL(&arbolAVL, p);
                break;
            }
            case 2:
                mostrarTodosPaquetes(&listaPaquetes);
                break;
            case 3: {
                char codigo[MAX_CODIGO];
                printf("Codigo a buscar: ");
                scanf(" %[^\n]", codigo);
                NodoPaquete *resultado = buscarPaquetePorCodigo(&listaPaquetes, codigo);
                if (resultado != NULL) {
                    printf("Codigo:        %s\n", resultado->dato.codigo);
                    printf("Destinatario:  %s\n", resultado->dato.nombreDestinatario);
                    printf("Destino:       %s\n", resultado->dato.destino);
                    printf("Peso:          %.2f kg\n", resultado->dato.peso);
                    printf("Prioridad:     %s\n", resultado->dato.prioridad);
                    printf("Estado:        %s\n", resultado->dato.estado);
                } else {
                    printf("Paquete no encontrado.\n");
                }
                break;
            }
            case 4: {
                char codigo[MAX_CODIGO];
                char nuevoEstado[MAX_ESTADO];
                printf("Codigo del paquete: ");
                scanf(" %[^\n]", codigo);
                printf("Nuevo estado: ");
                scanf(" %[^\n]", nuevoEstado);
                actualizarEstadoPaquete(&listaPaquetes, codigo, nuevoEstado);
                break;
            }
            case 5: {
                char codigo[MAX_CODIGO];
                printf("Codigo a eliminar: ");
                scanf(" %[^\n]", codigo);
                eliminarPaquete(&listaPaquetes, codigo);
                break;
            }
            case 0: break;
            default: printf("Opcion invalida.\n");
        }
    } while (opcion != 0);
}

void menuEntregas() {
    int opcion;
    do {
        printf("\n===== COLA DE ENTREGAS =====\n");
        printf("1. Encolar paquete\n");
        printf("2. Ver siguiente paquete\n");
        printf("3. Mostrar cola completa\n");
        printf("4. Procesar siguiente entrega\n");
        printf("0. Volver\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                char codigo[MAX_CODIGO];
                printf("Codigo del paquete a encolar: ");
                scanf(" %[^\n]", codigo);
                NodoPaquete *nodo = buscarPaquetePorCodigo(&listaPaquetes, codigo);
                if (nodo == NULL) {
                    printf("Error: paquete no encontrado.\n");
                    break;
                }
                actualizarEstadoPaquete(&listaPaquetes, codigo, ESTADO_PENDIENTE);
                nodo->dato.estado[0] = '\0';
                strcpy(nodo->dato.estado, ESTADO_PENDIENTE);
                enqueue(&colaEntregas, nodo->dato);
                printf("Paquete encolado correctamente.\n");
                break;
            }
            case 2: {
                int exito;
                Paquete p = peekCola(&colaEntregas, &exito);
                if (exito)
                    printf("Siguiente: %s -> %s\n", p.codigo, p.destino);
                else
                    printf("La cola esta vacia.\n");
                break;
            }
            case 3:
                mostrarCola(&colaEntregas);
                break;
            case 4: {
                int exito;
                Paquete p = dequeue(&colaEntregas, &exito);
                if (!exito) {
                    printf("La cola esta vacia.\n");
                    break;
                }
                printf("Procesando entrega de %s a %s\n", p.codigo, p.destino);
                printf("¿Fue exitosa la entrega? (1=Si / 0=No): ");
                int respuesta;
                scanf("%d", &respuesta);
                if (respuesta == 1) {
                    actualizarEstadoPaquete(&listaPaquetes, p.codigo, ESTADO_ENTREGADO);
                    printf("Entrega exitosa.\n");
                } else {
                    actualizarEstadoPaquete(&listaPaquetes, p.codigo, ESTADO_DEVUELTO);
                    strcpy(p.estado, ESTADO_DEVUELTO);
                    apilar(&pilaDevoluciones, p);
                    printf("Paquete enviado a devoluciones.\n");
                }
                break;
            }
            case 0: break;
            default: printf("Opcion invalida.\n");
        }
    } while (opcion != 0);
}

void menuDevoluciones() {
    int opcion;
    do {
        printf("\n===== DEVOLUCIONES =====\n");
        printf("1. Ver ultimo paquete devuelto\n");
        printf("2. Mostrar todos los devueltos\n");
        printf("3. Reprocesar ultimo devuelto\n");
        printf("0. Volver\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                int exito;
                Paquete p = peekPila(&pilaDevoluciones, &exito);
                if (exito)
                    printf("Ultimo devuelto: %s -> %s\n", p.codigo, p.destino);
                else
                    printf("No hay paquetes devueltos.\n");
                break;
            }
            case 2:
                mostrarPila(&pilaDevoluciones);
                break;
            case 3: {
                int exito;
                Paquete p = desapilar(&pilaDevoluciones, &exito);
                if (!exito) {
                    printf("No hay paquetes devueltos.\n");
                    break;
                }
                actualizarEstadoPaquete(&listaPaquetes, p.codigo, ESTADO_PENDIENTE);
                strcpy(p.estado, ESTADO_PENDIENTE);
                enqueue(&colaEntregas, p);
                printf("Paquete %s reencolado correctamente.\n", p.codigo);
                break;
            }
            case 0: break;
            default: printf("Opcion invalida.\n");
        }
    } while (opcion != 0);
}

void menuRutas() {
    int opcion;
    do {
        printf("\n===== RUTAS =====\n");
        printf("1. Agregar punto de entrega\n");
        printf("2. Agregar ruta entre puntos\n");
        printf("3. Mostrar puntos disponibles\n");
        printf("4. Mostrar matriz de adyacencia\n");
        printf("5. Calcular ruta mas corta\n");
        printf("0. Volver\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                char nombre[MAX_NOMBRE_PUNTO];
                printf("Nombre del punto: ");
                scanf(" %[^\n]", nombre);
                agregarPunto(&grafoRutas, nombre);
                break;
            }
            case 2: {
                char origen[MAX_NOMBRE_PUNTO];
                char destino[MAX_NOMBRE_PUNTO];
                int peso;
                mostrarPuntos(&grafoRutas);
                printf("Origen: ");
                scanf(" %[^\n]", origen);
                printf("Destino: ");
                scanf(" %[^\n]", destino);
                printf("Distancia (km): ");
                scanf("%d", &peso);
                agregarRuta(&grafoRutas, origen, destino, peso);
                break;
            }
            case 3:
                mostrarPuntos(&grafoRutas);
                break;
            case 4:
                mostrarMatrizAdyacencia(&grafoRutas);
                break;
            case 5: {
                char origen[MAX_NOMBRE_PUNTO];
                char destino[MAX_NOMBRE_PUNTO];
                mostrarPuntos(&grafoRutas);
                printf("Origen: ");
                scanf(" %[^\n]", origen);
                printf("Destino: ");
                scanf(" %[^\n]", destino);
                dijkstra(&grafoRutas, origen, destino);
                break;
            }
            case 0: break;
            default: printf("Opcion invalida.\n");
        }
    } while (opcion != 0);
}

void menuReportes() {
    int opcion;
    do {
        printf("\n===== REPORTES =====\n");
        printf("1. Total de paquetes por estado\n");
        printf("2. Clientes registrados\n");
        printf("3. Paquetes ordenados por codigo (AVL)\n");
        printf("4. Ruta mas corta entre dos puntos\n");
        printf("0. Volver\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                contarPaquetesPorEstado(&listaPaquetes);
                break;
            case 2:
                mostrarInOrder(&arbolClientes);
                break;
            case 3:
                mostrarAVLInOrder(&arbolAVL);
                break;
            case 4: {
                char origen[MAX_NOMBRE_PUNTO];
                char destino[MAX_NOMBRE_PUNTO];
                mostrarPuntos(&grafoRutas);
                printf("Ingrese origen: ");
                scanf("%s", origen);
                printf("Ingrese destino: ");
                scanf("%s", destino);
                dijkstra(&grafoRutas, origen, destino);
                break;
            }
            case 0:
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 0);
}
