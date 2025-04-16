#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "include/Grille.h"
#include "include/Cells.h"
#include "include/Cell_noir.h"
#include "include/Cell_vide.h"
#include "include/Cell_sum.h"
#include "include/Factory.h"
#include "include/TextReader.h"
#include "include/TextCellFactory.h"




int main(){
    // Objet qui permet de lire un fichier texte et de fabriquer toutes les cellules nécessaires pour construire une grille
    Factory* factory = new Factory(new TextReader(), new TextCellFactory());

    // Construction de la grille
    Grille* grille = factory->buildGrid("Grille.txt");

    // Affichage
    grille->afficher();

    return 0;
}