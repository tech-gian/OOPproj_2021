#include "../../../include/Living/Monster/Dragon.h"

void Dragon::print(){
    cout << "\t -------------------------------" << endl;
    cout << "\t > Dragon Name       : " << this->name << endl;
    Monster::print();
}
