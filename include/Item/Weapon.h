////////////////////////
// Header file of Weapon
////////////////////////


#pragma once

#include "Item.h"
#include "../../include/constants.h"


// Weapon
class Weapon: public Item {
    int damage;     // Value of damage dealt
    int hands;      // 1 or 2 hands to use it

    public:
    // Constructor
    Weapon(string name, int hands): Item(name, WP_PRICE, WP_MIN_LEVEL), damage(WP_DAMAGE), hands(hands) {}

    // Destructor
    ~Weapon() {}

    // Get Functions
    // Get damage
    int get_dmg(void) const { return this->damage; }

    // Get hands
    int get_hands(void) const { return this-> hands; }

    // Get type
    char get_type(void) const { return 'w'; }

    // Print
    void print(void) const;
};
