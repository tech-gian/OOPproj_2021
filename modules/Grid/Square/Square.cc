///////////////////////////
// Implementation of Square
///////////////////////////



#include "../../../include/Grid/Square.h"


// Square Functions


void Square::move_heroes(Square* square) {
    // Move heroes from another Square
    for (int i=0 ; i<3 ; ++i) {
        this->heroes[i] = square->heroes[i];
        square->heroes[i] = NULL;
    }
}

void Square::displayStats(){
    int i = 0;
    while(i < 3 && this->heroes[i] != NULL){
        heroes[i]->print();
        i++;
    }
}
