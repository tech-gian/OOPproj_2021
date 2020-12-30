/////////////////////////////////
// Header file of Abstract Square
/////////////////////////////////


#pragma once

#include "../Living/Hero/Hero.h"


// Square
class Square {

    protected:
    Hero* heroes[3];

    public:
    // Constructor
    Square(Hero** heroes) {
        if (heroes == NULL) {
            for (int i=0 ; i<3 ; ++i) {
                this->heroes[i] = NULL;
            }
        }
        else {
            for (int i=0 ; i<3 ; ++i) {
                this->heroes[i] = heroes[i];
            }
        }
    }

    // Default Destructor
    virtual ~Square();

    // Ο παίκτης μπορεί ανά πάσα χρονική στιγμή να εμϕανίσει πληροϕορίες για τους ήρωές του
    void displayStats(Hero* hero);

    // Get Funcions
    // Get what square
    virtual char get_sq(void) = 0;

    // Display Menu to get the user to buy/sell
    virtual void displayMenu(void);

    // Possibility for a fight or not
    virtual void poss_fight(void);

    // Move heroes, when player moves
    void move_heroes(Square* square);

    // Get if there are heroes
    bool is_hero(void) { return (heroes[0] == NULL) ? false : true; }
};
