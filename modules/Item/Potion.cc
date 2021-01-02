///////////////////////////
// Implementation of Potion
///////////////////////////


#include <iostream>
using namespace std;

#include "../../include/Item/Potion.h"



// Potion Functions

void Potion::print(void) {
    cout << "Potion with name: " << name << endl;
    Item::print();
}

