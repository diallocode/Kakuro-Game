#include "../include/TextCellFactory.h"

Cells* TextCellFactory::createCell(const std::string& token) {
    if (token == "X") {
        return new Cell_noir();
    } 
    else if (token == "U-" || token == "U") {
        return new Cell_vide(0);
    } 
    else if (token[0] == 'U' && token.size() > 1 && isdigit(token[1])) {
        int value = std::stoi(token.substr(1));
        return new Cell_vide(value); // avec valeur initiale
    } 
    else if (token.rfind("I-", 0) == 0) { // commence par "I-"
        // Exemple : I-/45 ou I-23/-
        std::string content = token.substr(2); // on enlève "I-"
        int sumDown = -1, sumRight = -1;

        size_t slashPos = content.find('/');
        if (slashPos != std::string::npos) {
            std::string downStr = content.substr(0, slashPos);
            std::string rightStr = content.substr(slashPos + 1);

            if (!downStr.empty() && downStr != "-")
                sumDown = std::stoi(downStr);
            if (!rightStr.empty() && rightStr != "-")
                sumRight = std::stoi(rightStr);
        }

        return new Cell_sum(sumRight, sumDown);
    }

    // Par défaut, on retourne une case noire (sécurité)
    return new Cell_noir();
}
