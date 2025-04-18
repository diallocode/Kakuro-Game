#include "../include/Cell_sum.h"

// Constructeur
Cell_sum::Cell_sum(int right, int down) : horizontale(right), verticale(down) {};

// Méthode pour savoir si la case est éditable
bool Cell_sum::isEditable() {
    return false; // Les cases de somme ne sont jamais éditables
}

std::string Cell_sum::afficher() {
    std::string affichage;

    if (verticale >= 0 && horizontale >= 0) {
        affichage = " ↓" + std::to_string(verticale) + "/" + "→" + std::to_string(horizontale) + " ";
    } 
    else if (verticale >= 0) {
        affichage = " ↓" + std::to_string(verticale) + "/   ";
    } 
    else if (horizontale >= 0) {
        affichage = "    /→" + std::to_string(horizontale);
    } 
    else {
        affichage = "        "; // aucun indice (très rare)
    }

    return "\033[33m" + affichage + "\033[0m";  // Jaune
}




int Cell_sum::getSumVerticale(){
    return verticale;
}

int Cell_sum::getsumHorizontale(){
    return horizontale;
}
