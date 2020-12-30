#pragma once

#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

#include "../../constants.h"
#include "../Hero/Hero.h"
#include "../Living.h"

class Monster : public Living {
    protected:
        int min_damage;                     // Εύρος ζημιάς που μπορεί να προκαλέσει
        int max_damage;
        int defense;                        // Ποσό άμυνας το οποίο αϕαιρείται από τη ζημιά που δέχεται σε μια επίθεση του αντιπάλου του
        float possibilityOfAvoidance;       // Πιθανότητα να αποϕύγει κάποια επίθεση του αντιπάλου του

    public:
        Monster(string name, int min_damage, int max_damage, int defense, float possibilityOfAvoidance, int level) : 
        Living(name, level), min_damage(min_damage), max_damage(max_damage), defense(defense), possibilityOfAvoidance(possibilityOfAvoidance){}

        virtual ~Monster(){}

        int getMinDamage();
        int getMaxDamage();
        
        // Εμϕάνιση στατιστικών τέρατος
        void displayStats();

        // Μείωση εύρους ζημιάς (από ξόρκι)
        void decreaseDamage();

        // Μείωση ποσού άμυνας (από ξόρκι)
        void decreaseDefense();

        // Μείωση πιθανότητας αποφυγής επίθεσης (από ξόρκι)
        void decreasePossibilityOfAvoidance();

        // Αποδοχή ζημιάς από επίθεση ήρωα
        void receiveDamage(int damage);

        // Tα τέρατα αναγεννούν σε κάθε γύρο κάποιο ποσό της ζωτικής τους ενέργειας
        void regenerate();
};
