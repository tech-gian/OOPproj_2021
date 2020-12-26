#include "../include/Living/Monster/Monster.h"

#include <stdlib.h>
#include <iostream>
using namespace std;

void Monster::displayStats(){
    cout << "Monster Name: " << this->name << endl;
    cout << "Damage: [" << this->min_damage << " - " << this->max_damage << "]" << endl;
    cout << "Defense: " << this->defense << endl;
}

void Monster::decreaseDamage(){
    this->min_damage -= x;  // TODO
    this->min_damage -= x;
}

void Monster::decreaseDefense(){
    this->defense -= y;     // TODO
}

void Monster::decreasePossibilityOfAvoidance(){
    this->possibilityOfAvoidance -= z; // TODO
}

void Monster::attack(Hero* hero){
    hero->receiveDamage(this->min_damage + rand() % (this->max_damage - this->min_damage));
}
