#ifndef JSONREADER_H
#define JSONREADER_H

#include <fstream>
#include <iostream>
#include "Reader.h"
#include <vector>
#include <string>
#include "../externale/json.hpp"
using json = nlohmann::json;


class JsonReader : public Reader {
public:
    std::vector<std::vector<std::string>> readFile(const std::string& filename) override;
};

#endif // JSONREADER_H
