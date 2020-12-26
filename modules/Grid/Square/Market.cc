///////////////////////////
// Implementation of Market
///////////////////////////



#pragma once

#include "Main_include.h"




// Market Functions

Market::Market() {
    srand(time(NULL));

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

Market::~Market() {
    for (int i=0 ; i<SIZE_ITEMS ; ++i) {
        delete items[i];
    }

    for (int i=0 ; i<SIZE_SPELLS ; ++i) {
        delete spells[i];
    }
}


void Market::displayMenu(void) {
    // Show money of each Hero
    cout << "You are on a Market Square. For each Hero you have:" << endl;
    for (int i=0 ; i<3 ; ++i) heroes[i]->print();

    // Show options to buy/sell
    cout << "Below you will see the options to buy or to sell something:" << endl;
    displayAvailable();

    // Assume input it correct
    cout << "Type 'b' to buy something, 's' to sell something or 'n' for nothing: ";
    char ans;
    cin >> ans;
    cout << endl;

    if (ans == 'b') {
        buy();
    }
    else if (ans == 's') {
        sell();
    }
    else {
        cout << "You choose to do nothing" << endl;
    }
}


void Market::buy() {
    // Assume input is correct
    cout << "You selected to buy something. Type 'i' for Item or 's' for Spell: ";
    char ans;
    cin >> ans;
    cout << endl;

    if (ans == 'i') {
        cout << "Type the name of Item you want: ";
        string name;
        cin >> name;
        cout << endl;

        for (int i=0 ; i<SIZE_ITEMS ; ++i) {
            if (items[i]->get_name() == name) {
                cout << "Type the number of hero to add it: ";
                int num;
                cin >> num;
                cout << endl;

                heroes[num]->add_item(items[i]);
                break;
            }
        }
    }
    else {
        cout << "Type the name of Spell you want: ";
        string name;
        cin >> name;
        
        for (int i=0 ; i<SIZE_ITEMS ; ++i) {
            if (spells[i]->get_name() == name) {
                cout << "Type the number of hero to add it: ";
                int num;
                cin >> num;
                cout << endl;

                heroes[num]->add_spell(spells[i]);
                break;
            }
        }
    }
}


void Market::sell() {
    // Assume input is correct
    cout << "You selected to sell something. Type 'i' for Item or 's' for Spell: ";
    char ans;
    cin >> ans;
    cout << endl;

    cout << "Type the number of hero to take it: ";
    int num;
    cin >> num;
    cout << endl;

    if (ans == 'i') {
        cout << "Type the name of Item you want: ";
        string name;
        cin >> name;
        cout << endl;

        for (int i=0 ; i<heroes[num]->items_size() ; ++i) {
            if (heroes[i]->get_items()[i]->get_name() == name) {
                heroes[num]->sell_item(heroes[i]->get_items()[i]);
                break;
            }
        }
    }
    else {
        cout << "Type the name of Spell you want: ";
        string name;
        cin >> name;
        cout << endl;

        for (int i=0 ; i<heroes[num]->spells_size() ; ++i) {
            if (heroes[i]->get_spells()[i]->get_name() == name) {
                heroes[num]->sell_spell(heroes[i]->get_spells()[i]);
                break;
            }
        }
    }
}


void Market::displayAvailable() {
    // Display every Item and Spell available on store
    cout << "Depending on your money, you can buy:" << endl;
    cout << "Available Items:" << endl;

    for (int i=0 ; i<SIZE_ITEMS ; ++i) {
        items[i]->print();
    }

    cout << "Available Spells:" << endl;

    for (int i=0 ; i<SIZE_SPELLS ; ++i) {
        spells[i]->print();
    }

    // Display every Item and Spell on player
    cout << "Depending on your bag, you can sell:" << endl;
    cout << "Available Items:" << endl;

    for (int i=0 ; i<3 ; ++i) {
        heroes[i]->print();

        Item** hero_items = heroes[i]->get_items();
        for (int j=0 ; j<heroes[i]->items_size() ; ++j) {
            hero_items[j]->print();
        }
    }

    cout << "Available Spells:" << endl;

    for (int i=0 ; i<3 ; ++i) {
        heroes[i]->print();

        Spell** hero_spells = heroes[i]->get_spells();
        for (int j=0 ; j<heroes[j]->spells_size() ; ++j) {
            hero_spells[j]->print();
        }
    }
}
