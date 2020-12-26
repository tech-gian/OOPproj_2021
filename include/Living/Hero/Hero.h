#include "../../constants.h"
#include "../Living.h"
#include "../Item/Armor.h"
#include "../Item/Weapon.h"
#include "../Item/Potion.h"
#include "../Spell/Spell.h"

class Hero : public Living {
    protected:
        int magicPower;         // ποσό μαγικής ενέργειας
        int strength;           // τιμή δύναμης
        int dexterity;          // τιμή επιδεξιότητας
        int agility;            // τιμή ευκινησίας
        int money;              // ποσό χρημάτων
        int experience;         // ποσό εμπειρίας

        Armor* armor;
        Weapon* weapon_left;
        Weapon* weapon_right;

    public:
        Hero(string name, int strength, int dexterity, int agility)
        : Living(name), magicPower(INIT_MAGIC_POWER), strength(strength), dexterity(dexterity), agility(agility), money(INIT_MONEY), experience(0) {}
        // Οταν ο ήρωας αποκτήσει αρκετή εμπειρία, ανεβαίνει ένα επίπεδο
        virtual void levelUp() = 0;
        void displayStats();
        void equip(Armor* armor);
        void equip(Weapon* weapon);
        void attack();
        void castSpell(Spell* spell);
        void use(Potion* potion);
        void checkInventory();
};
