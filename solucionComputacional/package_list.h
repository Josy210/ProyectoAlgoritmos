#ifndef PACKAGE_LIST_H
#define PACKAGE_LIST_H

#include "types.h"

// ─── Node of the linked list ──────────────────────────────────────
typedef struct PackageNode {
    Package data;
    struct PackageNode *next;
} PackageNode;

// ─── Linked list ──────────────────────────────────────────────────
typedef struct {
    PackageNode *head;
    int size;
} PackageList;

// ─── Function declarations ────────────────────────────────────────
void initPackageList(PackageList *list);
int  insertPackage(PackageList *list, Package pkg);
PackageNode* searchPackageByCode(PackageList *list, const char *code);
int  updatePackageState(PackageList *list, const char *code, const char *newState);
int  deletePackage(PackageList *list, const char *code);
void displayAllPackages(PackageList *list);
void countPackagesByState(PackageList *list);
void freePackageList(PackageList *list);

#endif // PACKAGE_LIST_H
