// BinaryCellFactory.h
#ifndef BINARYCELLFACTORY_H
#define BINARYCELLFACTORY_H

#include "ICellFactory.h"

class BinaryCellFactory : public ICellFactory {
public:
    Cells* createCell(const std::string& token) override;
};

#endif 