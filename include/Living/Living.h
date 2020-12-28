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

        // Get healthPower
        int get_life(void) { return this->healthPower; }

        // Σε κάθε γύρο, ο παίκτης μπορεί να εμϕανίσει τα στατιστικά κάθε ήρωα και τέρατος
        virtual void displayStats() = 0;

        // Αποδοχή ζημιάς από επίθεση αντιπάλου
        virtual void receiveDamage(int damage) = 0;

        // Οι ήρωες καθώς και τα τέρατα αναγεννούν σε κάθε γύρο κάποιο ποσό της ζωτικής τους ενέργεια
        virtual void regenerate() = 0;
};
