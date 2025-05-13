#include "../include/Cell_sum.h"

Cell_sum::Cell_sum(int right, int down) : horizontale(right), verticale(down) {};

bool Cell_sum::isEditable() {
    return false;
}

std::string Cell_sum::afficher() {
    std::string affichage;
    std::string bas = (verticale >= 0) ? std::to_string(verticale) : "";
    std::string droite = (horizontale >= 0) ? std::to_string(horizontale) : "";

    affichage = bas + "/" + droite;

    // Pour bien centrer et homogénéiser sur 7 caractères
    int totalLength = affichage.length();
    int padding = (7 - totalLength) / 2;
    affichage = std::string(padding, ' ') + affichage + std::string(7 - padding - totalLength, ' ');

    return "\033[33m" + affichage + "\033[0m";
}

int Cell_sum::getSumVerticale(){
    return verticale;
}

int Cell_sum::getsumHorizontale(){
    return horizontale;
}
