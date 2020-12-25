//////////////////////////////////
// Implementation of Grid, Square,
// nonAccesible, Market and Common
//////////////////////////////////



#pragma once

#include "Main_include.h"


// Grid Functions

Grid::~Grid() {
    for (int i=0 ; i<x ; ++i) {
        for (int j=0 ; j<y ; ++j) {
            delete squares[i][j];
        }
        delete squares[i];
    }
    delete squares;
}


void Grid::move(void) {
    int i = posi;
    int j = posj;
    bool flag;

    // Loop to make a move
    do {
        flag = false;

        cout << "Type 'u' for up, 'd' for down, 'r' for right and 'l' for left: ";
        char p;
        cin >> p;
        cout << endl;

        if (p == 'u' || p == 'd' || p == 'r' || p == 'l') {
            if (p == 'u') --i;
            else if (p == 'd') ++i;
            else if (p == 'r') ++j;
            else if (p == 'l') --j;

            if (i < 0 || i >= x || j < 0 || j >= y) {
                cout << "Out of bounds. Type again." << endl;
                flag = true;
            }
            else if (squares[i][j]->get_sq() == 'n') {
                cout << "Non Accesible square. Type again." << endl;
                flag = true;
            }
        }
        else {
            flag = true;
            cout << "Wrong input. Type again." << endl;
        }

    } while (flag);

    // After everything is ok,
    // do whatever each square does
    posi = i;
    posj = j;

    if (squares[posi][posj]->get_sq() == 'm') {
        cout << "You are on a Market square. Type 'b' to buy, 's' to sell or 'n' for nothing: ";
        char answer;
        cin >> answer;
        cout << endl;

        if (answer == 'b') {
            squares[posi][posj]->buy();
        }
        else if (answer == 's') {
            squares[posi][posj]->sell();
        }
        else {
            cout << "You choose to do nothing." << endl;
        }
    }
    else if (squares[posi][posj]->get_sq() == 'c') {
        // TODO
    }


}


void Grid::displayMap() {

}


void Grid::quitGame() {

}




// Market Functions

Market::Market() {
    srand(time(NULL));

    for (int i=0 ; i<SIZE_ITEMS ; ++i) {
        int temp = rand() % 3;

        // TODO: take names from file and pick with rand()
        if (temp == 0) {
            items[i] = new Weapon("TODO", (rand()%2)+1);
        }
        else if (temp == 1) {
            items[i] = new Armor("TODO");
        }
        else {
            // TODO: declare which stat and make rand() for it
            items[i] = new Potion("TODO", "TODO");
        }
    }

    for (int i=0 ; i<SIZE_SPELLS ; ++i) {
        int temp = rand() % 3;

        // TODO: take names from file and pick with rand()
        if (temp == 0) {
            spells[i] = new FireSpell("TODO");
        }
        else if (temp == 1) {
            spells[i] = new IceSpell("TODO");
        }
        else {
            spells[i] = new LightningSpell("TODO");
        }
    }

}

Market::~Market() {
    for (int i=0 ; i<SIZE_ITEMS ; ++i) {
        delete items[i];
    }

    for (int i=0 ; i<SIZE_SPELLS ; ++i) {
        delete spells[i];
    }
}


void Market::buy() {

}


void Market::sell() {

}


void Market::displayAvailable() {
    // Display every Item and Spell available
    cout << "Depending on your money, you can buy:" << endl;
    cout << "Available Items:" << endl;

    for (int i=0 ; i<SIZE_ITEMS ; ++i) {
        items[i]->print();
    }

    cout << "Available Spells" << endl;

    for (int i=0 ; i<SIZE_SPELLS ; ++i) {
        spells[i]->print();
    }
}




// Common Functions

void Common::fight() {

}


void Common::displayStats() {
    
}



