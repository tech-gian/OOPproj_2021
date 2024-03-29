////////////////////////////
// Header file of Class Grid
////////////////////////////


#pragma once

#include "Square.h"
#include "nonAccessible.h"
#include "Market.h"
#include "Common.h"
#include "../Living/Hero/Hero.h"


// Grid
class Grid {
    int x;              // Dimensions of
    int y;              // the Grid
    Square*** squares;  // A 2-dimensional array of Grid (the Squares)

    Hero** heroes;      // Heroes playing
    int posi;           // Current position
    int posj;           // of the Heroes' team

    public:
    // Constructor
    Grid(Hero** heroes, int x, int y): x(x), y(y), heroes(heroes), posi(0), posj(0) {
        // Just initiliaze
        squares = new Square**[x];
        for (int i=0 ; i<x ; ++i) squares[i] = new Square*[y];

        for (int i=0 ; i<x ; ++i) {
            for (int j=0 ; j<y ; ++j) {
                int temp = rand() % 3;

                // Initial position for heroes
                if (i == 0 && j == 0) {
                    squares[i][j] = new nonAccesible(heroes);
                }

                // Create 2 Squares in purpose
                // so player can make at least one move
                else if (i == 0 && j == 1) {
                    squares[i][j] = new Common();
                }
                else if (i == 1 && j == 0) {
                    squares[i][j] = new Market();
                }

                // The rest create random
                else if (temp == 0) {
                    squares[i][j] = new nonAccesible(NULL);
                }
                else if (temp == 1) {
                    squares[i][j] = new Market();
                }
                else {
                    squares[i][j] = new Common();
                }
            }
        }
    }

    // Destructor
    ~Grid();

    // Move Player
    void move(void);

    // Display Map
    void displayMap();

    // Quit the game
    bool quitGame();

    // Do anything else, when finished from a Square
    void do_anything(void);
};
