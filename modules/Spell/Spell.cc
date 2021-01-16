#include "../../include/Spell/Spell.h"

string Spell::get_name(){
    return this->name;
}

int Spell::get_price(){
    return this->price;
}

int Spell::get_min_level(){
    return this->min_level;
}

int Spell::getMagicPowerRequired(){
    return this->magic_power_required;
}

void Spell::print(){
    cout << this->name << endl;
    cout << "Price                       : " << this->price << endl;
    cout << "Min. Level                  : " << this->min_level << endl;
    cout << "Damage                      : [" << this->min_damage << " - " << this->max_damage << "]" << endl;
    cout << "Magic power required to use : " << this->magic_power_required << endl;
}
