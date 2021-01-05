#include "../../../include/Living/Hero/Warrior.h"

void Warrior::levelUp(){
    this->strength *= 1.2;
    this->agility *= 1.3;
    this->dexterity *= 1.3;
    this->level++;
}
