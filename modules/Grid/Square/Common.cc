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
        // Get the next random line (monster_name)
        int temp_pos = rand() % (NAMES_SIZE / 3);
        for (int j=0 ; j<temp_pos ; ++j) getline(file, monster_name);
        // If temp_pos == 0, it takes the next name
        if (temp_pos == 0) getline(file, monster_name);
        std::replace(monster_name.begin(), monster_name.end(), '\r', '\0');
        std::replace(monster_name.begin(), monster_name.end(), '\n', '\0');
        monster_name.erase(std::remove(monster_name.begin(), monster_name.end(), '\0'), monster_name.end());

        // TODO: adjust monster's level
        if (i == 0) {
            monsters[i] = new Dragon(monster_name, 1);
        }
        else if (i == 1) {
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
    
    if (ans == 'y') displayStats();

    ans = 'z';

    // Show options to player
    while(ans != 'a' && ans != 'c' && ans != 'u'){
        cout << "Type 'a' to attack, 'c' to cast Spell or 'u' to use some Item: ";
        cin >> ans;
    }

    // Get the hero, that player wants to use
    cout << "Type the number of hero you want to make the action with: ";
    int hero_num;
    while (true) {
        cin >> hero_num;
        if (hero_num > 2 || hero_num < 0)
            cout << "The number of the hero should be 0, 1 or 2: ";
        else {
            if (heroes[hero_num]->get_life() == 0)
                cout << "This hero is dead. Pick another one: ";
            else
                break;
        }
    }

    // Depending on the answers, make the correct option
    if (ans == 'a') {
        // Get the number of monster to attack
        cout << "Type the number of monster you want to attack: ";
        int mon_num = 3;
        while(mon_num > 2 || monsters[mon_num]->get_life() == 0){
            cin >> mon_num;
            if(mon_num > 2){
                cout << "The number of the monster should be 0, 1 or 2: ";
            }else if(monsters[mon_num]->get_life() == 0)
                cout << monsters[mon_num]->getName() << " is dead. Choose another monster: ";
        }

        // Attack
        attack(heroes[hero_num], monsters[mon_num]);
    }
    else if (ans == 'c') {
        // Print the Spells of hero
        list<Spell*> spells = heroes[hero_num]->getSpells();
        list<Spell*>::iterator it;

        int i = 0;
        for (it=spells.begin() ; it!=spells.end() ; ++it, ++i) {
            cout << i << ") ";
            (*it)->print();
        }

        int spell = i + 1;
        while (spell >= i) {
            cout << "Type the number of Spell you want to use [0-" << i - 1 << "]: ";
            cin >> spell;
        }

        cout << "Type the number of monster you want to attack: ";
        int mon_num;
        cin >> mon_num;

        // To find the correct spell
        int temp = 0;
        for (it=spells.begin() ; it!=spells.end() ; ++it) {
            if (temp == spell) break;
            ++temp;
        }

        // Cast Spell
        castSpell(heroes[hero_num], monsters[mon_num], (*it));
    }
    else if (ans == 'u') {
        // Print the Items of hero
        list<Item*> items = heroes[hero_num]->getInventory();
        list<Item*>::iterator it;

        int i = 0;
        for (it=items.begin() ; it!=items.end() ; ++it, ++i) {
            cout << i << ") ";
            (*it)->print();
        }

        int item = i + 1;
        while(item >= i){
            cout << "Type the number of Item you want to use [0-" << i - 1 << "]: ";
            cin >> item;
        }
        

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

    // Monsters attack.
        bool life_monsters = true;

        for (int i=0 ; i<3 ; ++i) {
            if (monsters[i]->get_life() != 0) {
                life_monsters = false;
            }
        }
        if (life_monsters)
            return;

        
        int temp = rand() % 3;
        while(heroes[temp]->get_life() == 0)
            temp = rand() % 3;

        int temp2 = rand() % 3;
        while(monsters[temp2]->get_life() == 0)
            temp2 = rand() % 3;


        attack(monsters[temp2], heroes[temp]);
}


void Common::poss_fight(void) {
    // Possibility for a fight

    // int temp = rand() % 100;
    if (true) {                                            // TODO: CHANGE TO temp < possibility on production :P
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
        cout << "You crashed those monsters!" << endl;
        for (int i=0 ; i<3 ; ++i) {
            heroes[i]->win(monsters_dead);
        }
    }
    // If monsters win
    else if (life_heroes) {
        cout << "You lost :( Better luck next time!" << endl;
        for (int i=0 ; i<3 ; ++i) {
            heroes[i]->lose();
        }
    }

    // Delete previous monsters and create new
    for (int i=0 ; i<3 ; ++i) {
        delete monsters[i];
    }

    // Get random name from file
    ifstream file("../samples/names.txt");
    string monster_name;

    for (int i=0 ; i<3 ; ++i) {
        // Get the next random line (monster_name)
        int temp_pos = rand() % (NAMES_SIZE / 3);
        for (int j=0 ; j<temp_pos ; ++j) getline(file, monster_name);
        // If temp_pos == 0, it takes the next name
        if (temp_pos == 0) getline(file, monster_name);
        std::replace(monster_name.begin(), monster_name.end(), '\r', '\0');
        std::replace(monster_name.begin(), monster_name.end(), '\n', '\0');
        monster_name.erase(std::remove(monster_name.begin(), monster_name.end(), '\0'), monster_name.end());

        // TODO: adjust monster's level
        if (i == 0) {
            monsters[i] = new Dragon(monster_name, 1);
        }
        else if (i == 1) {
            monsters[i] = new Exoskeleton(monster_name, 1);
        }
        else {
            monsters[i] = new Spirit(monster_name, 1);
        }
    }

    file.close();
}


void Common::displayStats(void) {
    cout << "> Below are shown heroes stats:" << endl;
    for (int i=0 ; i<3 ; ++i) Square::displayStats(heroes[i]);

    cout << "> Below are shown monsters stats:" << endl;
    for (int i=0 ; i<3 ; ++i) displayStats(monsters[i]);
}

void Common::displayStats(Monster* monster){
    cout << "\t -------------------------------" << endl;
    cout << "\t > Monster Name : " << monster->getName() << endl;
    cout << "\t > Defense      : " << monster->getDefense() << endl;
    cout << "\t > Monster Life : " << monster->get_life() << endl;
    cout << "\t > Damage       : [" << monster->getMinDamage() << " - " << monster->getMaxDamage() << "]" << endl;
}

void Common::attack(Hero* hero, Monster* monster){
    cout << hero->getName() << " attacks " << monster->getName() << "!" << endl;
    
    if((rand() % 100) + 1 > monster->getPossibilityOfAvoidance()){
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
    }else{
        cout << monster->getName() << " is too fast and avoided " << hero->getName() << "'s attack!" << endl;
    }
}

void Common::attack(Monster* monster, Hero* hero){
    cout << monster->getName() << " attacks " << hero->getName() << "!" << endl;

    if ((rand() % 100) + 1 > hero->getAgility()) {
        hero->receiveDamage(monster->getMinDamage() + rand() % (monster->getMaxDamage() - monster->getMinDamage()));
    }else{
        cout << hero->getName() << " is too fast and avoided " << monster->getName() << "'s attack!" << endl;
    }
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
