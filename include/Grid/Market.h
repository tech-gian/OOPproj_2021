////////////////////////
// Header file of Market
////////////////////////


#pragma once
#include <algorithm>

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
    Market(): Square(NULL) {
        // Opening all files
        ifstream file_weapons("../samples/weapons.txt");
        ifstream file_armors("../samples/armors.txt");
        ifstream file_potions("../samples/potions.txt");

        for (int i=0 ; i<SIZE_ITEMS ; ++i) {
            int temp = rand() % 3;

            if (temp == 0) {
                // Get random name from file
                string weapon_name;
                int temp = rand() % (WEAPONS_SIZE / SIZE_ITEMS);
                for (int j=0 ; j<temp ; ++j) getline(file_weapons, weapon_name);
                // If temp == 0, it should take the next line
                if (temp == 0) getline(file_weapons, weapon_name);
                std::replace(weapon_name.begin(), weapon_name.end(), '\r', '\0');
                std::replace(weapon_name.begin(), weapon_name.end(), '\n', '\0');
                weapon_name.erase(std::remove(weapon_name.begin(), weapon_name.end(), '\0'), weapon_name.end());

                // Create Weapon
                items[i] = new Weapon(weapon_name, (rand()%2)+1);
            }
            else if (temp == 1) {
                // Get random name from file
                string armor_name;
                int temp = rand() % (ARMORS_SIZE / SIZE_ITEMS);
                for (int j=0 ; j<temp ; ++j) getline(file_armors, armor_name);
                // If temp == 0, it should take the next line
                if (temp == 0) getline(file_armors, armor_name);
                std::replace(armor_name.begin(), armor_name.end(), '\r', '\0');
                std::replace(armor_name.begin(), armor_name.end(), '\n', '\0');
                armor_name.erase(std::remove(armor_name.begin(), armor_name.end(), '\0'), armor_name.end());
                // Create Armor
                items[i] = new Armor(armor_name);
            }
            else {
                // Get random name from file
                string potion_name;
                int temp = rand() % (POTIONS_SIZE / SIZE_ITEMS);
                for (int j=0 ; j<temp ; ++j) getline(file_potions, potion_name);
                // If temp == 0, it should take the next line
                if (temp == 0) getline(file_potions, potion_name);
                std::replace(potion_name.begin(), potion_name.end(), '\r', '\0');
                std::replace(potion_name.begin(), potion_name.end(), '\r', '\0');
                potion_name.erase(std::remove(potion_name.begin(), potion_name.end(), '\0'), potion_name.end());
                // Local array with stats
                string stats[] = {"health", "magic power", "strength", "dexterity", "agility"};
                int rand_stat = rand() % 5;
                items[i] = new Potion(potion_name, stats[rand_stat]);
            }
        }

        // Closing files
        file_weapons.close();
        file_armors.close();
        file_potions.close();

        // Get random name from file
        ifstream file("../samples/spells.txt");

        for (int i=0 ; i<SIZE_SPELLS ; ++i) {
            int temp = rand() % 3;
            string spell_name;

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

    // Display Menu to get the user to buy/sell
    void displayMenu(void);

    // Get Functions
    // Get what square
    char get_sq(void) { return 'm'; }
};
