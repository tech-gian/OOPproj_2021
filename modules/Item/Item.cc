/////////////////////////
// Implementation of Item
/////////////////////////


#include "../../include/Item/Item.h"
#include <iostream>
using namespace std;


// Item Functions


void Item::print(void) {
    cout << name << ", min_level: " << min_level << ", price: " << price << endl;
}

