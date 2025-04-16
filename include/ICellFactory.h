// ICellFactory.h
// Interface pour toutes les factories capables de créer des objets Cells

#ifndef ICELLFACTORY_H
#define ICELLFACTORY_H

#include <string>
#include "Cells.h"

class ICellFactory {
public:
    // nettoyage des ressources
    virtual ~ICellFactory() = default;
    // implémenter leur propre logique de création de cellule pour les classes fille
    virtual Cells* createCell(const std::string& token) = 0;
};

#endif
