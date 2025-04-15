// TextReader.h
#ifndef TEXTREADER_H
#define TEXTREADER_H
#include <fstream>
#include <sstream>
#include <iostream>

#include "Reader.h"

class TextReader : public Reader {
public:
    std::vector<std::vector<std::string>> readFile(const std::string& filename) override;
};

#endif