#include "../../../include/Living/Monster/Exoskeleton.h"

void Exoskeleton::print(){
    cout << "\t -------------------------------" << endl;
    cout << "\t > Exosceleton Name  : " << this->name << endl;
    Monster::print();
}
