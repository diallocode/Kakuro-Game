#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "solver.h"

class bruteForceSolver : public Solver
{
public:
    bool solution(Grille& g) override;
};