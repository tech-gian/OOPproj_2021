#pragma once

#include "../../constants.h"
#include "Hero.h"

#include <string>
using namespace std;

class Warrior : public Hero {
    public:
        // Ευνοημένος στον τομέα της δύναμης και της ευκινησίας
        Warrior(string name) : Hero(name, INIT_STRENGTH + 20, INIT_DEXTERITY, INIT_AGILITY + 20){}

        ~Warrior(){}
        
        // Όταν ο ήρωας ανεβαίνει επίπεδο, τα στατιστικά αυτά θα επηρεάζονται περισσότερο
        void levelUp();

        void print();
};
