///////////////////////////
// Implementation of Market
///////////////////////////


#include "../../../include/Grid/Market.h"

// Market Functions

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
    for (int i=0 ; i<3 ; ++i) displayStats(heroes[i]);

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

        list<Item*> items = heroes[num]->getInventory();
        list<Item*>::iterator it;
        for (it=items.begin() ; it!=items.end() ; ++it) {
            if ((*it)->get_name() == name) {
                heroes[num]->sell_item(*it);
            }
        }
    }
    else {
        cout << "Type the name of Spell you want: ";
        string name;
        cin >> name;
        cout << endl;

        list<Spell*> spells = heroes[num]->getSpells();
        list<Spell*>::iterator it;
        for (it=spells.begin() ; it!=spells.end() ; ++it) {
            if ((*it)->get_name() == name) {
                heroes[num]->sell_spell(*it);
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

    for (int i=0 ; i<3 ; ++i) {
        displayStats(heroes[i]);

        list<Item*> items = heroes[i]->getInventory();
        if (items.size() == 0) cout << "This hero doesn't have Items" << endl;
        else {
            cout << "Available Items:" << endl;

            list<Item*>::iterator it;
            for (it=items.begin() ; it!=items.end() ; ++it) {
                (*it)->print();
            }
        }
    }

    for (int i=0 ; i<3 ; ++i) {
        displayStats(heroes[i]);

        list<Spell*> spells = heroes[i]->getSpells();
        if (spells.size() == 0) cout << "This hero doesn't have Spells" << endl;
        else {
            cout << "Available Spells:" << endl;
        
            list<Spell*>::iterator it;
            for (it=spells.begin() ; it!=spells.end() ; ++it) {
                (*it)->print();
            }
        }
    }
}
