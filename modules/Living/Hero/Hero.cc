#include "Hero.h"
#include <iostream>

#include <iterator>
using namespace std;

void Hero::displayStats(){
    cout << "Name: " << this->name << endl;
    cout << "Magic Power: " << this->magicPower << endl;
    cout << "Strength: " << this->strength << endl;
    cout << "Dexterity: " << this->dexterity << endl;
    cout << "Agility: " << this->agility << endl;
    cout << "Money: " << this->money;
}

void Hero::equip(Armor* armor){
    this->armor = armor;
    this->inventory.remove(armor);
}

void Hero::equip(Weapon* weapon){
    if(!this->weapon_left || this->weapon_left->get_hands() == 2){
        this->weapon_left = weapon;
        return;
    }
    this->weapon_right = weapon;
    this->inventory.remove(weapon);
}

Item** Hero::checkInventory(){
    Item** items = new Item*[this->inventory.size()];
    int i = 0;
    for(list<Item*>::iterator it = this->inventory.begin(); it != this->inventory.end(); ++it){
        items[i++] = *it;
    }
    return items;
}

int Hero::items_size(){
    return this->inventory.size();
}

Spell** Hero::get_spells(){
    Spell** spells = new Spell*[this->spells.size()];
    int i = 0;
    for(list<Spell*>::iterator it = this->spells.begin(); it != this->spells.end(); ++it){
        spells[i++] = *it;
    }
    return spells;
}

int Hero::spells_size(){
    return this->spells.size();
}

void Hero::add_item(Item* item){
    this->inventory.push_back(item);
}

void Hero::add_spell(Spell* spell){
    this->spells.push_back(spell);
}

void Hero::sell_item(Item* item){
    this->inventory.remove(item);
}

void Hero::sell_spell(Spell* spell){
    this->spells.remove(spell);
}
