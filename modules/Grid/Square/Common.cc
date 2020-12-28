///////////////////////////
// Implementation of Common
///////////////////////////



#pragma once

#include "Main_include.h"




// Common Functions

Common::Common() {
    // Initialize heroes
    for (int i=0 ; i<3 ; ++i) {
        heroes[i] = NULL;
    }

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
            monsters[i] = new Dragon(monster_name);
        }
        else if (temp == 1) {
            monsters[i] = new Exoskeleton(monster_name);
        }
        else {
            monsters[i] = new Spirit(monster_name);
        }
    }

    file.close();
}

Common::~Common() {
    for (int i=0 ; i<3 ; ++i) {
        delete monsters[i];
    }
}


void Common::round(void) {
    // Display Stats or not
    cout << "Type 'y' if you want to display Stats of heroes and monsters or 'n' if you don't want: ";
    char ans;
    cin >> ans;
    cout << endl;
    if (ans == 'y') displayStats();

    // Show options to player
    cout << "Type 'a' to attack, 'c' to cast Spell or 'u' to use some Item: ";
    cin >> ans;
    cout << endl;

    // Depending on the answers, make the correct option
    if (ans == 'a') {
        cout << "Type the number of hero you want to attack with: ";
        int hero_num;
        cin >> hero_num;
        cout << endl;

        cout << "Type the number of monster you want to attack: ";
        int mon_num;
        cin >> mon_num;
        cout << endl;

        // Attack
        heroes[hero_num]->attack(monsters[mon_num]);
    }
    else if (ans == 'c') {
        cout << "Type the number of hero you want to attack with: ";
        int hero_num;
        cin >> hero_num;
        cout << endl;

        cout << "Type the number of monster you want to attack: ";
        int mon_num;
        cin >> mon_num;
        cout << endl;

        cout << "Type the number of Spell you want to use: ";
        int spell;
        cin >> spell;
        cout << endl;

        // To find the correct spell
        list<Spell*> spells = heroes[hero_num]->get_spells();
        list<Spell*>::iterator it;
        int temp = 0;
        for (it=spells.begin() ; it!=spells.end() ; ++it) {
            if (temp == spell) break;
            ++temp;
        }

        // Cast Spell
        heroes[hero_num]->castSpell((*it), monsters[mon_num]);
    }
    else if (ans == 'u') {
        cout << "Type the number of hero you want to use it: ";
        int hero_num;
        cin >> hero_num;
        cout << endl;
        list<Item*> items = heroes[hero_num]->checkInventory();
        list<Item*>::iterator it;

        for (it=items.begin() ; it!=items.end() ; ++it) {
            (*it)->print();
        }   

        cout << "Type the number of item you want to use: ";
        int item;
        cin >> item;
        cout << endl;

        // To find the correct item
        int temp = 0;
        for (it=items.begin() ; it!=items.end() ; ++it) {
            if (temp == item) break;
            ++temp;
        }

        // We "use" the correct Item from Inventory
        if ((*it)->get_type() == 'a') {
            heroes[hero_num]->equip((Armor*) (*it));
        }
        else if ((*it)->get_type() == 'w') {
            heroes[hero_num]->equip((Weapon*) (*it));
        }
        else if ((*it)->get_type() == 'p') {
            heroes[hero_num]->use((Potion*) (*it));
        }
    }

    // Monsters attack
    for (int i=0 ; i<3 ; ++i) {
        int temp = rand() % 3;

        // Attack based on hero->agility
        if (rand() % 100 < heroes[temp]->get_agility()) {
            monsters[i]->attack(heroes[temp]);
        }
        else {
            cout << "Hero is too fast and avoided monster's attack" << endl;
        }
    }
}


void Common::poss_fight(void) {
    // Possibility for a fight
    int poss = (int) (possibility) * 100;

    int temp = rand() % 100;
    if (temp < poss) {
        cout << "You got into a fight!" << endl;
        fight();
    }
    else {
        cout << "You are in a Common square" << endl;
    }
}


void Common::fight() {
    bool life_heroes, life_monsters;
    int monsters_dead = 3;

    // Loop for a battle
    // Each loop is a round of fight
    while (true) {
        life_heroes = true;
        life_monsters = true;

        for (int i=0 ; i<3 ; ++i) {
            if (heroes[i]->get_life() != 0) {
                life_heroes = false;
            }
            if (monsters[i]->get_life() != 0) {
                --monsters_dead;
                life_monsters = false;
            }
        }

        // Main condition
        if (life_heroes || life_monsters) {
            break;
        }

        round();

        for (int i=0 ; i<3 ; ++i) {
            heroes[i]->regenerate();
            monsters[i]->regenerate();
        }
    }

    // If some hero has life == 0, get it to half of original
    for (int i=0 ; i<3 ; ++i) {
        if (heroes[i]->get_life() == 0) {
            heroes[i]->half_life();
        }
    }

    // If heroes win
    if (life_monsters) {
        for (int i=0 ; i<3 ; ++i) {
            heroes[i]->win(monsters_dead);
        }
    }
    // If monsters win
    else if (life_heroes) {
        for (int i=0 ; i<3 ; ++i) {
            heroes[i]->lose();
        }
    }

}


void Common::displayStats(void) {
    cout << "Below are shown heroes stats:" << endl;
    for (int i=0 ; i<3 ; ++i) heroes[i]->displayStats();

    cout << "Below are shown monsters stats:" << endl;
    for (int i=0 ; i<3 ; ++i) monsters[i]->displayStats();
}

