#pragma once
#include "Solver.h"
#include "Grille.h"

class FilteredSolver : public Solver {
public:
    bool solution(Grille& g) override;

private:
    
    bool isValid(Grille& g, int row, int col, int val);
    bool solveKakuro(Grille& g, int row, int col);
    bool checkVertical(Grille& g, int row, int col, int num);
    bool checkHorizontal(Grille& g, int row, int col, int num);
};
