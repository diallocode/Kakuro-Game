#include "../include/Cell_vide.h"

Cell_vide::Cell_vide(int v) : val(v) {};

// La case noire n'est jamais éditable
bool Cell_vide::isEditable() {
    return true;
}

void Cell_vide::afficher(){
    std::cout << " " ;
}