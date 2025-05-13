// BinReader.h
#ifndef BINREADER_H
#define BINTREADER_H
#include <fstream>
#include <sstream>
#include <iostream>

#include "Reader.h"

class BinReader : public Reader {

    public:
        std::vector<std::vector<std::string>> readFile(const std::string& filename) override;
};

#endif

