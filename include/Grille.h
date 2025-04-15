#ifndef GRILLE_H
#define GRILLE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Cells.h"

class Grille {
private:
    std::vector<std::vector<Cells*>> cells;
    int rows, cols;

public:
    // Constructeur qui crée une grille vide (remplie de nullptr par défaut)
    explicit Grille(int r, int c);

    // Accesseurs de taille
    int getRows() const;
    int getCols() const;

    // Accès aux cases
    Cells* getCell(int i, int j) const;
    void setCell(int i, int j, Cells* cell);

    // Affichage simple (pour tester)
    void afficher() const;

    // Destructeur pour nettoyer la mémoire
    ~Grille();
};

#endif
