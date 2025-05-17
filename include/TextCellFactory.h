// TextCellFactory.h
#ifndef TEXTCELLFACTORY_H
#define TEXTCELLFACTORY_H
#include "ICellFactory.h"
#include "TextCellFactory.h"
#include "Cell_noir.h"
#include "Cell_sum.h"
#include "Cell_vide.h"
#include <algorithm>

class TextCellFactory : public ICellFactory {
public:
    Cells* createCell(const std::string& token) override;
};

#endif