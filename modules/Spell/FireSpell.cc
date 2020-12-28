#include "../../include/Spell/FireSpell.h"

void FireSpell::use(Monster* monster, float dexterity){
    monster->receiveDamage(this->min_damage + dexterity * (rand() % (this->max_damage - this->min_damage)));
    monster->decreaseDefense();
}

void FireSpell::print(){
    cout << "FireSpell: ";
    Spell::print();
}
