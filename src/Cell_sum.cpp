#include "../include/Cell_sum.h"

// Constructeur
Cell_sum::Cell_sum(int right, int down) : horizontale(right), verticale(down) {};

// Méthode pour savoir si la case est éditable
bool Cell_sum::isEditable() {
    return false; // Les cases de somme ne sont jamais éditables
}

std::string Cell_sum::afficher(){
    std::string top = (verticale >= 0) ? "↓" + std::to_string(verticale) : "   ";
    std::string right = (horizontale >= 0) ? "→" + std::to_string(horizontale) : "   ";

    // Format : ↓16 ou →23 → aligné sur 4 ou 5 caractères
    return top + "/" + right;
}
