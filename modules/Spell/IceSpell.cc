#include "../../include/Spell/IceSpell.h"

void IceSpell::use(Monster* monster, int dexterity){
    monster->receiveDamage(this->min_damage + dexterity/100.0 * (rand() % (this->max_damage - this->min_damage)));
    monster->decreaseDamage();
}

void IceSpell::print() const{
    cout << "IceSpell: ";
    Spell::print();
}
