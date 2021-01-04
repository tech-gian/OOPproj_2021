#include "../../../include/Living/Hero/Hero.h"


int Hero::getMagicPower(){
    return this->magicPower;
}

int Hero::getStrenth(){
    return this->strength;
}

int Hero::getDexterity(){
    return this->dexterity;
}

int Hero::getAgility(){
    return this->agility;
}

int Hero::getMoney(){
    return this->money;
}

list<Spell*> Hero::getSpells(){
    return this->spells;
}

Armor* Hero::getArmor(){
    return this->armor;
}

Weapon* Hero::getWeapon(char hand){
    return hand == 'l' ? this->weapon_left : this->weapon_right;
}

void Hero::setWeapon(Weapon* weapon){
    if(!this->weapon_left || this->weapon_left->get_hands() == 2 || weapon->get_hands() == 2){
        if(this->weapon_left)
            this->inventory.push_back(this->weapon_left);
        this->weapon_left = weapon;
        this->weapon_right = NULL;
    }else{
        if(this->weapon_right)
            this->inventory.push_back(this->weapon_right);
        this->weapon_right = weapon;
        this->inventory.remove(weapon);
    }
}

void Hero::setArmor(Armor* armor){
    if(this->armor)
        this->inventory.push_back(this->armor);
    this->armor = armor;
    this->inventory.remove(armor);
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

    this->inventory.remove(potion); // TODO: OR potion->set_used(); OR delete potion ??
}

void Hero::setMagicPower(int magic_power){
    this->magicPower = magic_power;
}

list<Item*> Hero::getInventory(){
    return this->inventory;
}

void Hero::add_item(Item* item){
    this->inventory.push_back(item);
    money -= item->get_price();
}

void Hero::add_spell(Spell* spell){
    this->spells.push_back(spell);
    money -= spell->get_price();
}

void Hero::sell_item(Item* item){
    this->inventory.remove(item);
    money += item->get_price() / 2;
}

void Hero::sell_spell(Spell* spell){
    this->spells.remove(spell);
    money += spell->get_price() / 2;
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
    // TODO: find appropriate constants
    this->money += this->level * 1 + num_of_monsters * 10;
    this->experience += this->level * 1 + num_of_monsters * 10;
    if(this->experience >= this->level * 1)
        this->levelUp();
}

void Hero::regenerate(){
    if (this->healthPower < 0.95 * INIT_HEALTH_POWER)
        this->healthPower *= 1.05;
    
    if (this->magicPower < 0.95 * INIT_MAGIC_POWER)
        this->magicPower *= 1.05;
}
