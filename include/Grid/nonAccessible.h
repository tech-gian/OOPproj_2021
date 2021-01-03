//////////////////////////////
// Header file of nonAccesible
//////////////////////////////


#pragma once

#include "../Grid/Square.h"
#include "../Living/Hero/Hero.h"


// nonAccesible
class nonAccesible: public Square {


    public:
    // Constructor
    nonAccesible(Hero** heroes): Square(heroes) {}

    // Destructor
    ~nonAccesible() {}

    // Get Functions
    // Get what square
    char get_sq(void) { return 'n'; }

};