#include "../../include/Spell/LightingSpell.h"

void LightningSpell::use(Monster* monster, int dexterity){
    monster->receiveDamage(this->min_damage + dexterity/100.0 * (rand() % (this->max_damage - this->min_damage)));
    monster->decreasePossibilityOfAvoidance();
}

void LightningSpell::print(){
    cout << "LightningSpell: ";
    Spell::print();
}
