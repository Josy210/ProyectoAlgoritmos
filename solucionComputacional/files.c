#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "files.h"

static void quitarSaltoLinea(char *texto) {
    texto[strcspn(texto, "\r\n")] = '\0';
}

static void guardarClientesRec(file *archivo, NodoBST *nodo) {
    if (nodo == NULL) {
        return;
    }
    guardarClientesRec(archivo, nodo->izquierda);
    fprintf(archivo, "%d|%s|%s|%s|%s\n",
            nodo->dato.id, nodo->dato.nombre, nodo->dato.telefono,
            nodo->dato.correo, nodo->dato.direccion);
    guardarClientesRec(archivo, nodo->derecha);
}

void guardarClientes(ArbolClientes *arbol) {
    file *archivo = fopen(archivoClientes, "w");
    if (archivo == NULL) {
        printf("No se pudo guardar %s.\n", archivosClientes);
        return;
    }
    guardarClientesRec(archivo, arbol->raiz);
    fclose(archivo);
}

void cargarClientes(ArbolClientes *arbol) {
    file *archivo = fopen(archivoClientes, "r");
    char linea[512];

    if (archivo == NULL) {
        return;
    }

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        Cliente cliente;
        char *token;
        quitarSaltoLinea(linea);

        token = strtok(linea, "|");
        if (token == NULL) {
            continue;
        }
        cliente.id = atoi(token);

        token = strtok(NULL, "|");
        strncpy(cliente.nombre, token == NULL ? "" : token, maxNombre - 1);
        cliente.nombre[maxNombre - 1] = '\0';
        token = strtok(NULL, "|");
        strncpy(cliente.telefono, token == NULL ? "" : token, maxTelefono - 1);
        cliente.telefono[maxTelefono - 1] = '\0';
        token = strtok(NULL, "|");
        strncpy(cliente.correo, token == NULL ? "" : token, maxCorreo - 1);
        cliente.correo[maxCorreo - 1] = '\0';
        token = strtok(NULL, "|");
        strncpy(cliente.direccion, token == NULL ? "" : token, maxDireccion - 1);
        cliente.direccion[maxDireccion - 1] = '\0';

        insertarCliente(arbol, cliente);
    }

    fclose(archivo);
}

// ─── Paquetes ─────────────────────────────────────────────────────

void guardarPaquetes(ListaPaquetes *lista) {
    file *archivo = fopen(archivoPaquetes, "w");
    if (archivo == NULL) {
        printf("No se pudo guardar %s.\n", archivoPaquetes);
        return;
    }

    for (NodoPaquete *actual = lista->cabeza; actual != NULL; actual = actual->siguiente) {
        Paquete p = actual->dato;
        fprintf(archivo, "%s|%d|%s|%s|%.2f|%s|%s\n",
                p.codigo, p.idCliente, p.nombreDestinatario, p.destino,
                p.peso, p.prioridad, p.estado);
    }

    fclose(archivo);
}

void cargarPaquetes(ListaPaquetes *lista, ArbolAVL *avl, ArbolClientes *bst) {
    FILE *archivo = fopen(archivoPaquetes, "r");
    char linea[512];

    if (archivo == NULL) {
        return;
    }

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        Paquete paquete;
        char *token;
        quitarSaltoLinea(linea);

        token = strtok(linea, "|");
        if (token == NULL) {
            continue;
        }
        strncpy(paquete.codigo, token, maxCodigo - 1);
        paquete.codigo[maxCodigo - 1] = '\0';

        token = strtok(NULL, "|");
        paquete.idCliente = token == NULL ? 0 : atoi(token);
        token = strtok(NULL, "|");
        strncpy(paquete.nombreDestinatario, token == NULL ? "" : token, maxNombre - 1);
        paquete.nombreDestinatario[maxNombre - 1] = '\0';
        token = strtok(NULL, "|");
        strncpy(paquete.destino, token == NULL ? "" : token, maxDireccion - 1);
        paquete.destino[maxDireccion - 1] = '\0';
        token = strtok(NULL, "|");
        paquete.peso = token == NULL ? 0.0f : (float)atof(token);
        token = strtok(NULL, "|");
        strncpy(paquete.prioridad, token == NULL ? "" : token, maxPrioridad - 1);
        paquete.prioridad[maxPrioridad - 1] = '\0';
        token = strtok(NULL, "|");
        strncpy(paquete.estado, token == NULL ? "" : token, maxEstado - 1);
        paquete.estado[maxEstado - 1] = '\0';

        if (clienteExiste(bst, paquete.idCliente) && insertarPaquete(lista, paquete)) {
            insertarPaqueteAVL(avl, paquete);
        }
    }

    fclose(archivo);
}

void guardarRutas(GrafoRutas *grafo) {
    FILE *archivo = fopen(archivoRutas, "w");
    if (archivo == NULL) {
        printf("No se pudo guardar %s.\n", archivoRutas);
        return;
    }

    fprintf(archivo, "%d\n", grafo->numPuntos);
    for (int i = 0; i < grafo->numPuntos; i++) {
        fprintf(archivo, "%s\n", grafo->nombresPuntos[i]);
    }
    for (int i = 0; i < grafo->numPuntos; i++) {
        for (int j = 0; j < grafo->numPuntos; j++) {
            fprintf(archivo, "%d", grafo->matrizAdyacencia[i][j]);
            if (j < grafo->numPuntos - 1) {
                fprintf(archivo, "|");
            }
        }
        fprintf(archivo, "\n");
    }

    fclose(archivo);
}

void cargarRutas(GrafoRutas *grafo) {
    FILE *archivo = fopen(archivoRutas, "r");
    char linea[512];
    int cantidad;

    if (archivo == NULL) {
        return;
    }

    if (fgets(linea, sizeof(linea), archivo) == NULL) {
        fclose(archivo);
        return;
    }
    cantidad = atoi(linea);
    if (cantidad < 0 || cantidad > maxPuntos) {
        fclose(archivo);
        return;
    }

    inicializarGrafo(grafo);
    for (int i = 0; i < cantidad; i++) {
        if (fgets(linea, sizeof(linea), archivo) == NULL) {
            fclose(archivo);
            return;
        }
        quitarSaltoLinea(linea);
        agregarPunto(grafo, linea);
    }

    for (int i = 0; i < cantidad; i++) {
        if (fgets(linea, sizeof(linea), archivo) == NULL) {
            break;
        }
        quitarSaltoLinea(linea);
        char *token = strtok(linea, "|");
        for (int j = 0; j < cantidad && token != NULL; j++) {
            grafo->matrizAdyacencia[i][j] = atoi(token);
            token = strtok(NULL, "|");
        }
    }

    fclose(archivo);
}
