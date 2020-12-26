///////////////////////////
// Implementation of Common
///////////////////////////



#pragma once

#include "Main_include.h"




// Common Functions

Common::Common() {
    this->possibility = POSSIBILITY_OF_FIGHT;

    srand(time(NULL));
    // Get random name from file
    ifstream file("../../../samples/names.txt");
    string monster_name;

    for (int i=0 ; i<3 ; ++i) {
        int temp = rand() % 3;

        // Get the next random line (monster_name)
        int temp_pos = rand() % (NAMES_SIZE / 3);
        for (int j=0 ; j<temp_pos ; ++j) getline(file, monster_name);

        if (temp == 0) {
            monsters[i] = new Dragon(monster_name);
        }
        else if (temp == 1) {
            monsters[i] = new Exoskeleton(monster_name);
        }
        else {
            monsters[i] = new Spirit(monster_name);
        }
    }

    file.close();
}

Common::~Common() {
    for (int i=0 ; i<3 ; ++i) {
        delete monsters[i];
    }
}


void Common::fight() {

}


void Common::displayStats() {
    
}

