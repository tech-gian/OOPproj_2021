#pragma once
#include "../Living/Monster/Monster.h"

#include <string>
#include <iostream>
using namespace std;

class Spell{
    protected:
        string name;                // Όνομα
        int price;                  // Τιμή
        int min_level;              // Ελάχιστο επίπεδο στο οποίο πρέπει να βρίσκεται ο ήρωας για να το χρησιμοποιήσει
        int min_damage;             // Εύρος ζημιάς που μπορεί να προκαλέσει
        int max_damage; 
        int magic_power_required;   // Ποσό μαγικής ενέργειας που απαιτεί για να εκτελεστεί
    public:
        Spell(string name, int price, int min_level, int min_damage, int max_damage, int magic_power_required) :
        name(name), price(price), min_level(min_level), min_damage(min_damage), max_damage(max_damage), magic_power_required(magic_power_required){}

        string get_name(void);

        int get_price();

        int get_min_level();

        int getMagicPowerRequired();

        virtual void use(Monster* monster, float dexterity) = 0;

        virtual void print();
};
