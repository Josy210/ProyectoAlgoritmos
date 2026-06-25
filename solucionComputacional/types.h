#ifndef TYPES_H
#define TYPES_H

// ─── Estados del paquete ──────────────────────────────────────────
#define ESTADO_REGISTRADO        "Registrado"
#define ESTADO_PENDIENTE         "Pendiente de entrega"
#define ESTADO_EN_RUTA           "En ruta"
#define ESTADO_ENTREGADO         "Entregado"
#define ESTADO_DEVUELTO          "Devuelto"

// ─── Niveles de prioridad ─────────────────────────────────────────
#define PRIORIDAD_BAJA           "Baja"
#define PRIORIDAD_MEDIA          "Media"
#define PRIORIDAD_ALTA           "Alta"

// ─── Tamaños de campos ────────────────────────────────────────────
#define MAX_CODIGO       20
#define MAX_NOMBRE       100
#define MAX_TELEFONO     20
#define MAX_CORREO       100
#define MAX_DIRECCION    150
#define MAX_ESTADO       30
#define MAX_PRIORIDAD    10

// ─── Estructura Cliente ───────────────────────────────────────────
typedef struct {
    int id;
    char nombre[MAX_NOMBRE];
    char telefono[MAX_TELEFONO];
    char correo[MAX_CORREO];
    char direccion[MAX_DIRECCION];
} Cliente;

// ─── Estructura Paquete ───────────────────────────────────────────
typedef struct {
    char codigo[MAX_CODIGO];
    int  idCliente;
    char nombreDestinatario[MAX_NOMBRE];
    char destino[MAX_DIRECCION];
    float peso;
    char prioridad[MAX_PRIORIDAD];
    char estado[MAX_ESTADO];
} Paquete;

#endif // TYPES_H
