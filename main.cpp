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
#include "include/Game.h"




int main(){
    Game jeu;

    // On creer la grille
    jeu.chargerGrille("Grille.txt");
    std::cout << "🧩 Grille initiale :\n";

    // Affichage de la grille
    jeu.afficherGrille();

    std::cout << "🧩 Mode joueur activé !\n";
    jeu.jouer();

    // resolution avec le solver
    std::cout << "\n🧠 Résolution en cours...\n";
    jeu.resoudre();

    return 0;
}