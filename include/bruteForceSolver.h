#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <sstream>
#include "Solver.h"
#include "Cell_vide.h"
#include "Cell_sum.h"


class bruteForceSolver : public Solver
{
public:
    bool solution(Grille& g) override;
};