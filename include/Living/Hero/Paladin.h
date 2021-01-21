#pragma once

#include "../../constants.h"
#include "Hero.h"

#include <string>
using namespace std;

class Paladin : public Hero {
    public:
        // Ευνοημένος στον τομέα της δύναμης και της επιδεξιότητας
        Paladin(string name) : Hero(name, INIT_STRENGTH + 20, INIT_DEXTERITY + 20, INIT_AGILITY){}

        ~Paladin(){}
        
        // Όταν ο ήρωας ανεβαίνει επίπεδο, τα στατιστικά αυτά θα επηρεάζονται περισσότερο
        void levelUp();

        void print() const;
};
