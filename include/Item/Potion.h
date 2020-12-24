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
    Potion(string name, int price, int min, int percent, string stat): Item(name, price, min), percentage(percent), stat(stat), used(false) {}

    // Destructor
    ~Potion() {}

    // Get Functions
    // Get percentage
    int get_percent(void) { return this->percentage; }

    // Get statistic
    string get_stat(void) { return this->stat; }

    // Get used
    bool get_used(void) { return this->used; }

};
