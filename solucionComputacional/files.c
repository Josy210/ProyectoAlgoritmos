#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "files.h"

// ─── Clients ──────────────────────────────────────────────────────

void saveClients(ClientBST *tree) {
    // TODO: traverse BST inorder and write each client to FILE_CLIENTS
}

void loadClients(ClientBST *tree) {
    // TODO: read FILE_CLIENTS line by line and insert each client into BST
}

// ─── Packages ─────────────────────────────────────────────────────

void savePackages(PackageList *list) {
    // TODO: traverse list and write each package to FILE_PACKAGES
}

void loadPackages(PackageList *list, PackageAVL *avl, ClientBST *bst) {
    // TODO: read FILE_PACKAGES and insert each package into list and AVL
    // Validate that the client exists in BST before inserting
}

// ─── Routes ───────────────────────────────────────────────────────

void saveRoutes(RouteGraph *graph) {
    // TODO: write points and adjacency matrix to FILE_ROUTES
}

void loadRoutes(RouteGraph *graph) {
    // TODO: read FILE_ROUTES and rebuild the graph
}
