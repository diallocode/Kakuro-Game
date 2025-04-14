#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "solver.h"

// Game ne se préoccupe pas de comment la grille est construite, il se contente de l’utiliser.

class Game
{
private:
    /* attribut */
    Grille grille; // Contient la grille
    Solver s;
public:
    explicit Game(Solver solution, Grille g):s(solution), grille(g) {};

    bool isSolutionValide() const;
    void affichage_grille() const;

    // Methode permettant a un jouer de remplir la grille
    void jouer() const;
};