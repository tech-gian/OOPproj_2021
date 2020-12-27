#include "../constants.h"
#include "./spell.h"
#include "../Living/Monster/Monster.h"

class LightningSpell : public Spell {
    public:
        LightningSpell(string name) : Spell(name, LS_PRICE, LS_MIN_LEVEL, LS_MIN_DAMAGE, LS_MAX_DAMAGE, LS_MAGIC_POWER_REQUIRED){}
        /* Εκτός από τη ζημιά που προκαλεί,
            μειώνει και την πιθανότητα να αποϕύγει μια επίθεση ο αντίπαλος για κάποιους γύρους */
        void use(Monster* monster,  float dexterity);

        void print();
};
