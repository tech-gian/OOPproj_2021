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
        int magicPower;         // Ποσό μαγικής ενέργειας
        int strength;           // Τιμή δύναμης
        int dexterity;          // TODO: Τιμή επιδεξιότητας
        int agility;            // Τιμή ευκινησίας
        int money;              // Ποσό χρημάτων
        int experience;         // Ποσό εμπειρίας

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
        void attack(Monster* monster);
        void castSpell(Spell* spell, Monster* monster);
        void use(Potion* potion);
        list<Item*> checkInventory();

        list<Spell*> get_spells(void);

        void add_item(Item* item);

        void add_spell(Spell* spell);

        void sell_item(Item* item);

        void sell_spell(Spell* spell);

        // Αποδοχή ζημιάς από επίθεση τέρατος
        void receiveDamage(int damage);

        int getMagicPower();

        void half_life(void) { this->healthPower = INIT_HEALTH_POWER / 2; }

        /* Αν η μάχη τελειώσει επειδή νίκησαν οι ήρωες,
        τότε αυτοί λαμβάνουν κάποια χρήματα και ένα ποσό εμπειρίας βάσει του επιπέδου τους και του πλήθους των τεράτων που αντιμετώπισαν.*/
        void win(int num_of_monsters);

        // Αν η μάχη τελειώσει επειδή νίκησαν τα τέρατα, οι ήρωες χάνουν τα μισά χρήματα τους
        void lose(void) { this->money /= 2; }

        // Οι ήρωες αναγεννούν σε κάθε γύρο κάποιο ποσό της ζωτικής και της μαγικής τους ενέργειας
        void regenerate();
};
