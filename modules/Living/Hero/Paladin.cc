#include "../../../include/Living/Hero/Paladin.h"

void Paladin::levelUp(){
    this->strength += 100;
    this->agility += 50;
    this->dexterity += 100;
    this->level++;
}
