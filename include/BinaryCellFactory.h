// BinaryCellFactory.h
#ifndef BINARYCELLFACTORY_H
#define BINARYCELLFACTORY_H

#include "IcellFactory.h"

class BinaryCellFactory : public ICellFactory {
public:
    Cells* createCell(const std::string& token) override;
};

#endif 