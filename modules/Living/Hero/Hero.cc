#include "Hero.h"
#include <iostream>

using namespace std;

void Hero::displayStats(){
    cout << this->name << endl;
    cout << "Magic Power: " << this->magicPower << endl;
    cout << "Strength: " << this->strength << endl;
    cout << "Dexterity: " << this->dexterity << endl;
    cout << "Agility: " << this->agility << endl;
}
