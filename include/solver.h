#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Grille.h"


class Solver
{
    public:

    // Résout une grille en la modifiant directement
    virtual bool solution(Grille& g) = 0; 
};
