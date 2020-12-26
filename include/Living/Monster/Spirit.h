#include "../../constants.h"
#include "Monster.h"

class Spirit : public Monster {
    public:
        // ευνοημένο στο πόσο συχνά αποϕεύγει επιθέσεις
        Spirit() : Monster(name, MIN_DAMAGE, MAX_DAMAGE, INIT_DEFENSE, POSSIBILITY_OF_AVOIDANCE + 0.2){}
};
