#pragma once

#include "../../constants.h"
#include "Monster.h"

#include <string>
using namespace std;

class Exoskeleton : public Monster {
    public:
        // Ευνοημένο στο ποσό άμυνας που διαθέτει
        Exoskeleton(string name, int level) : Monster(name, MIN_DAMAGE, MAX_DAMAGE, INIT_DEFENSE + 20, POSSIBILITY_OF_AVOIDANCE, level){}

        ~Exoskeleton(){}

        void print() const;
};
