#include "../include/BinaryReader.h"

std::vector<std::vector<std::string>> BinaryReader::readFile(const std::string& filename) {
    std::vector<std::vector<std::string>> grid;
    std::ifstream file(filename, std::ios::binary);

    if (!file) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier binaire " << filename << std::endl;
        return grid;
    }

    int rows = 0, cols = 0;
    file.read(reinterpret_cast<char*>(&rows), sizeof(int));
    file.read(reinterpret_cast<char*>(&cols), sizeof(int));

    for (int i = 0; i < rows; ++i) {
        std::vector<std::string> line;
        for (int j = 0; j < cols; ++j) {
            char buffer[32] = {0};  // Max 31 chars + null terminator
            file.read(buffer, sizeof(buffer));
            line.push_back(std::string(buffer));
        }
        grid.push_back(line);
    }

    file.close();
    return grid;
}
