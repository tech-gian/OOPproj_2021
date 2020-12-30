////////////////////////
// Header file of Market
////////////////////////


#pragma once

#include "../Grid/Square.h"
#include "../Item/Item.h"
#include "../Spell/Spell.h"
#include "../Spell/FireSpell.h"
#include "../Spell/IceSpell.h"
#include "../Spell/LightingSpell.h"

#include <iostream>
#include <fstream>
using namespace std;


// Market
class Market: public Square {
    Item* items[SIZE_ITEMS];
    Spell* spells[SIZE_SPELLS];

    // Private Functions
    // Buy Items or Spells
    void buy(void);

    // Sell Items or Spells
    void sell(void);

    // Display available Items and Spells, to buy or to sell
    void displayAvailable(void);


    public:

    // Constructor
    Market(Hero** heroes): Square(heroes) {
        // Initialize heroes
        for (int i=0 ; i<3 ; ++i) {
            heroes[i] = NULL;
        }


        for (int i=0 ; i<SIZE_ITEMS ; ++i) {
            int temp = rand() % 3;

            if (temp == 0) {
                // Get random name from file
                ifstream file("../../../samples/weapons.txt");
                string weapon_name;
                int temp = rand() % WEAPONS_SIZE;
                for (int j=0 ; j<temp ; ++j) getline(file, weapon_name);
                file.close();

                // Create Weapon
                items[i] = new Weapon(weapon_name, (rand()%2)+1);
            }
            else if (temp == 1) {
                // Get random name from file
                ifstream file("../../../samples/armors.txt");
                string armor_name;
                int temp = rand() % ARMORS_SIZE;
                for (int j=0 ; j<temp ; ++j) getline(file, armor_name);
                file.close();

                // Create Armor
                items[i] = new Armor(armor_name);
            }
            else {
                // Get random name from file
                ifstream file("../../../samples/potions.txt");
                string potion_name;
                int temp = rand() % POTIONS_SIZE;
                for (int j=0 ; j<temp ; ++j) getline(file, potion_name);
                file.close();

                // TODO: declare which stat and make rand() for it
                items[i] = new Potion(potion_name, "TODO");
            }
        }

        // Get random name from file
        ifstream file("../../../samples/spells.txt");
        string spell_name;

        for (int i=0 ; i<SIZE_SPELLS ; ++i) {
            int temp = rand() % 3;

            // Get the next random line (spell_name)
            int temp_pos = rand() % (SPELLS_SIZE / SIZE_SPELLS);
            for (int j=0 ; j<temp_pos ; ++j) getline(file, spell_name);

            if (temp == 0) {
                spells[i] = new FireSpell(spell_name);
            }
            else if (temp == 1) {
                spells[i] = new IceSpell(spell_name);
            }
            else {
                spells[i] = new LightningSpell(spell_name);
            }
        }

        file.close();
    }

    // Destructor
    ~Market();

    // Virtual function must be declared
    void poss_fight(void) { cout << "Enter here by mistake!" << endl; }

    // Display Menu to get the user to buy/sell
    void displayMenu(void);

    // Get Functions
    // Get what square
    char get_sq(void) { return 'm'; }
};
