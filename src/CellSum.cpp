#include "../include/Cell_sum.h"
#include <sstream>

// Constructeur
Cell_sum::Cell_sum(int right, int down) : horizontale(right), verticale(down) {}

// Méthode pour savoir si la case est éditable
bool Cell_sum::isEditable() {
    return false; // Les cases de somme ne sont jamais éditables
}