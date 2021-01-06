/////////////////////////
// Implementation of Grid
/////////////////////////


#include <iostream>
using namespace std;

#include "../../include/Grid/Grid.h"

// Grid Functions

Grid::~Grid() {
    // Delete Squares
    for (int i=0 ; i<x ; ++i) {
        for (int j=0 ; j<y ; ++j) {
            delete squares[i][j];
        }
        delete[] squares[i];
    }
    delete[] squares;
}


void Grid::move(void) {
    // Initial position
    int init_i = posi;
    int init_j = posj;

    // Temp position
    int i = posi;
    int j = posj;
    bool flag;

    // Loop to make a move
    do {
        flag = false;

        // Get the next position, that player wants to go
        cout << "Type 'u' for up, 'd' for down, 'r' for right and 'l' for left: ";
        char p;
        cin >> p;

        // Necessary checks
        if (p == 'u' || p == 'd' || p == 'r' || p == 'l') {

            // Temp i, j
            int temp_i = i, temp_j = j;
            if (p == 'u') --temp_i;
            else if (p == 'd') ++temp_i;
            else if (p == 'r') ++temp_j;
            else if (p == 'l') --temp_j;

            if (temp_i < 0 || temp_i >= x || temp_j < 0 || temp_j >= y) {
                cout << "Out of bounds. Type again." << endl;
                flag = true;
            }
            else if (squares[temp_i][temp_j]->get_sq() == 'n') {
                cout << "Non Accesible square. Type again." << endl;
                flag = true;
            }

            if (!flag) {
                if (p == 'u') --i;
                else if (p == 'd') ++i;
                else if (p == 'r') ++j;
                else if (p == 'l') --j;
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

    // If Square is a Market
    if (squares[posi][posj]->get_sq() == 'm') {
        squares[posi][posj]->move_heroes(squares[init_i][init_j]);
        ((Market*)(squares[posi][posj]))->displayMenu();
    }
    // If Square is a Common
    else if (squares[posi][posj]->get_sq() == 'c') {
        ((Common*)(squares[posi][posj]))->move_heroes(squares[init_i][init_j]);
        ((Common*)(squares[posi][posj]))->poss_fight();
    }


}


void Grid::displayMap() {
    // Display Map to player, when asked
    for (int i=0 ; i<2*x-1 ; ++i) {
        for (int j=0 ; j<2*y-1 ; ++j) {

            if (i % 2 == 1) {
                cout << "--";
            }
            else {
                if (j % 2 == 0) {
                    if (squares[i/2][j/2]->is_hero()) {
                        cout << " H ";
                    }
                    else {
                        cout << " " << squares[i/2][j/2]->get_sq() << " ";
                    }
                }
                else {
                    cout << "|";
                }
            }
        }
        cout << endl;
    }
}


bool Grid::quitGame() {
    // Get answer, if player wants to quit game
    cout << "If you want to stop playing type 'q' or anything else to continue: ";
    char ans;
    cin >> ans;
    cout << endl;

    // If the player wants to quit the game
    if (ans == 'q') {
        cout << "-------------" << endl;
        cout << "Quit the Game" << endl;

        return false;
    }

    return true;
}


void Grid::do_anything(void) {
    // Give the player options to do while he goes
    // from Square to Square

    // Loop, if player wants more than one action
    while (true) {
        cout << "Type 'c' to checkInventory, 'd' to displayStats, 'w' to use different weapons, 'e' to equip armor, 'u' to use potion, or 'n' to do nothing: ";
        char ans;
        cin >> ans;
        cout << endl;

        // Check all the possibilities
        
        // Display each hero's Inventory
        if (ans == 'c') {
            for (int i=0 ; i<3 ; ++i) {
                // Display Items for each Hero
                list<Item*> items = heroes[i]->getInventory();
                if (items.size() > 0) {
                    cout << "Hero: " << heroes[i]->getName() << " has:" << endl;

                    list<Item*>::iterator it;
                    for (it=items.begin() ; it!=items.end() ; ++it) {
                        (*it)->print();
                    }
                }
                else {
                    cout << "Hero: " << heroes[i]->getName() << " has no Items" << endl;
                }
            }
        }
        // Display stats from each hero
        else if (ans == 'd') {
            for (int i=0 ; i<3 ; ++i) {
                heroes[i]->print();
            }
        }
        // Change Weapon
        else if (ans == 'w') {
            for (int i=0 ; i<3 ; ++i) {
                // Display their Weapon(s)
                Weapon* weapon;
                if ((weapon = heroes[i]->getWeapon('l')) != NULL) {
                    if (weapon->get_hands() == 1)
                        cout << "Left weapon: " << endl;
                    weapon->print();
                }

                if ((weapon = heroes[i]->getWeapon('r')) != NULL) {
                    if (weapon->get_hands() == 1)
                        cout << "Right weapon: " << endl;
                    weapon->print();
                }
            }

            // Get the number of Hero. Assume correct input
            cout << "Type the number of Hero you want to change his Weapon: ";
            int num;
            cin >> num;
            cout << endl;

            // Display his Items
            list<Item*> items = heroes[num]->getInventory();
            if (items.size() > 0) {
                cout << "Available Items:" << endl;

                list<Item*>::iterator it;
                for (it=items.begin() ; it!=items.end() ; ++it) {
                    (*it)->print();
                }

                // Get the Weapon to change
                cout << "Type the name of Weapon you want to change: ";
                string name;
                cin.ignore();
                getline(cin, name);
                std::replace(name.begin(), name.end(), '\r', '\0');
                std::replace(name.begin(), name.end(), '\n', '\0');
                name.erase(std::remove(name.begin(), name.end(), '\0'), name.end());
                cout << endl;

                // Find the Weapon
                if (items.size() > 0) {
                    list<Item*>::iterator it;
                    for (it=items.begin() ; it!=items.end() ; ++it) {
                        if ((*it)->get_name() == name) {
                            if ((*it)->get_type() == 'w') {
                                heroes[num]->setWeapon((Weapon*)(*it));
                            }
                            else {
                                cout << "This is not a Weapon. Try again" << endl;
                            }
                        }
                    }
                }
            }
            else {
                cout << "No Available Weapons. Try again" << endl;
            }
        }
        // Equip different Armor from Inventory
        else if (ans == 'e') {
            for (int i=0 ; i<3 ; ++i) {
                // Display their Armor
                Armor* armor;
                if ((armor = heroes[i]->getArmor()) != NULL)
                    armor->print();
            }

            // Get the number of Hero. Assume correct input
            cout << "Type the number of Hero you want to change his Armor: ";
            int num;
            cin >> num;
            cout << endl;

            // Display his Items
            list<Item*> items = heroes[num]->getInventory();
            if (items.size() > 0) {
                cout << "Available Items:" << endl;

                list<Item*>::iterator it;
                for (it=items.begin() ; it!=items.end() ; ++it) {
                    (*it)->print();
                }

                // Get the Armor to equip
                cout << "Type the name of Armor you want to change: ";
                string name;
                cin.ignore();
                getline(cin, name);
                std::replace(name.begin(), name.end(), '\r', '\0');
                std::replace(name.begin(), name.end(), '\n', '\0');
                name.erase(std::remove(name.begin(), name.end(), '\0'), name.end());
                cout << endl;

                // Find the Armor
                if (items.size() > 0) {
                    list<Item*>::iterator it;
                    for (it=items.begin() ; it!=items.end() ; ++it) {
                        if ((*it)->get_name() == name) {
                            if ((*it)->get_type() == 'a') {
                                heroes[num]->setArmor((Armor*)(*it));
                            }
                            else {
                                cout << "This is not an Armor. Try again" << endl;
                            }
                        }
                    }
                }
            }
            else {
                cout << "No Available Armors. Try again" << endl;
            }
        }
        // Use one Potion from Inventory
        else if (ans == 'u') {
            // Get the number of Hero. Assume correct input
            cout << "Type the number of Hero you want to use a Potion: ";
            int num;
            cin >> num;
            cout << endl;

            // Display his Items
            list<Item*> items = heroes[num]->getInventory();
            if (items.size() > 0) {
                cout << "Available Items:" << endl;

                list<Item*>::iterator it;
                for (it=items.begin() ; it!=items.end() ; ++it) {
                    (*it)->print();
                }

                // Get the Potion to use
                cout << "Type the name of Potion you want to use: ";
                string name;
                cin.ignore();
                getline(cin, name);
                std::replace(name.begin(), name.end(), '\r', '\0');
                std::replace(name.begin(), name.end(), '\n', '\0');
                name.erase(std::remove(name.begin(), name.end(), '\0'), name.end());
                cout << endl;

                // Find the Potion
                if (items.size() > 0) {
                    list<Item*>::iterator it;
                    for (it=items.begin() ; it!=items.end() ; ++it) {
                        if ((*it)->get_name() == name) {
                            if ((*it)->get_type() == 'p') {
                                heroes[num]->usePotion((Potion*)(*it));
                            }
                            else {
                                cout << "This is not a Potion. Try again" << endl;
                            }
                        }
                    }
                }
            }
            else {
                cout << "No Available Potions. Try again" << endl;
            }
        }
        // If player doesn't want to do anything else
        else {
            // Stop the Loop
            break;   
        }
    }
}
