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

void Square::displayStats(Hero* hero){
    // Display all Hero's Stats
    cout << "\t -----------------------------" << endl;
    cout << "\t > Hero Name   : " << hero->getName() << endl;
    cout << "\t > Hero Life   : " << hero->get_life() << endl;
    cout << "\t > Magic Power : " << hero->getMagicPower() << endl;
    cout << "\t > Strength    : " << hero->getStrenth() << endl;
    cout << "\t > Dexterity   : " << hero->getDexterity() << endl;
    cout << "\t > Agility     : " << hero->getAgility() << endl;
    cout << "\t > Money       : " << hero->getMoney() << endl;

    // Display his Weapon(s)
    Weapon* weapon;
    if ((weapon = hero->getWeapon('l')) != NULL) {
        if (weapon->get_hands() == 1)
            cout << "Left weapon: " << endl;
        weapon->print();
    }

    if ((weapon = hero->getWeapon('r')) != NULL) {
        if (weapon->get_hands() == 1)
            cout << "Right weapon: " << endl;
        weapon->print();
    }

    // Display his Armor
    Armor* armor;
    if ((armor = hero->getArmor()) != NULL)
        armor->print();

    // Display his Items
    list<Item*> items = hero->getInventory();
    if (items.size() > 0) {
        cout << "Available Items:" << endl;

        list<Item*>::iterator it;
        for (it=items.begin() ; it!=items.end() ; ++it) {
            (*it)->print();
        }
    }

    // Display his Spells
    list<Spell*> spells = hero->getSpells();
    if (spells.size() > 0) {
        cout << "Available Spells:" << endl;
    
        list<Spell*>::iterator it;
        for (it=spells.begin() ; it!=spells.end() ; ++it) {
            (*it)->print();
        }
    }
}
