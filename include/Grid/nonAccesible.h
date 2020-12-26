//////////////////////////////
// Header file of nonAccesible
//////////////////////////////


#pragma once

#include "Main_include.h"


// nonAccesible
class nonAccesible: public Square {


    public:
    // Constructor
    nonAccesible() {}

    // Destructor
    ~nonAccesible() {}

    // Get Functions
    // Get what square
    char get_sq(void) { return 'n'; }

};
