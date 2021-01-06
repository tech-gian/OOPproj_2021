///////////////////////////
// Implementation of Potion
///////////////////////////


#include <iostream>
using namespace std;

#include "../../include/Item/Potion.h"


// Potion Functions

void Potion::print(void) {
    // Specific print function for Potion
    cout << "Potion with name: " << name << endl;
    cout << "It is used to increase heroes " << stat << "." << endl;
    Item::print();
}

