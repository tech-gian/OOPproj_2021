///////////////////////////
// Implementation of Common
///////////////////////////


#include "../../../include/Grid/Common.h"
#include <algorithm>


// Common Functions

Common::Common() : Square(NULL) {
    // Initialize heroes
    for (int i=0 ; i<3 ; ++i) {
        heroes[i] = NULL;
    }

    this->possibility = POSSIBILITY_OF_FIGHT;

    // Get random name from file
    ifstream file("../samples/names.txt");
    string monster_name;

    for (int i=0 ; i<3 ; ++i) {
        int temp = rand() % 3;

        // Get the next random line (monster_name)
        int temp_pos = rand() % (NAMES_SIZE / 3);
        for (int j=0 ; j<temp_pos ; ++j) getline(file, monster_name);
        // If temp_pos == 0, it takes the next name
        if (temp_pos == 0) getline(file, monster_name);
        std::replace(monster_name.begin(), monster_name.end(), '\r', '\0');
        std::replace(monster_name.begin(), monster_name.end(), '\n', '\0');
        monster_name.erase(std::remove(monster_name.begin(), monster_name.end(), '\0'), monster_name.end());

        if (temp == 0) {
            monsters[i] = new Dragon(monster_name, 1);
        }
        else if (temp == 1) {
            monsters[i] = new Exoskeleton(monster_name, 1);
        }
        else {
            monsters[i] = new Spirit(monster_name, 1);
        }
    }

    file.close();
}

Common::~Common() {
    for (int i=0 ; i<3 ; ++i) {
        delete monsters[i];
    }
}


void Common::round(void) {
    // Display Stats or not
    cout << "Type 'y' if you want to display Stats of heroes and monsters or 'n' if you don't want: ";
    char ans;
    cin >> ans;
    cout << endl;
    if (ans == 'y') displayStats();

    // Show options to player
    cout << "Type 'a' to attack, 'c' to cast Spell or 'u' to use some Item: ";
    cin >> ans;
    cout << endl;

    // Depending on the answers, make the correct option
    if (ans == 'a') {
        cout << "Type the number of hero you want to attack with: ";
        int hero_num;
        cin >> hero_num;
        cout << endl;

        cout << "Type the number of monster you want to attack: ";
        int mon_num;
        cin >> mon_num;
        cout << endl;

        // Attack
        attack(heroes[hero_num], monsters[mon_num]);
    }
    else if (ans == 'c') {
        cout << "Type the number of hero you want to attack with: ";
        int hero_num;
        cin >> hero_num;
        cout << endl;

        cout << "Type the number of monster you want to attack: ";
        int mon_num;
        cin >> mon_num;
        cout << endl;

        cout << "Type the number of Spell you want to use: ";
        int spell;
        cin >> spell;
        cout << endl;

        // To find the correct spell
        list<Spell*> spells = heroes[hero_num]->getSpells();
        list<Spell*>::iterator it;
        int temp = 0;
        for (it=spells.begin() ; it!=spells.end() ; ++it) {
            if (temp == spell) break;
            ++temp;
        }

        // Cast Spell
        castSpell(heroes[hero_num], monsters[mon_num], (*it));
    }
    else if (ans == 'u') {
        cout << "Type the number of hero you want to use it: ";
        int hero_num;
        cin >> hero_num;
        cout << endl;
        list<Item*> items = heroes[hero_num]->getInventory();
        list<Item*>::iterator it;

        for (it=items.begin() ; it!=items.end() ; ++it) {
            (*it)->print();
        }   

        cout << "Type the number of item you want to use: ";
        int item;
        cin >> item;
        cout << endl;

        // To find the correct item
        int temp = 0;
        for (it=items.begin() ; it!=items.end() ; ++it) {
            if (temp == item) break;
            ++temp;
        }

        // We "use" the correct Item from Inventory
        if ((*it)->get_type() == 'a') {
            equip(heroes[hero_num], (Armor*) (*it));
        }
        else if ((*it)->get_type() == 'w') {
            equip(heroes[hero_num], (Weapon*) (*it));

        }
        else if ((*it)->get_type() == 'p') {
            use(heroes[hero_num], (Potion*) (*it));
        }
    }

    // Monsters attack
        int temp = rand() % 3;
        int temp2 = rand() % 3;

        // Attack based on hero->agility
        if (rand() % 100 < heroes[temp]->getAgility()) {
            attack(monsters[temp2], heroes[temp]);
        }
        else {
            cout << "Hero is too fast and avoided monster's attack" << endl;
        }
}


