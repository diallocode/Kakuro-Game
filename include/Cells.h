#include <string.h>
#include <iostream>


class Cells
{
    private:
        /* positions */
        int x;
        int y;
    public:
        // Methode display cellule
        virtual void display() = 0;  

        // Verification si une cellule est modifiable
        virtual bool isEditable() = 0;
};


