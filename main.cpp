#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "include/Grille.h"
#include "include/Cells.h"
#include "include/Cell_noir.h"
#include "include/Cell_vide.h"
#include "include/Cell_sum.h"


int main(){

    Grille g(4,6); // creation d'une grille
    g.afficher();

    return 0;
}