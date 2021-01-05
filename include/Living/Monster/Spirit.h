#pragma once

#include <string>
using namespace std;

#include "../../constants.h"
#include "Monster.h"

class Spirit : public Monster {
    public:
        // Ευνοημένο στο πόσο συχνά αποϕεύγει επιθέσεις
        Spirit(string name, int level) : Monster(name, MIN_DAMAGE, MAX_DAMAGE, INIT_DEFENSE, POSSIBILITY_OF_AVOIDANCE + 20, level){}

        ~Spirit(){}

        void print();
};
