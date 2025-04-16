#include "../include/Factory.h"


Factory::Factory(Reader* r, ICellFactory* f)
    : reader(r), cellFactory(f) {}


Factory::~Factory() {
    delete reader;
    delete cellFactory;
}

Grille* Factory::buildGrid(const std::string& filename) {
    // 1. Lire le contenu du fichier
    std::vector<std::vector<std::string>> tokens = reader->readFile(filename);
    if (tokens.empty()) {
        std::cerr << "Erreur : aucune donnée lue depuis le fichier." << std::endl;
        return nullptr;
    }

    int rows = tokens.size();
    int cols = tokens[0].size();
    Grille* grille = new Grille(rows, cols);

    // 2. Parcourir et remplir chaque case
    for (int i = 0; i < rows; ++i) {
        if (tokens[i].size() != cols) {
            std::cerr << "Erreur : ligne " << i << " a une taille incohérente." << std::endl;
            delete grille;
            return nullptr;
        }

        for (int j = 0; j < cols; ++j) {
            Cells* cell = cellFactory->createCell(tokens[i][j]);
            grille->setCell(i, j, cell);
        }
    }

    return grille;
}
