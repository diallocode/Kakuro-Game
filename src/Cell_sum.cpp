#include "../include/Cell_sum.h"

// Constructeur
Cell_sum::Cell_sum(int right, int down) : horizontale(right), verticale(down) {};

// Méthode pour savoir si la case est éditable
bool Cell_sum::isEditable() {
    return false; // Les cases de somme ne sont jamais éditables
}

std::string Cell_sum::afficher(){
    std::string down = (verticale >= 0) ? "→" + std::to_string(verticale) : "  ";
    std::string right = (horizontale >= 0) ? "↓" + std::to_string(horizontale) : "  ";
    
    std::stringstream ss;
    ss << std::setw(2) << down << "/" << std::setw(3) << right;
    return "\033[33m" + ss.str() + "\033[0m";  // Jaune ANSI
}

int Cell_sum::getSumVerticale(){
    return verticale;
}

int Cell_sum::getsumHorizontale(){
    return horizontale;
}
