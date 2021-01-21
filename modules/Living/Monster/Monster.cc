#include "../../../include/Living/Monster/Monster.h"

int Monster::getMinDamage() const{
    return this->min_damage;
}

int Monster::getMaxDamage() const{
    return this->max_damage;
}

int Monster::getDefense() const{
    return this->defense;
}

int Monster::getPossibilityOfAvoidance() const{
    return this->possibilityOfAvoidance;
}

void Monster::decreaseDamage(){
    if(this->min_damage >= 10){
        this->min_damage -= 10;
        this->max_damage -= 10;
    }
}

void Monster::decreaseDefense(){
    if(this->defense >= 10)
        this->defense -= 10;
}

void Monster::decreasePossibilityOfAvoidance(){
    if(this->possibilityOfAvoidance >= 10)
        this->possibilityOfAvoidance -= 10;
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

void Monster::print() const{
    cout << "\t > Defense           : " << this->defense << endl;
    cout << "\t > Health power      : " << this->healthPower << endl;
    cout << "\t > Damage            : [" << this->min_damage << " - " << this->max_damage << "]" << endl;
}
