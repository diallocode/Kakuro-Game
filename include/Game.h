#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Solver.h"
#include "TextReader.h"
#include "TextCellFactory.h"
#include "Factory.h"
#include "bruteForceSolver.h"
#include "FilteredSolver.h"
#include "JsonReader.h"
#include "JsonCellFactory.h"
#include <limits> // pour std::numeric_limits
#include <iostream>


// Game ne se préoccupe pas de comment la grille est construite, il se contente de l’utiliser.

class Game
{
private:
    /* attribut */
    Grille* grille;
    Solver* solver;
public:
     Game();
    ~Game();

    void chargerGrille(const std::string& fichier);
    void afficherGrille() const;
    void jouer();
    void resoudre();
    
};