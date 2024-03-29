#pragma once

#include "../constants.h"
#include "Spell.h"
#include "../Living/Monster/Monster.h"

#include <stdlib.h>
#include <string>
using namespace std;

class LightningSpell : public Spell {
    public:
        LightningSpell(string name) : Spell(name, LS_PRICE, LS_MIN_LEVEL, LS_MIN_DAMAGE, LS_MAX_DAMAGE, LS_MAGIC_POWER_REQUIRED) {}
        /* Εκτός από τη ζημιά που προκαλεί,
            μειώνει και την πιθανότητα να αποϕύγει μια επίθεση ο αντίπαλος για κάποιους γύρους */
        void use(Monster* monster,  int dexterity);

        ~LightningSpell(){};

        void print() const;
};
