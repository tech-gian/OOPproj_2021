/////////////////////////
// Implementation of Grid
/////////////////////////



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
    // TODO: Move heroes when "move"

    if (squares[posi][posj]->get_sq() == 'm') {
        squares[posi][posj]->displayMenu();
    }
    else if (squares[posi][posj]->get_sq() == 'c') {
        squares[posi][posj]->poss_fight();
    }


}


void Grid::displayMap() {

}


void Grid::quitGame() {

}
