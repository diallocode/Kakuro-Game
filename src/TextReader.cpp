#include "../include/TextReader.h"


std::vector<std::vector<std::string>> TextReader::readFile(const std::string& filename) {
    std::vector<std::vector<std::string>> lines;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier " << filename << std::endl;
        return lines; // vide
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<std::string> tokens;
        std::string token;

        while (iss >> token) {
            tokens.push_back(token);
        }

        lines.push_back(tokens);
    }

    return lines;
}
