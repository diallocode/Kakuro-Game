#include "../include/Game.h"
#include <iostream>

int main() {
    Game jeu;

    std::cout << "🎮 Bienvenue dans Kakuro Solver 2025 🎮\n";
    std::cout << "--------------------------------------\n";

    std::cout << "Choisissez le format de la grille :\n";
    std::cout << "1. Fichier texte (.txt)\n";
    std::cout << "2. Fichier Json (.json)\n";
    std::cout << "Votre choix (1 ou 2) : ";

    int choix;
    std::cin >> choix;
    std::cin.ignore(); // pour consommer le retour chariot

    std::string fichier;
    if (choix == 1) {
        fichier = "Grille.txt";
        std::cout << "Vous avez sélectionnez le format text\n";
    } else if (choix == 2) {
        fichier = "kakuro.json";
        std::cout << "Vous avez sélectionnez le format binaire\n";
    } else {
        std::cerr << "Foramt non disponible.\n";
        return 1;
    }

    // Pause avec ENTER
    std::cout << "\nAppuyez sur ENTREE pour charger la grille...\n";
    std::cin.get();  // Attend que l'utilisateur appuie sur ENTER

    // Chargement automatique
    jeu.chargerGrille(fichier);

    std::cout << "\nChoisissez la difficulté :\n";
    std::cout << "1. Facile (temps illimité)\n";
    std::cout << "2. Moyen (3 minutes)\n";
    std::cout << "3. Difficile (2 minutes + 10 tentatives max)\n";
    std::cout << "Votre choix : ";

    int difficulte;
    std::cin >> difficulte;

    // Définir la difficulté directement dans Game
    jeu.setDifficulte(difficulte);

    std::cout << "\n🧩 Grille initiale :\n";
    jeu.afficherGrille();

    jeu.jouer();

    std::cout << "\n🧠 Résolution automatique...\n";
    jeu.resoudre();

    std::cout << "Merci d'avoir joué à Kakuro Solver ! 👋\n";
    return 0;
}
