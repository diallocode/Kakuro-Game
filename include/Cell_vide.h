#include <iostream>
#include "Cells.h"

class Cell_vide : public Cells
{
    private:
        /* valeur correspondante */
        int val;
    public:
        explicit Cell_vide(int v) : val(v) {};

        bool isEditable() override;
};
