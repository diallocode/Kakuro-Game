// ICellFactory.h
#ifndef ICELLFACTORY_H
#define ICELLFACTORY_H

#include <string>
#include "Cells.h"

class ICellFactory {
public:
    virtual ~ICellFactory() = default;
    virtual Cells* createCell(const std::string& token) = 0;
};

#endif
