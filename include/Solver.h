#ifndef SOLVER_H
#define SOLVER_H


#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Grille.h"


class Solver
{
    public:
    virtual ~Solver() = default;
    // Résout une grille en la modifiant directement
    virtual bool solution(Grille& g) = 0; 
};

#endif