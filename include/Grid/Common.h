////////////////////////
// Header file of Common
////////////////////////



#pragma once

#include "Main_include.h"


// Common
class Common: public Square {
    Monster* monsters[3];   // Monsters to fight
    int possibility;        // Possibility for fight

    // Function for each round
    void round(void);

    public:
    // Constructor
    Common();

    // Destructor
    ~Common();


    // Fight function
    void fight();

    // Display Stats of heroes and Monsters
    void displayStats(void);

    // Get Functions
    // Get what square
    char get_sq(void) { return 'c'; }

};
