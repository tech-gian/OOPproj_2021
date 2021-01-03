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

void Square::displayStats(Hero* hero){
    cout << "\t -----------------------------" << endl;
    cout << "\t > Hero Name   : " << hero->getName() << endl;
    cout << "\t > Hero Life   : " << hero->get_life() << endl;
    cout << "\t > Magic Power : " << hero->getMagicPower() << endl;
    cout << "\t > Strength    : " << hero->getStrenth() << endl;
    cout << "\t > Dexterity   : " << hero->getDexterity() << endl;
    cout << "\t > Agility     : " << hero->getAgility() << endl;
    cout << "\t > Money       : " << hero->getMoney() << endl;
}
