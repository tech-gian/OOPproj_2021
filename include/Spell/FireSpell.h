#pragma once

#include <stdlib.h>
#include <string>
using namespace std;

#include "../constants.h"
#include "Spell.h"
#include "../Living/Monster/Monster.h"

class FireSpell : public Spell {
    public:
        FireSpell(string name) : Spell(name, FS_PRICE, FS_MIN_LEVEL, FS_MIN_DAMAGE, FS_MAX_DAMAGE, FS_MAGIC_POWER_REQUIRED) {
            cout << "Constructor of FireSpell!" << endl;
        }
        // Εκτός από τη ζημιά που προκαλεί, μειώνει και το ποσό άμυνας του αντιπάλου για κάποιους γύρους
        void use(Monster* monster,  float dexterity);

        // TODO: if you want anything to add
        ~FireSpell();

        void print();
};
