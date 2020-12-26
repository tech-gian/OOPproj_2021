#include "../constants.h"
#include <string>

using namespace std;

class Living {
    protected:
        string name;        // όνομα
        int level;          // επίπεδο
        int healthPower;    // ποσό ζωτικής ενέργειας
    public:
        Living(string name) : name(name), level(1), healthPower(INIT_HEALTH_POWER){}
        // Σε κάθε γύρο, ο παίκτης μπορεί να εμϕανίσει τα στατιστικά κάθε ήρωα και τέρατος
        virtual void displayStats() = 0;

        // Αποδοχή ζημιάς που προκλήθηκε από τον αντίπαλο
        virtual void receiveDamage(int damage) = 0;
};
