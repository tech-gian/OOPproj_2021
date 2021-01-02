///////////////////////////
// Implementation of Weapon
///////////////////////////


#include <iostream>
using namespace std;

#include "../../include/Item/Weapon.h"



// Weapon Functions

void Weapon::print(void) {
    cout << "Weapon with name: " << name << endl;
    Item::print();
}

