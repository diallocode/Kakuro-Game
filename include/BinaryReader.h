// BinaryReader.h
#ifndef BINARYREADER_H
#define BINARYREADER_H

#include "Reader.h"

class BinaryReader : public Reader {
public:
    std::vector<std::vector<std::string>> readFile(const std::string& filename) override;
};

#endif