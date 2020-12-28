#include "../../include/Spell/IceSpell.h"

#include <stdlib.h>

void IceSpell::use(Monster* monster, float dexterity){
    monster->receiveDamage(this->min_damage + dexterity * (rand() % (this->max_damage - this->min_damage)));
    monster->decreaseDamage();
}

void IceSpell::print(){
    cout << "IceSpell: ";
    Spell::print()
}
