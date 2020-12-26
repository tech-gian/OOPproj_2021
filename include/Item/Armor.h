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
    Armor(string name): Item(name, AR_PRICE, AR_MIN_LEVEL), damage_protect(AR_DAMAGE_PROT) {}

    // Destructor
    ~Armor() {}

    // Get Functions
    // Get damage_protect
    int get_protection(void) { return this->damage_protect; }

    // Print
    void print(void);

};
