#ifndef _CELL_S
#define _CELL_S


#include <string.h>
#include <iostream>


class Cells
{
    private:
        /* positions */

    public:
        // Verification si une cellule est modifiable
        virtual bool isEditable() = 0;
        virtual std::string afficher() = 0;
        virtual ~Cells() = default;
};

#endif

