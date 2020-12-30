#include "../../include/Spell/LightingSpell.h"

LightningSpell::~LightningSpell() {
    cout << "Destructor of LightningSpell!" << endl;
    // TODO: if you want anything to add
}

void LightningSpell::use(Monster* monster, float dexterity){
    monster->receiveDamage(this->min_damage + dexterity * (rand() % (this->max_damage - this->min_damage)));
    monster->decreasePossibilityOfAvoidance();
}

void LightningSpell::print(){
    cout << "LightningSpell: ";
    Spell::print();
}
