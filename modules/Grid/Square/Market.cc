///////////////////////////
// Implementation of Market
///////////////////////////


#include "../../../include/Grid/Market.h"

// Market Functions

Market::~Market() {
    // Delete Items and Spells created
    for (int i=0 ; i<SIZE_ITEMS ; ++i) {
        delete items[i];
    }

    for (int i=0 ; i<SIZE_SPELLS ; ++i) {
        delete spells[i];
    }
}


void Market::displayMenu(void) {
    // Assume input it correct
    while (true) {
        // Show options to buy/sell
        cout << "Below you will see the options to buy or to sell something:" << endl;
        displayAvailable();
        cout << "Type 'b' to buy something, 's' to sell something or 'n' for leaving the market: ";
        char ans;
        cin >> ans;
        
        // Choosing depends on answer
        if (ans == 'b') {
            buy();
        }
        else if (ans == 's') {
            sell();
        }
        else {
            cout << "You are leaving the market" << endl;
            break;
        }
    }
}


void Market::buy() {
    // Assume input is correct
    cout << "You selected to buy something. Type 'i' for Item or 's' for Spell: ";
    char ans;
    cin >> ans;
    
    // If player wants to buy Item
    if (ans == 'i') {
        // Get the name of Item
        cout << "Type the name of Item you want: " << endl;
        string name;
        cin.ignore();
        getline(cin, name);
        std::replace(name.begin(), name.end(), '\r', '\0');
        std::replace(name.begin(), name.end(), '\n', '\0');
        name.erase(std::remove(name.begin(), name.end(), '\0'), name.end());
        
        // Find it and add it to Inventory
        for (int i=0 ; i<SIZE_ITEMS ; ++i) {
            if (items[i]->get_name() == name) {
                cout << "Type the number of hero to add it: ";
                int num;
                cin >> num;

                if (items[i]->get_price() <= heroes[num]->getMoney()) {
                    heroes[num]->add_item(items[i]);
                    cout << heroes[num]->getName() << " bought " << items[i]->get_name() << " for " << items[i]->get_price() << endl;
                } else {
                    cout << heroes[num]->getName() << " doesn't have enough money to buy " << items[i]->get_name() << endl;
                }
                break;
            }
        }
    }
    // If player wants to buy Spell
    else {
        // Get the name of Spell
        cout << "Type the name of Spell you want: " << endl;
        string name;
        cin.ignore();
        getline(cin, name);
        std::replace(name.begin(), name.end(), '\r', '\0');
        std::replace(name.begin(), name.end(), '\n', '\0');
        name.erase(std::remove(name.begin(), name.end(), '\0'), name.end());

        // Find it and add it to Hero's Spells
        for (int i=0 ; i<SIZE_ITEMS ; ++i) {
            if (spells[i]->get_name() == name) {
                cout << "Type the number of hero to add it: ";
                int num;
                cin >> num;

                if (spells[i]->get_price() <= heroes[num]->getMoney()) {
                    heroes[num]->add_spell(spells[i]);
                    cout << heroes[num]->getName() << " bought " << items[i]->get_name() << " for " << items[i]->get_price() << endl;
                } else {
                    cout << heroes[num]->getName() << " doesn't have enough money to buy " << spells[i]->get_name() << endl;
                }
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
    
    // Get the Hero to sell from
    cout << "Type the number of hero to take it: ";
    int num;
    cin >> num;
    
    // If player wants to sell Item
    if (ans == 'i') {
        // Get the name of Item
        cout << "Type the name of Item you want: " << endl;
        string name;
        cin.ignore();
        getline(cin, name);
        std::replace(name.begin(), name.end(), '\r', '\0');
        std::replace(name.begin(), name.end(), '\n', '\0');
        name.erase(std::remove(name.begin(), name.end(), '\0'), name.end());

        // Find it in the Inventory
        list<Item*> items = heroes[num]->getInventory();
        list<Item*>::iterator it;
        for (it=items.begin() ; it!=items.end() ; ++it) {
            if ((*it)->get_name() == name) {
                heroes[num]->sell_item(*it);
                cout << heroes[num]->getName() << " sold " << (*it)->get_name() << " for " << (int) ((*it)->get_price() / 2) << endl;
            }
        }
    }
    // If player want to sell Spell
    else {
        // Get the name of Spell
        cout << "Type the name of Spell you want: " << endl;
        string name;
        cin.ignore();
        getline(cin, name);
        std::replace(name.begin(), name.end(), '\r', '\0');
        std::replace(name.begin(), name.end(), '\n', '\0');
        name.erase(std::remove(name.begin(), name.end(), '\0'), name.end());

        // Find in Hero's Spell
        list<Spell*> spells = heroes[num]->getSpells();
        list<Spell*>::iterator it;
        for (it=spells.begin() ; it!=spells.end() ; ++it) {
            if ((*it)->get_name() == name) {
                heroes[num]->sell_spell(*it);
                cout << heroes[num]->getName() << " sold " << (*it)->get_name() << " for " << (int) ((*it)->get_price() / 2) << endl;
            }
        }
    }
}


void Market::displayAvailable() {
    // Display every Item and Spell available on store
    cout << "Depending on your level, you can buy:" << endl;
    cout << "> Available Items:" << endl;

    // Display Items
    for (int i=0 ; i<SIZE_ITEMS ; ++i) {
        if (items[i]->get_min_level() <= heroes[0]->get_level()) {
            cout << "-----------------------------" << endl;
            items[i]->print();
        }
    }

    cout << "> Available Spells:" << endl;

    // Display Spell
    for (int i=0 ; i<SIZE_SPELLS ; ++i) {
        if (spells[i]->get_min_level() <= heroes[0]->get_level()) {
            cout << "-----------------------------" << endl;
            spells[i]->print();
        }
    }

    // Display every Item and Spell on player
    cout << "Depending on your bag, you can sell:" << endl;
    displayStats();
}
