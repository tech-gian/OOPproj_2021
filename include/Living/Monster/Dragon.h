#pragma once

#include <string>
using namespace std;

#include "../../constants.h"
#include "Monster.h"

class Dragon : public Monster {
    public:
        // Ευνοημένο στο εύρος ζημιάς που μπορεί να προκαλέσει
        Dragon(string name, int level) : Monster(name, MIN_DAMAGE + 20, MAX_DAMAGE + 20, INIT_DEFENSE, POSSIBILITY_OF_AVOIDANCE, level){}

        ~Dragon(){}
        
        void print();
};
