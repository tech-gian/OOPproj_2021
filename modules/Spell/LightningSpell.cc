#include "../../include/Spell/LightingSpell.h"

#include <stdlib.h>

void LightningSpell::use(Monster* monster, float dexterity){
    monster->receiveDamage(this->min_damage + dexterity * (rand() % (this->max_damage - this->min_damage)));
    monster->decreasePossibilityOfAvoidance();
}

void LightningSpell::print(){
    cout << "LightningSpell: ";
    Spell::print()
}
