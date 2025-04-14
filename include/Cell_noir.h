#include <iostream>

#include "Cells.h"

class Cell_noir : public Cells
{
    private:
        /* Ne contient rien, vide */
    public:
        bool isEditable() override;
};