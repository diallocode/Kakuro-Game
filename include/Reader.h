// Reader.h
#ifndef READER_H
#define READER_H

#include <string>
#include <vector>

class Reader {
public:
    virtual ~Reader() = default;
    virtual std::vector<std::vector<std::string>> readFile(const std::string& filename) = 0;
};

#endif