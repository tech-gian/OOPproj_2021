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

        // TODO (needed in Grid.cc/line 293)
        void print(void);

        // TODO (needed in Grid.cc/line 295)
        Item** get_items(void);

        // TODO (needed in Grid.cc/line 296)
        int items_size(void);

        // TODO (needed in Grid.cc/line 306)
        Spell** get_spells(void);

        // TODO (needed in Grid.cc/line 307)
        int spells_size(void);

        // TODO (needed in Grid.cc/line 207)
        void add_item(Item* item);

        // TODO (needed in Grid.cc/line 224)
        void add_spell(Spell* spell);

        // TODO (needed in Grid.cc/line 252)
        void sell_item(Item* item);

        // TODO (needed in Grid.cc/line 266)
        void sell_spell(Spell* spell);
};
