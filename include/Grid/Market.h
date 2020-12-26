////////////////////////
// Header file of Market
////////////////////////


#pragma once

#include "Main_include.h"


// Market
class Market: public Square {
    Item* items[SIZE_ITEMS];
    Spell* spells[SIZE_SPELLS];


    public:
    // Constructor
    Market();

    // Destructor
    ~Market();

    // TODO
    // Display Menu to get the user to buy/sell
    void diplayMenu(void);

    // Buy Items or Spells
    void buy(void);

    // Sell Items or Spells
    void sell(void);

    // Display available Items and Spells, to buy or to sell
    void displayAvailable(void);

    // Get Functions
    // Get what square
    char get_sq(void) { return 'm'; }

};
