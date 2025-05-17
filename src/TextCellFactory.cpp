#include "../include/TextCellFactory.h"

Cells* TextCellFactory::createCell(const std::string& token) {
    if (token == "#") {
        return new Cell_noir();
    } 
    else if (token == "_") {
        return new Cell_vide(0);
    } 
    else if (token.find('/') != std::string::npos) { // Somme B/D
        int sumDown = -1, sumRight = -1;

        size_t slashPos = token.find('/');
        std::string downStr  = token.substr(0, slashPos);   // ↓
        std::string rightStr = token.substr(slashPos + 1);  // →

        if (!downStr.empty()) {
            try {
                sumDown = std::stoi(downStr);
            } catch (...) {}
        }

        if (!rightStr.empty()) {
            try {
                sumRight = std::stoi(rightStr);
            } catch (...) {}
        }

        return new Cell_sum(sumRight, sumDown); // toujours right, down
    }

    else if (std::all_of(token.begin(), token.end(), ::isdigit)) {
        // Nombre entier détecté → valeur fixe
        int val = std::stoi(token);
        return new Cell_vide(val);
    }

    // Par défaut : cellule noire si on ne comprend pas
    return new Cell_noir();
}
