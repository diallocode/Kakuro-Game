#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Grille.h"


class Solver
{
    private:
        /* */
        Grille g;
    public:
        explicit Solver(Grille gl): g(gl) {};
        

    void solution(Grille g) const;
};
