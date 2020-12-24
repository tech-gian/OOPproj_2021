#include "../../constants.h"
#include "../Living.h"

class Hero : public Living {
    protected:
        int magicPower;         // ποσό μαγικής ενέργειας
        int strength;           // τιμή δύναμης
        int dexterity;          // τιμή επιδεξιότητας
        int agility;            // τιμή ευκινησίας
        int money;              // ποσό χρημάτων
        int experience;         // ποσό εμπειρίας
    public:
        Hero(string name, int strength, int dexterity, int agility)
        : Living(name), magicPower(INIT_MAGIC_POWER), strength(strength), dexterity(dexterity), agility(agility), money(INIT_MONEY), experience(0) {}
        // Οταν ο ήρωας αποκτήσει αρκετή εμπειρία, ανεβαίνει ένα επίπεδο
        virtual void levelUp() = 0;
};
