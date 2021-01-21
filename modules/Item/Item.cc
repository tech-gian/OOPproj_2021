/////////////////////////
// Implementation of Item
/////////////////////////


#include <iostream>
using namespace std;

#include "../../include/Item/Item.h"


// Item Functions

void Item::print(void) const {
    // General print function for all types of Items
    cout << "Min level: " << min_level << ", price: " << price << endl;
}
