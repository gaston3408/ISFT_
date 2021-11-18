#include "../AbstractModels/Mammal.hpp"
#include <iostream>
using namespace std;

class SeaLion : public Mammal
{
public:
    SeaLion(string name, int code)
        : Mammal(name, code){};

    void swim()
    {
        cout << this->getName() << " está nadando" << endl;
    }

    void clap()
    {
        cout << this->getName() << " está aplaudiendo" << endl;
    }

    ~SeaLion();
};