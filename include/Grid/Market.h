////////////////////////
// Header file of Market
////////////////////////


#pragma once

#include "Main_include.h"


// Market
class Market: public Square {


    public:
    // Constructor
    Market() {}

    // Destructor
    ~Market() {}


    // Buy Items or Spells
    void buy();

    // Sell Items or Spells
    void sell();

    // Display available Items and Spells, to buy or to sell
    void displayAvailable();

};
