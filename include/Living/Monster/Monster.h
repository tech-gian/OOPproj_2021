#pragma once

#include "../../constants.h"
#include "../Living.h"
#include "../Hero/Hero.h"

#include <string>
using namespace std;

class Monster : public Living {
    protected:
        int min_damage;                     // Εύρος ζημιάς που μπορεί να προκαλέσει
        int max_damage;
        int defense;                        // Ποσό άμυνας το οποίο αϕαιρείται από τη ζημιά που δέχεται σε μια επίθεση του αντιπάλου του
        float possibilityOfAvoidance;       // Πιθανότητα να αποϕύγει κάποια επίθεση του αντιπάλου του

    public:
        Monster(string name, int min_damage, int max_damage, int defense, float possibilityOfAvoidance) : 
        Living(name), min_damage(min_damage), max_damage(max_damage), defense(defense), possibilityOfAvoidance(possibilityOfAvoidance){}
        
        // Εμϕάνιση στατιστικών τέρατος
        void displayStats();

        // Μείωση εύρους ζημιάς (από ξόρκι)
        void decreaseDamage();

        // Μείωση ποσού άμυνας (από ξόρκι)
        void decreaseDefense();

        // Μείωση πιθανότητας αποφυγής επίθεσης (από ξόρκι)
        void decreasePossibilityOfAvoidance();

        // Επίθεση τέρατος σε ήρωα
        void attack(Hero* Hero);

        // Αποδοχή ζημιάς από επίθεση ήρωα
        void receiveDamage(int damage);

        // Tα τέρατα αναγεννούν σε κάθε γύρο κάποιο ποσό της ζωτικής τους ενέργειας
        void regenerate();
};
