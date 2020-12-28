///////////////////////////
// Implementation of Square
///////////////////////////



#pragma once

#include "Main_include.h"



// Square Functions

void Square::move_heroes(Square* square) {
    for (int i=0 ; i<3 ; ++i) {
        this->heroes[i] = square->heroes[i];
        square->heroes[i] = NULL;
    }    
}


