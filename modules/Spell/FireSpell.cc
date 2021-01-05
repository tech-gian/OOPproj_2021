#include "../../include/Spell/FireSpell.h"


void FireSpell::use(Monster* monster, int dexterity){
    monster->receiveDamage(this->min_damage + dexterity/100.0 * (rand() % (this->max_damage - this->min_damage)));
    monster->decreaseDefense();
}

void FireSpell::print(){
    cout << "FireSpell: ";
    Spell::print();
}
