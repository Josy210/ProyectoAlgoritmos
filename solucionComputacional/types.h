#ifndef TYPES_H
#define TYPES_H

// ─── Package states ───────────────────────────────────────────────
#define STATE_REGISTERED     "Registered"
#define STATE_PENDING        "Pending"
#define STATE_IN_ROUTE       "In Route"
#define STATE_DELIVERED      "Delivered"
#define STATE_RETURNED       "Returned"

// ─── Priority levels ──────────────────────────────────────────────
#define PRIORITY_LOW         "Low"
#define PRIORITY_MEDIUM      "Medium"
#define PRIORITY_HIGH        "High"

// ─── Field sizes ──────────────────────────────────────────────────
#define MAX_CODE        20
#define MAX_NAME        100
#define MAX_PHONE       20
#define MAX_EMAIL       100
#define MAX_ADDRESS     150
#define MAX_STATE       30
#define MAX_PRIORITY    10

// ─── Client structure ─────────────────────────────────────────────
typedef struct {
    int id;
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    char email[MAX_EMAIL];
    char address[MAX_ADDRESS];
} Client;

// ─── Package structure ────────────────────────────────────────────
typedef struct {
    char code[MAX_CODE];
    int  clientId;
    char recipientName[MAX_NAME];
    char destination[MAX_ADDRESS];
    float weight;
    char priority[MAX_PRIORITY];
    char state[MAX_STATE];
} Package;

#endif // TYPES_H
