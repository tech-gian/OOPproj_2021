#include "../constants.h"
#include "./spell.h"

class IceSpell : public Spell {
    public:
        IceSpell(string name) : Spell(name, IS_PRICE, IS_MIN_LEVEL, IS_MIN_DAMAGE, IS_MAX_DAMAGE, IS_MAGIC_POWER_REQUIRED){}
        // εκτός από τη ζημιά που προκαλεί, μειώνει και το εύρος ζημιάς του αντιπάλου για κάποιους γύρους
        void use();
};
