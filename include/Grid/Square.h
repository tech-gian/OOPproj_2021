/////////////////////////////////
// Header file of Abstract Square
/////////////////////////////////


#pragma once

#include "Main_include.h"


// Square
class Square {

    protected:
    Hero* heroes[3];

    public:
    // Constructor
    Square() {}

    // Destructor
    ~Square() {}

    // Get Funcions
    // Get what square
    virtual char get_sq(void) = 0;

    // Buy function for Market
    virtual void buy(void);

    // Sell function for Market
    virtual void sell(void);

};
