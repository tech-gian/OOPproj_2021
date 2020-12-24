#include "../../constants.h"
#include "../Living.h"

class Monster : public Living {
    protected:
        int min_damage;                     // εύρος ζημιάς που μπορεί να προκαλέσει
        int max_damage;
        int defense;                        // ποσό άμυνας το οποίο αϕαιρείται από τη ζημιά που δέχεται σε μια επίθεση του αντιπάλου του
        float possibilityOfAvoidance;       // πιθανότητα να αποϕύγει κάποια επίθεση του αντιπάλου του

    public:
        Monster(string name, int min_damage, int max_damage, int defense, float possibilityOfAvoidance) : 
        Living(name), min_damage(min_damage), max_damage(max_damage), defense(defense), possibilityOfAvoidance(possibilityOfAvoidance){}
};
