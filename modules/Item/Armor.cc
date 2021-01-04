//////////////////////////
// Implementation of Armor
//////////////////////////


#include <iostream>
using namespace std;

#include "../../include/Item/Armor.h"



// Armor Functions

void Armor::print(void) {
    cout << "Armor with name: " << name << endl;
    cout << "It protects from damage up to " << damage_protect << "." << endl;
    Item::print();
}

