#pragma once

#include "../constants.h"
#include "Spell.h"
#include "../Living/Monster/Monster.h"

#include <stdlib.h>
#include <string>
using namespace std;

class IceSpell : public Spell {
    public:
        IceSpell(string name) : Spell(name, IS_PRICE, IS_MIN_LEVEL, IS_MIN_DAMAGE, IS_MAX_DAMAGE, IS_MAGIC_POWER_REQUIRED) {}
        // Εκτός από τη ζημιά που προκαλεί, μειώνει και το εύρος ζημιάς του αντιπάλου για κάποιους γύρους
        void use(Monster* monster,  int dexterity);

        ~IceSpell(){};

        void print() const;
};
