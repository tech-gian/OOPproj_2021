#include "../../constants.h"
#include "../Living.h"
#include "../Item/Armor.h"
#include "../Item/Weapon.h"
#include "../Item/Potion.h"
#include "../Spell/Spell.h"

#include <list>
using namespace std;

class Hero : public Living {
    protected:
        int magicPower;         // ποσό μαγικής ενέργειας
        int strength;           // τιμή δύναμης
        int dexterity;          // τιμή επιδεξιότητας
        int agility;            // τιμή ευκινησίας
        int money;              // ποσό χρημάτων
        int experience;         // ποσό εμπειρίας

        list<Item*> inventory;  // Ασπίδες, Φίλτρα, Όπλα
        list<Spell*> spells;    // Ξόρκια
        Armor* armor;           // Ασπίδα που χρησιμοποιεί ο παίκτης
        Weapon* weapon_left;    // Όπλο στο αριστερό χέρι
        Weapon* weapon_right;   // Όπλο στο δεξί χέρι

    public:
        Hero(string name, int strength, int dexterity, int agility)
        : Living(name), magicPower(INIT_MAGIC_POWER), strength(strength), dexterity(dexterity), agility(agility), money(INIT_MONEY), experience(0) {}
        // Οταν ο ήρωας αποκτήσει αρκετή εμπειρία, ανεβαίνει ένα επίπεδο
        virtual void levelUp() = 0;
        void displayStats();
        void equip(Armor* armor);
        void equip(Weapon* weapon);
        void attack(Monster* monster);  // TODO
        void castSpell(Monster* monster, int spell);    // TODO: grid doesn't have Spell* spells of heroes
        void use(Potion* potion);
        Item** checkInventory();

        // No need for this if we use <list>
        int items_size(void);

        // TODO: Spell** needs delete after usage
        Spell** get_spells(void);

        // No need for this if we use <list>
        int spells_size(void);

        void add_item(Item* item);

        void add_spell(Spell* spell);

        // TODO: make money
        void sell_item(Item* item);

        // TODO: make money
        void sell_spell(Spell* spell);
};
