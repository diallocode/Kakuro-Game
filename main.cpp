#include "../include/Game.h"
#include <iostream>

int main() {
    Game jeu;

    std::cout << "🎮 Bienvenue dans Kakuro Solver 2025 🎮\n";
    std::cout << "--------------------------------------\n";

    std::cout << "Choisissez le format de la grille :\n";
    std::cout << "1. Fichier texte (Grille.txt)\n";
    std::cout << "2. Fichier binaire (Grille.bin)\n";
    std::cout << "Votre choix (1 ou 2) : ";

    int choix;
    std::cin >> choix;
    std::cin.ignore();  // Pour vider le buffer et éviter que le ENTER saute la pause

    std::string fichier;
    if (choix == 1) {
        fichier = "Grille.txt";
        std::cout << "Vous avez sélectionnez le format text\n";
    } else if (choix == 2) {
        fichier = "Grille.bin";
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

    std::cout << "🧩 Grille initiale :\n";
    jeu.afficherGrille();

    std::cout << "\nAppuyez sur ENTREE pour commencer...\n";
    std::cin.get();  // Attend que l'utilisateur appuie sur ENTER

    std::cout << "🧩 Mode joueur activé !\n";
    jeu.jouer();

    std::cout << "\n🧠 Résolution en cours...\n";
    jeu.resoudre();

    std::cout << "Merci d'avoir utilisé Kakuro Solver ! 👋\n";
    return 0;
}
