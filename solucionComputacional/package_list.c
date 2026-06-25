#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "package_list.h"

// Initialize empty list
void initPackageList(PackageList *list) {
    // TODO
}

// Insert package - returns 1 if success, 0 if duplicate code
int insertPackage(PackageList *list, Package pkg) {
    // TODO
    return 0;
}

// Search package by code - returns node or NULL
PackageNode* searchPackageByCode(PackageList *list, const char *code) {
    // TODO
    return NULL;
}

// Update package state - returns 1 if success, 0 if not found
int updatePackageState(PackageList *list, const char *code, const char *newState) {
    // TODO
    return 0;
}

// Delete package - returns 1 if success, 0 if not found
int deletePackage(PackageList *list, const char *code) {
    // TODO
    return 0;
}

// Display all packages
void displayAllPackages(PackageList *list) {
    // TODO
}

// Count and display packages grouped by state
void countPackagesByState(PackageList *list) {
    // TODO
}

// Free all memory
void freePackageList(PackageList *list) {
    // TODO
}
