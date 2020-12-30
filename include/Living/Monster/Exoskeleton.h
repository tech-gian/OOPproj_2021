#pragma once

#include <string>
using namespace std;

#include "../../constants.h"
#include "Monster.h"

class Exoskeleton : public Monster {
    public:
        // Ευνοημένο στο ποσό άμυνας που διαθέτει
        Exoskeleton(string name, int level) : Monster(name, MIN_DAMAGE, MAX_DAMAGE, INIT_DEFENSE + 50, POSSIBILITY_OF_AVOIDANCE, level){}

        ~Exoskeleton(){}
};
