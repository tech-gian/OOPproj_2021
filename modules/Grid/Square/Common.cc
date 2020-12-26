///////////////////////////
// Implementation of Common
///////////////////////////



#pragma once

#include "Main_include.h"




// Common Functions

Common::Common() {
    this->possibility = POSSIBILITY_OF_FIGHT;

    srand(time(NULL));
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
    // TODO: get life up, by a percent for heroes and for monsters
    // TODO: get magic up, by a percent for heroes

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

        // Cast Spell
        heroes[hero_num]->castSpell(spell, monsters[mon_num]);  // TODO
    }
    else if (ans == 'u') {
        cout << "Type the number of hero you want to use it: ";
        int hero_num;
        cin >> hero_num;
        cout << endl;
        Item** items = heroes[hero_num]->checkInventory();

        for (int i=0 ; i<heroes[hero_num]->items_size() ; ++i) {
            items[i]->print();
        }

        cout << "Type the number of item you want to use: ";
        int item;
        cin >> item;
        cout << endl;

        // We "use" the correct Item from Inventory
        if (items[item]->get_type() == 'a') {
            heroes[hero_num]->equip((Armor*) items[item]);
        }
        else if (items[item]->get_type() == 'w') {
            heroes[hero_num]->equip((Weapon*) items[item]);
        }
        else if (items[item]->get_type() == 'p') {
            heroes[hero_num]->use((Potion*) items[item]);
        }
    }
}


void Common::fight() {

}


void Common::displayStats(void) {
    cout << "Below are shown heroes stats:" << endl;
    for (int i=0 ; i<3 ; ++i) heroes[i]->displayStats();

    cout << "Below are shown monsters stats:" << endl;
    for (int i=0 ; i<3 ; ++i) monsters[i]->displayStats();
}

