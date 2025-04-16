#ifndef _CELL_VIDE_
#define _CELL_VIDE_

#include <iostream>
#include "Cells.h"

class Cell_vide : public Cells
{
    private:
        /* valeur correspondante */
        int val;
    public:
        explicit Cell_vide(int v);

        bool isEditable() override;
        std::string afficher() override;
        int getValue() const;
        void setValue(int val);
};

#endif