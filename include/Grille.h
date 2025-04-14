#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Cells.h"


// s’occupe exclusivement du plateau (chargement, affichage, accès aux cases).


class Grille
{
private:
    /* kakuro grid */
    std::vector<std::vector<Cells*>> cells;
    int rows, cols;
public:
    explicit Grille(int r, int c): rows(r), cols(c) {};
    void loadFromFile(const std::string& filename); // pour charger la grille depuis le fichier

};
