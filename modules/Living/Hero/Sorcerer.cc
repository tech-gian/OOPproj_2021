#include "../../../include/Living/Hero/Sorcerer.h"

void Sorcerer::levelUp(){
    this->strength *= 1.2;
    this->agility *= 1.3;
    this->dexterity *= 1.3;
    this->level++;
}
