#include "../../../include/Living/Hero/Warrior.h"

void Warrior::levelUp(){
    this->strength += 100;
    this->agility += 100;
    this->dexterity += 50;
    this->level++;
}
