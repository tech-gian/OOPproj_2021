/////////////////////////
// Implementation of Item
/////////////////////////


#include "../../include/Item/Item.h"
#include <iostream>
using namespace std;


// Item Functions


void Item::print(void) {
    cout << "Min level: " << min_level << ", price: " << price << endl;
}