void Common::poss_fight(void) {
    // Possibility for a fight

    int temp = rand() % 100;
    if (temp < possibility) {
        cout << "You got into a fight!" << endl;
        fight();
    }
    else {
        cout << "You are in a Common square" << endl;
    }
}


void Common::fight() {
    bool life_heroes, life_monsters;
    int monsters_dead = 3;

    // Loop for a battle
    // Each loop is a round of fight
    while (true) {
        life_heroes = true;
        life_monsters = true;

        for (int i=0 ; i<3 ; ++i) {
            if (heroes[i]->get_life() != 0) {
                life_heroes = false;
            }
            if (monsters[i]->get_life() != 0) {
                --monsters_dead;
                life_monsters = false;
            }
        }

        // Main condition
        if (life_heroes || life_monsters) {
            break;
        }

        round();

        for (int i=0 ; i<3 ; ++i) {
            // Check is placed in functions
            // (If life == 0, then there is no problem)
            heroes[i]->regenerate();
            monsters[i]->regenerate();
        }
    }

    // If some hero has life == 0, get it to half of original
    for (int i=0 ; i<3 ; ++i) {
        if (heroes[i]->get_life() == 0) {
            heroes[i]->half_life();
        }
    }

    // If heroes win
    if (life_monsters) {
        for (int i=0 ; i<3 ; ++i) {
            heroes[i]->win(monsters_dead);
        }
    }
    // If monsters win
    else if (life_heroes) {
        for (int i=0 ; i<3 ; ++i) {
            heroes[i]->lose();
        }
    }

}


void Common::displayStats(void) {
    cout << "Below are shown heroes stats:" << endl;
    for (int i=0 ; i<3 ; ++i) Square::displayStats(heroes[i]);

    cout << "Below are shown monsters stats:" << endl;
    for (int i=0 ; i<3 ; ++i) displayStats(monsters[i]);
}

void Common::displayStats(Monster* monster){
    cout << "Monster Life: " << monster->get_life() << endl;
    cout << "Monster Name: " << monster->getName() << endl;
    cout << "Damage: [" << monster->getMinDamage() << " - " << monster->getMaxDamage() << "]" << endl;
    cout << "Defense: " << monster->getDefense() << endl;
}

void Common::attack(Hero* hero, Monster* monster){
    int left_damage = 0;
    int right_damage = 0;
    if(hero->getWeapon('l') != NULL){
        left_damage = hero->getWeapon('l')->get_dmg();
    }
    if(hero->getWeapon('r') != NULL){
        right_damage = hero->getWeapon('r')->get_dmg();
    }
    int damage = hero->getStrenth() + left_damage + right_damage;
    monster->receiveDamage(damage);
}

void Common::attack(Monster* monster, Hero* hero){
    hero->receiveDamage(monster->getMinDamage() + rand() % (monster->getMaxDamage() - monster->getMinDamage()));
}

void Common::equip(Hero* hero, Weapon* weapon){
    hero->setWeapon(weapon);
}

void Common::equip(Hero* hero, Armor* armor){
    hero->setArmor(armor);
}

void Common::use(Hero* hero, Potion* spell){
    hero->usePotion(spell);
}

void Common::castSpell(Hero* hero, Monster* monster, Spell* spell){
    spell->use(monster, hero->getDexterity());
    hero->setMagicPower(hero->getMagicPower() - spell->getMagicPowerRequired());
    hero->getSpells().remove(spell);
}
