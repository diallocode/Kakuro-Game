#include "../include/Cell_noir.h"

// La case noire n'est jamais éditable
bool Cell_noir::isEditable() {
    return false;
}