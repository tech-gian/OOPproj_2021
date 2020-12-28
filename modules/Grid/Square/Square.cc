///////////////////////////
// Implementation of Square
///////////////////////////



#include "../../../include/Grid/Square.h"


// Square Functions

void Square::move_heroes(Square* square) {
    for (int i=0 ; i<3 ; ++i) {
        this->heroes[i] = square->heroes[i];
        square->heroes[i] = NULL;
    }    
}


