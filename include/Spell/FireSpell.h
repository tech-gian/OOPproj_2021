#include "../constants.h"
#include "./spell.h"

class FireSpell : public Spell {
    public:
        FireSpell(string name) : Spell(name, FS_PRICE, FS_MIN_LEVEL, FS_MIN_DAMAGE, FS_MAX_DAMAGE, FS_MAGIC_POWER_REQUIRED){}
        // εκτός από τη ζημιά που προκαλεί, μειώνει και το ποσό άμυνας του αντιπάλου για κάποιους γύρους
        void use();
};
