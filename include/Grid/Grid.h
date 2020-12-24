////////////////////////////
// Header file of Class Grid
////////////////////////////


#pragma once

#include "Main_include.h"


// Grid
class Grid {
    int x;      // Dimensions of
    int y;      // the Grid
    Square** squares;

    public:
    // Constructor
    Grid(int x, int y): x(x), y(y) {}

    // Destructor
    ~Grid() {}


    // Display Map
    void displayMap();


    // Quit the game
    void quitGame();

};

