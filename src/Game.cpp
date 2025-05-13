#include "../include/Game.h"


#include <iostream>

Game::Game() : grille(nullptr), solver(nullptr) {}

Game::~Game() {
    delete grille;
    delete solver;
}

void Game::chargerGrille(const std::string& fichier) {
    Reader* reader = nullptr;

    // Détecter l'extension
    if (fichier.size() >= 4 && fichier.substr(fichier.size() - 4) == ".bin") {
        reader = new BinaryReader();
        std::cout << "[INFO] Chargement fichier binaire.\n";
    } else if (fichier.size() >= 4 && fichier.substr(fichier.size() - 4) == ".txt") {
        reader = new TextReader();
        std::cout << "[INFO] Chargement fichier texte.\n";
    } else {
        std::cerr << "Erreur : Format de fichier non reconnu.\n";
        return;
    }

    Factory* factory = new Factory(reader, new TextCellFactory());
    grille = factory->buildGrid(fichier);
    delete factory;

    if (!grille) {
        std::cerr << "Erreur : Grille non chargée.\n";
    }
}

void Game::afficherGrille() const {
    if (grille)
        grille->afficher();
    else
        std::cerr << "Aucune grille à afficher.\n";
}

void Game::resoudre() {
    if (!grille) {
        std::cerr << "Erreur : aucune grille à résoudre.\n";
        return;
    }

    solver = new FilteredSolver();

    if (solver->solution(*grille)) {
        std::cout << "\n✅ Grille résolue :\n";
        grille->afficher();
    } else {
        std::cout << "\n❌ Aucune solution trouvée.\n";
    }
}

#include <limits> // pour std::numeric_limits

void Game::jouer() {
    if (!grille) {
        std::cerr << "Erreur : aucune grille chargée.\n";
        return;
    }

    while (true) {
        std::cout << "\n📋 Grille actuelle :\n";
        grille->afficher();

        int row, col, val;

        std::cout << "\nEntrez ligne (-1 pour quitter) : ";
        std::cin >> row;
        if (row == -1) break;

        std::cout << "Entrez colonne : ";
        std::cin >> col;

        std::cout << "Entrez valeur (1-9, 0 pour effacer) : ";
        std::cin >> val;

        // Sécuriser les entrées
        if (std::cin.fail() || val < 0 || val > 9) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "❌ Entrée invalide.\n";
            continue;
        }

        Cells* c = grille->getCell(row, col);
        Cell_vide* cell = dynamic_cast<Cell_vide*>(c);
        if (!cell) {
            std::cout << "❌ Ce n'est pas une case éditable.\n";
            continue;
        }

        cell->setValue(val);
    }

    std::cout << "\n✅ Partie terminée. Grille finale :\n";
    grille->afficher();
}
