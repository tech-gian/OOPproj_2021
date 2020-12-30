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

    // Function for each round
    void round(void);

    // Fight function
    void fight();


    public:

    Common();

    // Constructor
    Common(Hero** heroes): Square(heroes) {

        this->possibility = POSSIBILITY_OF_FIGHT;

        // Get random name from file
        ifstream file("../../../samples/names.txt");
        string monster_name;

        for (int i=0 ; i<3 ; ++i) {
            int temp = rand() % 3;

            // Get the next random line (monster_name)
            int temp_pos = rand() % (NAMES_SIZE / 3);
            for (int j=0 ; j<temp_pos ; ++j) getline(file, monster_name);

            if (temp == 0) {
                monsters[i] = new Dragon(monster_name, 1);
            }
            else if (temp == 1) {
                monsters[i] = new Exoskeleton(monster_name, 1);
            }
            else {
                monsters[i] = new Spirit(monster_name, 1);
            }
        }

        file.close();
    }

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

    // Σε κάθε γύρο, ο παίκτης μπορεί να εμϕανίσει τα στατιστικά κάθε τέρατος
    void displayStats(Monster* monster);

    // Possibility for fight or not
    void poss_fight(void);

    // Display Stats of heroes and Monsters
    void displayStats(void);

    // Get Functions
    // Get what square
    char get_sq(void) { return 'c'; }

    // Display Menu to get the user to buy/sell
    void displayMenu(void);


};
