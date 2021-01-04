///////////////////////////
// Implementation of Weapon
///////////////////////////


#include <iostream>
using namespace std;

#include "../../include/Item/Weapon.h"



// Weapon Functions

void Weapon::print(void) {
    cout << "Weapon with name: " << name << endl;
    cout << "It is a " << ((hands == 1) ? "one" : "two") << "-handed weapon and it causes damage up to " << damage << "!" << endl;
    Item::print();
}

