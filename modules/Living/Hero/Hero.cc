#include "Hero.h"
#include <iostream>

void Hero::displayStats(){
    cout << "Hero Name: " << this->name << endl;
    cout << "Magic Power: " << this->magicPower << endl;
    cout << "Strength: " << this->strength << endl;
    cout << "Dexterity: " << this->dexterity << endl;
    cout << "Agility: " << this->agility << endl;
    cout << "Money: " << this->money;
}

void Hero::equip(Armor* armor){
    if(this->armor)
        this->inventory.push_back(this->armor);
    this->armor = armor;
    this->inventory.remove(armor);
}

void Hero::equip(Weapon* weapon){
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

void Hero::attack(Monster* monster){
    int damage = this->strength + this->weapon_left ? this->weapon_left->get_dmg() : 0 + this->weapon_right ? this->weapon_right->get_dmg() : 0;
    monster->receiveDamage(damage);
}

void Hero::castSpell(Spell* spell, Monster* monster){
    spell->use(monster, this->dexterity);
    this->magicPower -= spell->getMagicPowerRequired();
    spells.remove(spell);
}

void Hero::use(Potion* potion){
    int percentage = potion->get_percent();
    string stat = potion->get_stat();

    if(stat == "health")
        this->healthPower += this->healthPower * percentage;
    else if(stat == "magic power")
        this->magicPower += this->magicPower * percentage;
    else if(stat == "strength")
        this->strength += this->strength * percentage;
    else if(stat == "dexterity")
        this->dexterity += this->dexterity * percentage;
    else if(stat == "agility")
        this->agility += this->agility * percentage;

    delete potion; // TODO: OR potion->set_used(); ??
}

list<Item*> Hero::checkInventory(){
    return this->inventory;
}

list<Spell*> Hero::get_spells(){
    return this->spells;
}

void Hero::add_item(Item* item){
    this->inventory.push_back(item);
}

void Hero::add_spell(Spell* spell){
    this->spells.push_back(spell);
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
}

int Hero::getMagicPower(){
    return this->magicPower;
}

void Hero::win(int num_of_monsters){
    // TODO: find appropriate constants
    this->money += this->level * k + num_of_monsters * l;
    this->experience += this->level * x + num_of_monsters * y;
    if(this->experience >= this->level * z)
        this->levelUp();
}

void Hero::regenerate(){
    this->healthPower *= 1.05;
    this->magicPower *= 1.05;
}
