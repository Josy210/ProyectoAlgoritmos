#ifndef FILES_H
#define FILES_H

#include "types.h"
#include "package_list.h"
#include "client_bst.h"
#include "package_avl.h"
#include "routes_graph.h"

// ─── File names ───────────────────────────────────────────────────
#define FILE_CLIENTS   "clients.txt"
#define FILE_PACKAGES  "packages.txt"
#define FILE_ROUTES    "routes.txt"

// ─── Function declarations ────────────────────────────────────────
void saveClients(ClientBST *tree);
void loadClients(ClientBST *tree);

void savePackages(PackageList *list);
void loadPackages(PackageList *list, PackageAVL *avl, ClientBST *bst);

void saveRoutes(RouteGraph *graph);
void loadRoutes(RouteGraph *graph);

#endif // FILES_H
