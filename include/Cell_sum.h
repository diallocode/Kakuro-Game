#ifndef _CELL_SUM
#define _CELL_SUM

#include <iostream>

#include "Cells.h"

class Cell_sum : public Cells
{
    private:
        /* sumRight et sumDown */
        int horizontale;
        int verticale;
    public:
        explicit Cell_sum(int h, int v);

        bool isEditable() override;
        void afficher() override;
};

#endif