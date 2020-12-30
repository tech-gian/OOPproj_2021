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
    ~nonAccesible();

    // Virtual function must be declared
    void poss_fight(void) { cout << "Enter here by mistake!" << endl; }

    // Get Functions
    // Get what square
    char get_sq(void) { return 'n'; }

    // Virtual function must be declared
    void displayMenu(void) { cout << "Enter here by mistake!" << endl; }

};
