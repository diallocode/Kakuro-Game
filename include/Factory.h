// Factory.h
#ifndef FACTORY_H
#define FACTORY_H

#include <string>
#include "Reader.h"
#include "ICellFactory.h"
#include "Grille.h"

class Factory {
private:
    Reader* reader;
    ICellFactory* cellFactory;

public:
    Factory(Reader* r, ICellFactory* f);
    Grille* buildGrid(const std::string& filename);
    ~Factory();
};

#endif