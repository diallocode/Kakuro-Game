#include <iostream>

#include "Cells.h"

class Cell_sum : public Cells
{
    private:
        /* sumRight et sumDown */
        int horizontale;
        int verticale;
    public:
        explicit Cell_sum(int h, int v): horizontale(h), verticale(v) {};

        bool isEditable() override;
};
