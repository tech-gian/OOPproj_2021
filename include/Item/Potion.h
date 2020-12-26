////////////////////////
// Header file of Potion
////////////////////////


#pragma once

#include "Main_include.h"



// Potion
class Potion: public Item {
    int percentage;     // How much increased
    string stat;        // What statistic to increase
    bool used;          // If this potion is used or not

    public:
    // Constructor
    Potion(string name, string stat): Item(name, PT_PRICE, PT_MIN_LEVEL), percentage(PT_PERCENT), stat(stat), used(false) {}

    // Destructor
    ~Potion() {}

    // Get Functions
    // Get percentage
    int get_percent(void) { return this->percentage; }

    // returns "health"/"magic power"/"strength"/"dexterity"/"agility"
    string get_stat(void) { return this->stat; }

    // Get used
    bool get_used(void) { return this->used; }

    // Get type
    char get_type(void) { return 'p'; };

    // Print
    void print(void);

};
