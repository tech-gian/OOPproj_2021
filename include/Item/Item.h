/////////////////////////////////////
// Header file of Abstract Class Item
/////////////////////////////////////


#pragma once

#include <string>
using namespace std;


// Item
class Item {
    // No private members

    protected:
    string name;        // Name of Item
    int price;          // Price of Item
    int min_level;      // Min level to take it

    public:
    // Constructor
    Item(string name, int price, int min): name(name), price(price), min_level(min) {}

    // Destructor
    virtual ~Item() {}

    // Get Function
    // Get name
    string get_name(void) const { return this->name; }

    // Get price
    int get_price(void) const { return this->price; }

    // Get min_level
    int get_min_level(void) const { return this->min_level; }

    // Get type of item
    virtual char get_type(void) const = 0;

    // Print
    virtual void print(void) const;
};
