#pragma once

#include "../constants.h"

#include <string>
using namespace std;

class Living {
    protected:
        string name;        // Όνομα
        int level;          // Επίπεδο
        int healthPower;    // Ζωτική ενέργεια
    public:
        Living(string name, int level) : name(name), level(level), healthPower(INIT_HEALTH_POWER){}

        virtual ~Living(){}

        string getName(){ return this->name; };

        int get_life(void) { return this->healthPower; }

        int get_level(void) { return this->level; }

        // Αποδοχή ζημιάς από επίθεση αντιπάλου
        virtual void receiveDamage(int damage) = 0;

        // Οι ήρωες καθώς και τα τέρατα αναγεννούν σε κάθε γύρο κάποιο ποσό της ζωτικής τους ενέργεια
        virtual void regenerate() = 0;

        virtual void print() = 0;
};
