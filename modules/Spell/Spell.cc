#include "../../include/Spell/Spell.h"

string Spell::get_name() const{
    return this->name;
}

int Spell::get_price() const{
    return this->price;
}

int Spell::get_min_level() const{
    return this->min_level;
}

int Spell::getMagicPowerRequired() const{
    return this->magic_power_required;
}

void Spell::print() const{
    cout << this->name << endl;
    cout << "Price                       : " << this->price << endl;
    cout << "Min. Level                  : " << this->min_level << endl;
    cout << "Damage                      : [" << this->min_damage << " - " << this->max_damage << "]" << endl;
    cout << "Magic power required to use : " << this->magic_power_required << endl;
}
