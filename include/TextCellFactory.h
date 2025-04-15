// TextCellFactory.h
#ifndef TEXTCELLFACTORY_H
#define TEXTCELLFACTORY_H
#include "IcellFactory.h"

class TextCellFactory : public ICellFactory {
public:
    Cells* createCell(const std::string& token) override;
};

#endif