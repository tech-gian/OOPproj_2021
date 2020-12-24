#include <string>

using namespace std;

class Spell{
    protected:
        string name;                // όνομα
        int price;                  // τιμή
        int min_level;              // ελάχιστο επίπεδο στο οποίο πρέπει να βρίσκεται ο ήρωας για να το χρησιμοποιήσει
        int min_damage;             // εύρος ζημιάς που μπορεί να προκαλέσει
        int max_damage; 
        int magic_power_required;   // ποσό μαγικής ενέργειας που απαιτεί για να εκτελεστεί
    public:
        Spell(string name, int price, int min_level, int min_damage, int max_damage, int magic_power_required) :
        name(name), price(price), min_level(min_level), min_damage(min_damage), max_damage(max_damage), magic_power_required(magic_power_required)
        
        virtual void use() = 0;
};
