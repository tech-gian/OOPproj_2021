#pragma once

#include <string>
using namespace std;

#include "../../constants.h"
#include "Hero.h"

class Sorcerer : public Hero {
    public:
        // ευνοημένος στον τομέα της επιδεξιότητας και της ευκινησίας
        Sorcerer(string name) : Hero(name, INIT_STRENGTH, INIT_DEXTERITY + 50, INIT_AGILITY + 50){}

        ~Sorcerer(){}
        
        // όταν ο ήρωας ανεβαίνει επίπεδο, τα στατιστικά αυτά θα επηρεάζονται περισσότερο
        void levelUp();
};
