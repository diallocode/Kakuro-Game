#include "../include/JsonCellFactory.h"
#include "../include/Cell_noir.h"
#include "../include/Cell_sum.h"
#include "../include/Cell_vide.h"

Cells* JsonCellFactory::createCell(const std::string& token) {
    if (token == "#") {
        return new Cell_noir();
    } 
    else if (token == "_") {
        return new Cell_vide(0);
    } 
    else if (token.find('/') != std::string::npos) {
        int down = 0, right = 0;
        size_t slash = token.find('/');
        std::string left = token.substr(0, slash);
        std::string rightStr = token.substr(slash + 1);

        if (!left.empty()) down = std::stoi(left);
        if (!rightStr.empty()) right = std::stoi(rightStr);

        return new Cell_sum(down, right);
    } 
    else {
        // C'est une valeur numérique fixe
        int val = std::stoi(token);
        return new Cell_vide(val);
    }
}
