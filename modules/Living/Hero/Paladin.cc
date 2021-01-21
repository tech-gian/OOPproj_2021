#include "../../../include/Living/Hero/Paladin.h"

void Paladin::levelUp(){
    this->strength *= 1.3;
    this->agility *= 1.2;
    this->dexterity *= 1.3;
    this->level++;
}

void Paladin::print() const{
    cout << "\t -----------------------------" << endl;
    cout << "\t > Paladin Name    : " << this->name << endl;
    Hero::print();
}
