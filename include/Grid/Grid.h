////////////////////////////
// Header file of Class Grid
////////////////////////////


#pragma once

#include "Main_include.h"


// Grid
class Grid {
    int x;      // Dimensions of
    int y;      // the Grid
    Square*** squares;

    int posi;
    int posj;

    public:
    // Constructor
    Grid(Hero** heroes, int x, int y): x(x), y(y), posi(0), posj(0) {
        // Just initiliaze rand
        srand(time(NULL));

        squares = new Square**[x];
        for (int i=0 ; i<x ; ++i) squares[i] = new Square*[y];

        for (int i=0 ; i<x ; ++i) {
            for (int j=0 ; j<y ; ++j) {
                int temp = rand() % 3;

                // Initial position for heroes
                if (i == 0 && j == 0) {
                    squares[i][j] = new nonAccesible(heroes);
                }
                else if (temp == 0) {
                    squares[i][j] = new nonAccesible();
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
    void quitGame();

};

