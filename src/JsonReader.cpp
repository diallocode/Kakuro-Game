#include "../include/JsonReader.h"

using json = nlohmann::json;

std::vector<std::vector<std::string>> JsonReader::readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir " << filename << std::endl;
        return {};
    }

    json j;
    file >> j;

    int rows = j["dimensions"]["rows"];
    int cols = j["dimensions"]["cols"];

    std::vector<std::vector<std::string>> result;
    result.push_back({std::to_string(rows), std::to_string(cols)}); // ligne de dimensions

    for (const auto& row : j["grid"]) {
        std::vector<std::string> tokens;
        for (const auto& cell : row) {
            std::string type = cell["type"];
            if (type == "black") {
                tokens.push_back("#");
            } else if (type == "sum") {
                int down = cell.value("right", 0);
                int right = cell.value("down", 0);
                if (down > 0 && right > 0)
                    tokens.push_back(std::to_string(down) + "/" + std::to_string(right));
                else if (down > 0)
                    tokens.push_back(std::to_string(down) + "/");
                else if (right > 0)
                    tokens.push_back("/" + std::to_string(right));
                else
                    tokens.push_back("/"); 
            } else if (type == "value") {
                int value = cell.value("value", 0);
                tokens.push_back(value == 0 ? "_" : std::to_string(value));
            }
        }
        result.push_back(tokens);
    }

    return result;
}
