////////////////////////
// Header file of Weapon
////////////////////////


#pragma once

#include "Main_include.h"



// Weapon
class Weapon: public Item {
    int damage;     // Value of damage dealt
    int hands;      // 1 or 2 hands to use it

    public:
    // Constructor
    Weapon(string name, int price, int min, int damage, int hands): Item(name, price, min), damage(damage), hands(hands) {}

    // Destructor
    ~Weapon() {}

    // Get Functions
    // Get damage
    int get_dmg(void) { return this->damage; }

    // Get hands
    int get_hands(void) { return this-> hands; }


};
