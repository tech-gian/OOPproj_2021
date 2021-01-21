#include "../../../include/Living/Hero/Warrior.h"

void Warrior::levelUp(){
    this->strength *= 1.3;
    this->agility *= 1.3;
    this->dexterity *= 1.2;
    this->level++;
}

void Warrior::print() const{
    cout << "\t -----------------------------" << endl;
    cout << "\t > Warrior Name    : " << this->name << endl;
    Hero::print();
}
