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
};
