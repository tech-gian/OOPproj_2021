#pragma once

#include <string>
using namespace std;

#include "../../constants.h"
#include "Hero.h"

class Warrior : public Hero {
    public:
        // ευνοημένος στον τομέα της δύναμης και της ευκινησίας
        Warrior(string name) : Hero(name, INIT_STRENGTH + 50, INIT_DEXTERITY, INIT_AGILITY + 50){}

        ~Warrior(){}
        
        // όταν ο ήρωας ανεβαίνει επίπεδο, τα στατιστικά αυτά θα επηρεάζονται περισσότερο
        void levelUp();
};
