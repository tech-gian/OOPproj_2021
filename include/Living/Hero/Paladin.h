#pragma once

#include <string>
using namespace std;

#include "../../constants.h"
#include "Hero.h"

class Paladin : public Hero {
    public:
        // ευνοημένος στον τομέα της δύναμης και της επιδεξιότητας
        Paladin(string name) : Hero(name, INIT_STRENGTH + 20, INIT_DEXTERITY + 20, INIT_AGILITY){}

        ~Paladin(){}
        
        // όταν ο ήρωας ανεβαίνει επίπεδο, τα στατιστικά αυτά θα επηρεάζονται περισσότερο
        void levelUp();
};
