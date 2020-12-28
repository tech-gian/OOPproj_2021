///////////////////////////////////////
// Implementation of main_game function
///////////////////////////////////////


#pragma once

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "../include/Living/Hero/Hero.h"
#include "../include/Living/Hero/Paladin.h"
#include "../include/Living/Hero/Sorcerer.h"
#include "../include/Living/Hero/Warrior.h"
#include "../include/Grid/Grid.h"

int main(void) {

    // Initialize rand
    srand(time(NULL));

    // Create random 3 heroes
    Hero* heroes[3];
    for (int i=0 ; i<3 ; ++i) {
        int temp = rand() % 3;

        // Taking random name from names.txt
        ifstream file("../samples/names.txt");
        string name;
        temp = rand() % NAMES_SIZE;
        for (int j=0 ; j<temp ; ++j) getline(file, name);
        file.close();

        if (temp == 0) {
            heroes[i] = new Paladin(name);
        }
        else if (temp = 1) {
            heroes[i] = new Sorcerer(name);
        }
        else {
            heroes[i] = new Warrior(name);
        }
    }


    // Create Grid
    Grid* grid = new Grid(heroes, 5, 5);


    cout << "Welcome to Main_game. Your heroes are placed in square (0, 0). Enjoy!" << endl;
    

    // TODO: "Menu" for player's options


    return 0;
}

