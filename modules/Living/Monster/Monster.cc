#include "../../../include/Living/Monster/Monster.h"

int Monster::getMinDamage(){
    return this->min_damage;
}

int Monster:: getMaxDamage(){
    return this->max_damage;
}

void Monster::displayStats(){
    cout << "Monster Name: " << this->name << endl;
    cout << "Damage: [" << this->min_damage << " - " << this->max_damage << "]" << endl;
    cout << "Defense: " << this->defense << endl;
}

// void Monster::decreaseDamage(){
//     this->min_damage -= x;  // TODO
//     this->min_damage -= x;
// }

// void Monster::decreaseDefense(){
//     this->defense -= y;     // TODO
// }

// void Monster::decreasePossibilityOfAvoidance(){
//     this->possibilityOfAvoidance -= z; // TODO
// }


void Monster::receiveDamage(int damage){
    if(this->defense){
        if(damage <= this->defense)
            this->defense -= damage;
        else{
            damage -= this->defense;
            this->healthPower = this->healthPower > damage ? this->healthPower - damage : 0;
        }
    }else{
        this->healthPower = this->healthPower > damage ? this->healthPower - damage : 0;
    }
}

void Monster::regenerate(){
    this->healthPower *= 1.05;
}
