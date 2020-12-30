#pragma once

#include <string>
using namespace std;

#include "../constants.h"

class Living {
    protected:
        string name;        // Όνομα
        int level;          // Επίπεδο
        int healthPower;    // Ζωτική ενέργεια
    public:
        Living(string name) : name(name), level(1), healthPower(INIT_HEALTH_POWER){}

        string getName(){ return this->name; };

        // Get healthPower
        int get_life(void) { return this->healthPower; }

        // Αποδοχή ζημιάς από επίθεση αντιπάλου
        virtual void receiveDamage(int damage) = 0;

        // Οι ήρωες καθώς και τα τέρατα αναγεννούν σε κάθε γύρο κάποιο ποσό της ζωτικής τους ενέργεια
        virtual void regenerate() = 0;
};
