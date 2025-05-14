#include "../include/Game.h"

Game::Game() : grille(nullptr), solver(nullptr) {}

Game::~Game() {
    delete grille;
    delete solver;
}

void Game::chargerGrille(const std::string& fichier) {
    Reader* reader = nullptr;
    ICellFactory* cellFactory = nullptr;

    if (fichier.size() >= 5 && fichier.substr(fichier.size() - 5) == ".json") {
        reader = new JsonReader();
        cellFactory = new JsonCellFactory();
        std::cout << "Chargement fichier Json.\n";
    } else if (fichier.size() >= 4 && fichier.substr(fichier.size() - 4) == ".txt") {
        reader = new TextReader();
        cellFactory = new TextCellFactory();
        std::cout << "Chargement fichier texte.\n";
    } else {
        std::cerr << "Erreur : Format de fichier non reconnu.\n";
        return;
    }

    Factory* factory = new Factory(reader, cellFactory);
    grille = factory->buildGrid(fichier);
    delete factory;

    if (!grille) {
        std::cerr << "Erreur : Grille non chargée.\n";
    } else {
        std::cout << "Grille chargée avec succès.\n";
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

int difficulte = 1; // Par défaut Facile

void Game::setDifficulte(int diff) {
    difficulte = diff;
}



void Game::jouer() {
    if (!grille) {
        std::cerr << "Erreur : aucune grille chargée.\n";
        return;
    }

    int tempsLimite = 0;
    int tentativesRestantes = -1;

    if (difficulte == 1) { // Facile
        tempsLimite = -1; // illimité
    } else if (difficulte == 2) { // Moyen
        tempsLimite = 180;
    } else if (difficulte == 3) { // Difficile
        tempsLimite = 120;
        tentativesRestantes = 10;
    }

    auto debut = std::chrono::steady_clock::now();
    std::cout << "\n🧩 Mode défi activé !\n";

    while (true) {
        // Vérifier temps si pas illimité
        if (tempsLimite > 0) {
            auto maintenant = std::chrono::steady_clock::now();
            auto duree = std::chrono::duration_cast<std::chrono::seconds>(maintenant - debut).count();

            if (duree >= tempsLimite) {
                std::cout << "\n💀 Temps écoulé ! Game Over.\n";
                break;
            }

            int tempsRestant = tempsLimite - duree;
            std::cout << "\n⏱️ Temps restant : " << (tempsRestant / 60) << " min " << (tempsRestant % 60) << " s\n";
        } else {
            auto maintenant = std::chrono::steady_clock::now();
            auto duree = std::chrono::duration_cast<std::chrono::seconds>(maintenant - debut).count();
            std::cout << "\n⏱️ Temps écoulé : " << (duree / 60) << " min " << (duree % 60) << " s\n";
        }

        if (tentativesRestantes > 0) {
            std::cout << "💥 Tentatives restantes : " << tentativesRestantes << "\n";
        }

        grille->afficher();

        int row, col, val;
        std::cout << "\nEntrez ligne (-1 pour quitter) : ";
        std::cin >> row;
        if (row == -1) break;

        std::cout << "Entrez colonne : ";
        std::cin >> col;

        std::cout << "Entrez valeur (1-9, 0 pour effacer) : ";
        std::cin >> val;

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

        if (tentativesRestantes > 0) {
            tentativesRestantes--;
            if (tentativesRestantes == 0) {
                std::cout << "\n💀 Nombre de tentatives épuisé ! Game Over.\n";
                break;
            }
        }
    }

    std::cout << "\n✅ Partie terminée. Grille finale :\n";
    grille->afficher();

    // Vérifier si la grille est complétée et valide après chaque coup
    bool grilleComplete = true;
    for (int i = 0; i < grille->getRows(); ++i) {
        for (int j = 0; j < grille->getCols(); ++j) {
            Cell_vide* cell = dynamic_cast<Cell_vide*>(grille->getCell(i, j));
            if (cell) {
                if (cell->getValue() == 0) {
                    grilleComplete = false;
                    break;
                }
            }
        }
        if (!grilleComplete) break;
    }

    // Si tout est rempli, vérifier la validité globale (avec ton solver)
    if (grilleComplete) {
        FilteredSolver verifSolver;
        if (verifSolver.solution(*grille)) {
            std::cout << "\n🎉 BRAVO ! Grille complétée et correcte !\n";
            
        } else {
            std::cout << "\n❌ Solution incorrecte, retentez votre chance 😂😭\n";
            std::cout << "\n";
            std::cout << "\n🧠 Solution🥸😎\n";
            resoudre();
        }
    }

}

