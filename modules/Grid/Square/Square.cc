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
    cout << "Hero Name: " << hero->getName() << endl;
    cout << "Magic Power: " << hero->getMagicPower() << endl;
    cout << "Strength: " << hero->getStrenth() << endl;
    cout << "Dexterity: " << hero->getDexterity() << endl;
    cout << "Agility: " << hero->getAgility() << endl;
    cout << "Money: " << hero->getMoney();
}
