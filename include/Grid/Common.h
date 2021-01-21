////////////////////////
// Header file of Common
////////////////////////


#pragma once

#include "Square.h"
#include "../Living/Monster/Monster.h"
#include "../Living/Monster/Dragon.h"
#include "../Living/Monster/Exoskeleton.h"
#include "../Living/Monster/Spirit.h"

#include <fstream>
#include <iostream>
#include <string>
using namespace std;


// Common
class Common: public Square {
    Monster* monsters[3];   // Monsters to fight
    int possibility;        // Possibility for fight

    bool got_fight;         // True if got into a fight

    // Private Functions
    // Function for each round
    void round(void);

    // Fight function
    void fight();

    public:
    // Constructor
    Common();

    // Destructor
    ~Common();

    // ΄Οταν οι ήρωες δεν αγοράζουν ή πωλούν αντικείμενα και όταν δεν μάχονται
    // ...μπορούν να ελέγξουν τι αντικείμενα διαθέτουν 
    void checkInventory(Hero* hero);

    // ...να χρησιμοποιήσουν διαϕορετικά όπλα
    void equip(Hero* hero, Weapon* weapon);

    // ...να ϕορέσουν άλλη πανοπλία
    void equip(Hero* hero, Armor* armor);

    // ...να χρησιμοποιήσουν κάποιο ϕίλτρο
    void use(Hero* hero, Potion* potion);

    // ο παίκτης επιλέγει για κάθε ήρωα αν θα κάνει κανονική επίθεση
    void attack(Hero* hero, Monster* monster);

    void attack(Monster* monster, Hero* hero);

    // αν θα κάνει επίθεση με κάποιο ξόρκι
    void castSpell(Hero* hero, Monster* monster, Spell* spell);

    // Possibility for fight or not
    void poss_fight(void);

    // Display Stats of heroes and Monsters
    void displayStats(void);

    // Get Functions
    // Get what square
    char get_sq(void) const { return 'c'; }

    // Display Menu to get the user to buy/sell
    void displayMenu(void);
};
