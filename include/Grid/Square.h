/////////////////////////////////
// Header file of Abstract Square
/////////////////////////////////


#pragma once

#include "../Living/Hero/Hero.h"


// Square
class Square {
    // No private members

    protected:
    Hero* heroes[3];    // Heroes in this Square, else NULL

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
    virtual ~Square() {}

    // Ο παίκτης μπορεί ανά πάσα χρονική στιγμή να εμϕανίσει πληροϕορίες για τους ήρωές του
    void displayStats();

    // Get Funcions
    // Get what square
    virtual char get_sq(void) const = 0;

    // Move heroes, when player moves
    void move_heroes(Square* square);

    // Get if there are heroes
    bool is_hero(void) const { return (heroes[0] == NULL) ? false : true; }
};
