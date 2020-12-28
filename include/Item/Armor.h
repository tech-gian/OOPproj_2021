///////////////////////
// Header file of Armor
///////////////////////


#pragma once
#include <string>
using namespace std;

#include "Item.h"
#include "../constants.h"


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

    // Get type
    char get_type(void) { return 'a'; }

    // Print
    void print(void);

    // Μείωση προστασίας ασπίδας κατά την επίθεση
    void decreaseDamageProtection(int damage) { this->damage_protect -= damage; }
};
