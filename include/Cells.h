#ifndef _CELL_S
#define _CELL_S


#include <string.h>
#include <iostream>


class Cells
{
    private:
        /* positions */
        int x;
        int y;
    public:
        // Verification si une cellule est modifiable
        virtual bool isEditable() = 0;
        virtual void afficher() = 0;
};

#endif

