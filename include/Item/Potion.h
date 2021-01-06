////////////////////////
// Header file of Potion
////////////////////////


#pragma once

#include <string>
using namespace std;

#include "Item.h"
#include "../constants.h"


// Potion
class Potion: public Item {
    int percentage;     // How much increased
    string stat;        // What statistic to increase

    public:
    // Constructor
    Potion(string name, string stat): Item(name, PT_PRICE, PT_MIN_LEVEL), percentage(PT_PERCENT), stat(stat) {}

    // Destructor
    ~Potion() {}

    // Get Functions
    // Get percentage
    int get_percent(void) { return this->percentage; }

    // returns "health"/"magic power"/"strength"/"dexterity"/"agility"
    string get_stat(void) { return this->stat; }

    // Get type
    char get_type(void) { return 'p'; };

    // Print
    void print(void);
};
