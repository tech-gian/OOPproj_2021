///////////////////////
// Header file of Armor
///////////////////////


#pragma once

#include "Main_include.h"



// Armor
class Armor: public Item {
    int damage_protect;     // How much damage protected

    public:
    // Constructor
    Armor(string name, int price, int min, int damage_prot): Item(name, price, min), damage_protect(damage_prot) {}

    // Destructor
    ~Armor() {}

    // Get Functions
    // Get damage_protect
    int get_protection(void) { return this->damage_protect; }

};
