#pragma once

#include "../../constants.h"
#include "Hero.h"

#include <string>
using namespace std;

class Sorcerer : public Hero {
    public:
        // Ευνοημένος στον τομέα της επιδεξιότητας και της ευκινησίας
        Sorcerer(string name) : Hero(name, INIT_STRENGTH, INIT_DEXTERITY + 20, INIT_AGILITY + 20){}

        ~Sorcerer(){}
        
        // Όταν ο ήρωας ανεβαίνει επίπεδο, τα στατιστικά αυτά θα επηρεάζονται περισσότερο
        void levelUp();

        void print();
};
