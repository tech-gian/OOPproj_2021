//////////////////////////////////
// Implementation of Grid, Square,
// nonAccesible, Market and Common
//////////////////////////////////



#pragma once

#include "Main_include.h"


// Grid Functions

Grid::~Grid() {
    for (int i=0 ; i<x ; ++i) {
        for (int j=0 ; j<y ; ++j) {
            delete squares[i][j];
        }
        delete squares[i];
    }
    delete squares;
}


void Grid::move(void) {
    int i = posi;
    int j = posj;
    bool flag;

    // Loop to make a move
    do {
        flag = false;

        cout << "Type 'u' for up, 'd' for down, 'r' for right and 'l' for left: ";
        char p;
        cin >> p;
        cout << endl;

        if (p == 'u' || p == 'd' || p == 'r' || p == 'l') {
            if (p == 'u') --i;
            else if (p == 'd') ++i;
            else if (p == 'r') ++j;
            else if (p == 'l') --j;

            if (i < 0 || i >= x || j < 0 || j >= y) {
                cout << "Out of bounds. Type again." << endl;
                flag = true;
            }
            else if (squares[i][j]->get_sq() == 'n') {
                cout << "Non Accesible square. Type again." << endl;
                flag = true;
            }
        }
        else {
            flag = true;
            cout << "Wrong input. Type again." << endl;
        }

    } while (flag);

    // After everything is ok,
    // do whatever each square does
    posi = i;
    posj = j;

    if (squares[posi][posj]->get_sq() == 'm') {
        cout << "You are on a Market square. Type 'b' to buy, 's' to sell or 'n' for nothing: ";
        char answer;
        cin >> answer;
        cout << endl;

        if (answer == 'b') {
            squares[posi][posj]->buy();
        }
        else if (answer == 's') {
            squares[posi][posj]->sell();
        }
        else {
            cout << "You choose to do nothing." << endl;
        }
    }
    else if (squares[posi][posj]->get_sq() == 'c') {
        // TODO
    }


}


void Grid::displayMap() {

}


void Grid::quitGame() {

}




// Market Functions

Market::Market() {
    srand(time(NULL));

    for (int i=0 ; i<SIZE_ITEMS ; ++i) {
        int temp = rand() % 3;

        if (temp == 0) {
            // Get random name from file
            ifstream file("../samples/weapons.txt");
            string weapon_name;
            int temp = rand() % WEAPONS_SIZE;
            for (int j=0 ; j<temp ; ++j) getline(file, weapon_name);
            file.close();

            // Create Weapon
            items[i] = new Weapon(weapon_name, (rand()%2)+1);
        }
        else if (temp == 1) {
            // Get random name from file
            ifstream file("../samples/armors.txt");
            string armor_name;
            int temp = rand() % ARMORS_SIZE;
            for (int j=0 ; j<temp ; ++j) getline(file, armor_name);
            file.close();

            // Create Armor
            items[i] = new Armor(armor_name);
        }
        else {
            // Get random name from file
            ifstream file("../samples/potions.txt");
            string potion_name;
            int temp = rand() % POTIONS_SIZE;
            for (int j=0 ; j<temp ; ++j) getline(file, potion_name);
            file.close();

            // TODO: declare which stat and make rand() for it
            items[i] = new Potion(potion_name, "TODO");
        }
    }

    // Get random name from file
    ifstream file("../samples/spells.txt");
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


void Market::diplayMenu(void) {

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
        heroes[i]->displayStats();                              // CHANGE print() to displayStats(). Make sure this is what u need

        Item** hero_items = heroes[i]->checkInventory();        // CHANGE getItems() to checkInventory(). Make sure this is what u need
        for (int j=0 ; j<heroes[i]->items_size() ; ++j) {       // Maybe we replace 295-298 with heroes[i]->checkInventory() and change checkInventory() implementation
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




// Common Functions

void Common::fight() {

}


void Common::displayStats() {
    
}



