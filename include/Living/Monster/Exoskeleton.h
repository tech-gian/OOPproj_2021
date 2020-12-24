#include "../../constants.h"
#include "Monster.h"

class Exoskeleton : public Monster {
    public:
        // ευνοημένο στο ποσό άμυνας που διαθέτει
        Exoskeleton(string name) : Monster(name, MIN_DAMAGE, MAX_DAMAGE, INIT_DEFENSE + 50, POSSIBILITY_OF_AVOIDANCE){}
};