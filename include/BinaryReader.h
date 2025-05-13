// BinaryReader.h
#ifndef BINARYREADER_H
#define BINARYREADER_H
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include "Reader.h"

class BinaryReader : public Reader {
public:
    std::vector<std::vector<std::string>> readFile(const std::string& filename) override;
};

#endif