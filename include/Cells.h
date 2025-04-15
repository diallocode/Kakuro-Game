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
};


