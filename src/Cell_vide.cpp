#include "../include/Cell_vide.h"

Cell_vide::Cell_vide(int v) : val(v) {};

// La case noire n'est jamais éditable
bool Cell_vide::isEditable() {
    return true;
}

std::string Cell_vide::afficher(){
   if (val == 0)
        return "  .  ";
    else
        return "  " + std::to_string(val) + "  ";
}

int Cell_vide::getValue() const {
    return val;
}

void Cell_vide::setValue(int value) {
    val = value;
}
