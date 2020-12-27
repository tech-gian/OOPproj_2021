#include "../../constants.h"
#include "./Hero.h"

class Paladin : public Hero {
    public:
        // ευνοημένος στον τομέα της δύναμης και της επιδεξιότητας
        Paladin(string name) : Hero(name, INIT_STRENGTH + 50, INIT_DEXTERITY + 50, INIT_AGILITY){}
        
        // όταν ο ήρωας ανεβαίνει επίπεδο, τα στατιστικά αυτά θα επηρεάζονται περισσότερο
        void levelUp();
};
