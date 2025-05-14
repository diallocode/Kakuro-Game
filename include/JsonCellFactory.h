#ifndef JSONCELLFACTORY_H
#define JSONCELLFACTORY_H

#include "ICellFactory.h"
#include <string>
#include "Cell_noir.h"
#include "Cell_sum.h"
#include "Cell_vide.h"

class JsonCellFactory : public ICellFactory {
public:
    Cells* createCell(const std::string& token) override;
};

#endif // JSONCELLFACTORY_H
