#include "../include/Cell_noir.h"

// La case noire n'est jamais éditable
bool Cell_noir::isEditable() {
    return false;
}

std::string Cell_noir::afficher(){
    return "\033[30;47m       \033[0m"; // 7 caractères, visuellement homogène avec les autres
}
