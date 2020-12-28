#include "../../../include/Living/Hero/Sorcerer.h"

void Sorcerer::levelUp(){
    this->strength += 50;
    this->agility += 100;
    this->dexterity += 100;
    this->level++;
}
