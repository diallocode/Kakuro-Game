#include <fstream>
#include <string>
#include <cstring>
#include <iostream>

void generateGrilleBin(const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);

    if (!file) {
        std::cerr << "Erreur lors de l'ouverture du fichier " << filename << std::endl;
        return;
    }

    int rows = 5;
    int cols = 5;
    std::string grid[5][5] = {
        {"X", "X", "I25/-", "I-2/-", "X"},
        {"X", "I-5/8", "U-", "U-", "X"},
        {"I-/11", "U-", "U-", "I-5/-", "X"},
        {"I-/15", "U-", "U-", "U-", "X"},
        {"X", "I-/3", "U-", "U-", "X"}
    };

    file.write(reinterpret_cast<const char*>(&rows), sizeof(int));
    file.write(reinterpret_cast<const char*>(&cols), sizeof(int));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            char buffer[32] = {0};
            std::strncpy(buffer, grid[i][j].c_str(), 31);
            file.write(buffer, sizeof(buffer));
        }
    }

    file.close();
    std::cout << "✅ Grille.bin généré avec succès : " << filename << std::endl;
}

int main() {
    generateGrilleBin("Grille.bin");
    return 0;
}
