#include "../include/Factory.h"


Factory::Factory(Reader* r, ICellFactory* f)
    : reader(r), cellFactory(f) {}


Factory::~Factory() {
    delete reader;
    delete cellFactory;
}

Grille* Factory::buildGrid(const std::string& filename) {
    std::vector<std::vector<std::string>> tokens = reader->readFile(filename);
    if (tokens.empty() || tokens[0].size() < 2) {
        std::cerr << "Erreur : format invalide ou dimensions manquantes." << std::endl;
        return nullptr;
    }

    int rows = std::stoi(tokens[0][0]);
    int cols = std::stoi(tokens[0][1]);
    std::cout << "Dimensions détectées : " << rows << " x " << cols << std::endl;

    Grille* grille = new Grille(rows, cols);

    if (tokens.size() - 1 != rows) {
        std::cerr << "Erreur : nombre de lignes incohérent avec les dimensions." << std::endl;
        delete grille;
        return nullptr;
    }

    for (int i = 1; i < tokens.size(); ++i) {
        if (tokens[i].size() != cols) {
            std::cerr << "Erreur : ligne " << i << " a une taille incohérente." << std::endl;
            delete grille;
            return nullptr;
        }

        for (int j = 0; j < cols; ++j) {
            Cells* cell = cellFactory->createCell(tokens[i][j]);
            if (!cell) {
                std::cerr << "Erreur : cellule invalide à (" << i - 1 << ", " << j << ")." << std::endl;
                delete grille;
                return nullptr;
            }
            grille->setCell(i - 1, j, cell);
        }
    }

    std::cout << "Grille construite avec succès.\n";
    return grille;
}
