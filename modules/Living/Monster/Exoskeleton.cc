#include "../../../include/Living/Monster/Exoskeleton.h"

void Exoskeleton::print() const{
    cout << "\t -------------------------------" << endl;
    cout << "\t > Exosceleton Name  : " << this->name << endl;
    Monster::print();
}
