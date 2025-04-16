// Factory.h
#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include "Reader.h"
#include "ICellFactory.h"
#include "Grille.h"

class Factory {
private:
    Reader* reader;
    ICellFactory* cellFactory;

public:
    // Constructeur de la classe
    Factory(Reader* r, ICellFactory* f);
    // Methode pour construire une grille
    Grille* buildGrid(const std::string& filename);
    // Destructeur
    ~Factory();
};

#endif