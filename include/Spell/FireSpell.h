#pragma once

#include "../constants.h"
#include "Spell.h"
#include "../Living/Monster/Monster.h"

#include <stdlib.h>
#include <string>
using namespace std;

class FireSpell : public Spell {
    public:
        FireSpell(string name) : Spell(name, FS_PRICE, FS_MIN_LEVEL, FS_MIN_DAMAGE, FS_MAX_DAMAGE, FS_MAGIC_POWER_REQUIRED) {}
        // Εκτός από τη ζημιά που προκαλεί, μειώνει και το ποσό άμυνας του αντιπάλου για κάποιους γύρους
        void use(Monster* monster,  int dexterity);

        ~FireSpell() {}

        void print() const;
};
