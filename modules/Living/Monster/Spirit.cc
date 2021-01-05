#include "../../../include/Living/Monster/Spirit.h"

void Spirit::print(){
    cout << "\t -------------------------------" << endl;
    cout << "\t > Spirit Name       : " << this->name << endl;
    Monster::print();
}
