#include <iostream>
#include "../../include/Spell/Spell.h"

using namespace std;

void Spell::print(){
    cout << this->name << endl;
    cout << "Price: " << this->price << endl;
    cout << "Min. Level: " << this-min_level << endl;
    cout << "Damage: [" << this->min_damage << " - " << this->max_damage << "]" << endl;
    cout << "Magic power required to use: " << this->magic_power_required << endl;
}

string Spell::get_name(){
    return this->name;
}

int Spell::get_price(){
    return this->price;
}
