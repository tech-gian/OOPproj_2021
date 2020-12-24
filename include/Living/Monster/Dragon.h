#include "../../constants.h"
#include "Monster.h"

class Dragon : public Monster {
    public:
        // ευνοημένο στο εύρος ζημιάς που μπορεί να προκαλέσει
        Dragon(string name) : Monster(name, MIN_DAMAGE + 20, MAX_DAMAGE + 20, INIT_DEFENSE, POSSIBILITY_OF_AVOIDANCE){}
};
