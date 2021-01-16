#pragma once

#include "../../constants.h"
#include "../Living.h"
#include "../../Item/Item.h"
#include "../../Spell/Spell.h"
#include "../../Item/Armor.h"
#include "../../Item/Weapon.h"
#include "../../Item/Potion.h"

#include <iostream>
#include <string>
#include <list>
using namespace std;

class Hero : public Living {
    protected:
        int magicPower;         // Ποσό μαγικής ενέργειας
        int strength;           // Τιμή δύναμης
        int dexterity;          // Τιμή επιδεξιότητας
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
        : Living(name, 1), magicPower(INIT_MAGIC_POWER), strength(strength), dexterity(dexterity), agility(agility), money(INIT_MONEY), experience(0), armor(NULL), weapon_left(NULL), weapon_right(NULL) {}
        
        virtual ~Hero(){}

        int getMagicPower(){ return this->magicPower; }

        int getStrenth(){ return this->strength; }

        int getDexterity(){ return this->dexterity; }

        int getAgility(){ return this->agility; }

        int getMoney(){ return this->money; }

        list<Spell*> getSpells(){ return this->spells; }

        Armor* getArmor(){ return this->armor; }

        Weapon* getWeapon(char hand){ return hand == 'l' ? this->weapon_left : this->weapon_right; }

        void setMagicPower(int magic_power){ this->magicPower = magic_power; }

        list<Item*> getInventory(){ return this->inventory; }
        
        void setWeapon(Weapon* weapon);

        void setArmor(Armor* armor);

        void usePotion(Potion* potion);

        // Οταν ο ήρωας αποκτήσει αρκετή εμπειρία, ανεβαίνει ένα επίπεδο
        virtual void levelUp() = 0;

        // Συναρτήσεις διαχείρησης Items/Spells του παίκτη

        void add_item(Item* item);

        void add_spell(Spell* spell);

        void sell_item(Item* item);

        void sell_spell(Spell* spell);

        // Αποδοχή ζημιάς από επίθεση τέρατος
        void receiveDamage(int damage);

        /* Αν μετά το πέρας μίας μάχης κάποιος ήρωας έχει απομείνει με ζωτική ενέργεια μηδέν,
            τότε αυτή επαναϕέρεται στο μισό της κανονικής του ζωτικής ενέργειας. */
        void half_life(void) { this->healthPower = INIT_HEALTH_POWER / 2; }

        /* Αν η μάχη τελειώσει επειδή νίκησαν οι ήρωες,
        τότε αυτοί λαμβάνουν κάποια χρήματα και ένα ποσό εμπειρίας βάσει του επιπέδου τους και του πλήθους των τεράτων που αντιμετώπισαν.*/
        void win(int num_of_monsters);

        // Αν η μάχη τελειώσει επειδή νίκησαν τα τέρατα, οι ήρωες χάνουν τα μισά χρήματα τους
        void lose(void) { this->money /= 2; }

        // Οι ήρωες αναγεννούν σε κάθε γύρο κάποιο ποσό της ζωτικής και της μαγικής τους ενέργειας
        void regenerate();

        virtual void print();
};
