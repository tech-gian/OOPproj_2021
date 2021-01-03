#include "../../../include/Living/Monster/Monster.h"

int Monster::getMinDamage(){
    return this->min_damage;
}

int Monster:: getMaxDamage(){
    return this->max_damage;
}

int Monster::getDefense(){
    return this->defense;
}

int Monster::getPossibilityOfAvoidance(){
    return this->possibilityOfAvoidance;
}

void Monster::decreaseDamage(){
    this->min_damage -= 1;  // TODO
    this->max_damage -= 1;
}

void Monster::decreaseDefense(){
    this->defense -= 1;     // TODO
}

void Monster::decreasePossibilityOfAvoidance(){
    this->possibilityOfAvoidance -= 1; // TODO
}


void Monster::receiveDamage(int damage){
    if(this->defense){
        if(damage <= this->defense)
            this->defense -= damage;
        else{
            damage -= this->defense;
            this->defense = 0;
            this->healthPower = this->healthPower > damage ? (this->healthPower - damage) : 0;
        }
    }else{
        this->healthPower = this->healthPower > damage ? (this->healthPower - damage) : 0;
    }
    if(this->defense == 0 && this->healthPower == 0)
        cout << this->name << " died." << endl;
}

void Monster::regenerate(){
    if (this->healthPower < 0.95 * INIT_HEALTH_POWER)
        this->healthPower *= 1.05;
}
