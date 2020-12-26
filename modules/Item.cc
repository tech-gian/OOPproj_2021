//////////////////////////////////
// Implementation of Functions for
// Item, Weapon, Armor, Potion
//////////////////////////////////


#pragma once

#include "Main_include.h"



// Item Functions


void Item::print(void) {
    cout << name << ", min_level: " << min_level << ", price: " << price << endl;
}




// Weapon Functions

void Weapon::print(void) {
    cout << "Weapon with name: ";
    Item::print();
}



// Armor Functions

void Armor::print(void) {
    cout << "Armor with name: ";
    Item::print();
}



// Potion Functions

void Potion::print(void) {
    cout << "Potion with name: ";
    Item::print();
}



