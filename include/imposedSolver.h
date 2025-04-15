#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "solver.h"

class imposedSolver : public Solver
{
public:
   bool solution(Grille& g) override;
};
