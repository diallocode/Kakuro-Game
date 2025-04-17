#include "../include/Grille.h"

// Constructeur : crée une matrice de nullptr
Grille::Grille(int r, int c) : rows(r), cols(c) {
    cells.resize(rows, std::vector<Cells*>(cols, nullptr));
}


// Accesseur
Cells* Grille::getCell(int i, int j) const {
    if (i >= 0 && i < rows && j >= 0 && j < cols)
        return cells[i][j];
    return nullptr;
}

// Mutateur
void Grille::setCell(int i, int j, Cells* cell) {
    if (i >= 0 && i < rows && j >= 0 && j < cols)
        cells[i][j] = cell;
}

// Affichage simple : on montre des symboles pour voir le contenu
void Grille::afficher() const {
    std::string ligneSep = "+" + std::string(cols * 8, '-') + "+";
    std::cout << ligneSep << "\n";

    for (int i = 0; i < rows; ++i) {
        std::cout << "|";
        for (int j = 0; j < cols; ++j) {
            if (cells[i][j])
                std::cout << std::setw(7) << cells[i][j]->afficher() << "|";
            else
                std::cout << std::setw(7) << "#######" << "|";
        }
        std::cout << "\n" << ligneSep << "\n";
    }
}

// Destructeur
Grille::~Grille() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            delete cells[i][j];
        }
    }
}


int Grille::getRows() const {
    return rows;
}

int Grille::getCols() const {
    return cols;
}