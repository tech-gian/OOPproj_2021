#include "../../../include/Living/Hero/Hero.h"

void Hero::setWeapon(Weapon* weapon){
    if(!this->weapon_left || this->weapon_left->get_hands() == 2 || weapon->get_hands() == 2){
        if(this->weapon_left)
            this->inventory.push_back(this->weapon_left);
        if(this->weapon_right)
            this->inventory.push_back(this->weapon_right);
        this->weapon_left = weapon;
        this->weapon_right = NULL;
        this->inventory.remove(weapon);
    }else{
        if(this->weapon_right)
            this->inventory.push_back(this->weapon_right);
        this->weapon_right = weapon;
        this->inventory.remove(weapon);
    }
    cout << "Left ";
    this->weapon_left->print();
    if(this->weapon_right){
        cout << "Right ";
        this->weapon_right->print();
    }
}

void Hero::setArmor(Armor* armor){
    if(this->armor)
        this->inventory.push_back(this->armor);
    this->armor = armor;
    this->inventory.remove(armor);
    cout << this->name << " is equiped with armor: " << armor->get_name() << endl;
}

void Hero::usePotion(Potion* potion){
    int percentage = potion->get_percent();
    string stat = potion->get_stat();

    if(stat == "health")
        this->healthPower += this->healthPower * (percentage/100.0);
    else if(stat == "magic power")
        this->magicPower += this->magicPower * (percentage/100.0);
    else if(stat == "strength")
        this->strength += this->strength * (percentage/100.0);
    else if(stat == "dexterity")
        this->dexterity += this->dexterity * (percentage/100.0);
    else if(stat == "agility")
        this->agility += this->agility * (percentage/100.0);

    cout << this->name << "'s " << stat << " boosted by " << percentage << "%!" << endl;

    this->inventory.remove(potion);
}

void Hero::add_item(Item* item){
    this->inventory.push_back(item);
    this->money -= item->get_price();
}

void Hero::add_spell(Spell* spell){
    this->spells.push_back(spell);
    this->money -= spell->get_price();
}

void Hero::sell_item(Item* item){
    this->inventory.remove(item);
    this->money += item->get_price() / 2;
}

void Hero::sell_spell(Spell* spell){
    this->spells.remove(spell);
    this->money += spell->get_price() / 2;
}

void Hero::receiveDamage(int damage){
    if(this->armor){
        int protection = this->armor->get_protection();
        if(damage <= protection)
            this->armor->decreaseDamageProtection(damage);
        else{
            damage -= protection;
            this->armor = NULL;
            this->healthPower = this->healthPower > damage ? this->healthPower - damage : 0;
        }
    }else{
        this->healthPower = this->healthPower > damage ? this->healthPower - damage : 0;
    }

    if(this->armor == NULL && this->healthPower == 0)
        cout << this->name << " died." << endl;
}

void Hero::win(int num_of_monsters){
    this->money += this->level + num_of_monsters * 10;
    this->experience += this->level + num_of_monsters * 10;
    if(this->experience >= this->level * 15)
        this->levelUp();
}

void Hero::regenerate(){
    if (this->healthPower < 0.95 * INIT_HEALTH_POWER)
        this->healthPower *= 1.05;
    
    if (this->magicPower < 0.95 * INIT_MAGIC_POWER)
        this->magicPower *= 1.05;
}

void Hero::print(){
    cout << "\t > Hero Life       : " << this->get_life() << endl;
    cout << "\t > Magic Power     : " << this->getMagicPower() << endl;
    cout << "\t > Strength        : " << this->getStrenth() << endl;
    cout << "\t > Dexterity       : " << this->getDexterity() << endl;
    cout << "\t > Agility         : " << this->getAgility() << endl;
    cout << "\t > Money           : " << this->getMoney() << endl;
    cout << "\t > Level           : " << this->get_level() << endl;

    // Display his Weapon(s)
    Weapon* weapon;
    if ((weapon = this->getWeapon('l')) != NULL) {
        if (weapon->get_hands() == 1)
            cout << "Left weapon: " << endl;
        weapon->print();
    }

    if ((weapon = this->getWeapon('r')) != NULL) {
        cout << "Right weapon: " << endl;
        weapon->print();
    }

    // Display his Armor
    Armor* armor;
    if ((armor = this->getArmor()) != NULL)
        armor->print();

    // Display his Items
    list<Item*> items = this->getInventory();
    if (items.size() > 0) {
        cout << "Available Items:" << endl;

        list<Item*>::iterator it;
        for (it=items.begin() ; it!=items.end() ; ++it) {
            (*it)->print();
        }
    } else {
        cout << "This hero has no Items." << endl;
    }

    // Display his Spells
    list<Spell*> spells = this->getSpells();
    if (spells.size() > 0) {
        cout << "Available Spells:" << endl;
    
        list<Spell*>::iterator it;
        for (it=spells.begin() ; it!=spells.end() ; ++it) {
            (*it)->print();
        }
    } else {
        cout << "This hero has no Spells." << endl;
    }
}
