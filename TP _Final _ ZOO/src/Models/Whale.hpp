#include "../AbstractModels/Mammal.hpp"
#include <iostream>
using namespace std;

class Whale : public Mammal
{
public:
    Whale(string name, int code)
        : Mammal(name, code){};

    void swim()
    {
        cout << this->getName() << " está nadando" << endl;
    }

    void Jump()
    {
        cout << this->getName() << " salta sobre el mar" << endl;
    }

    ~Whale();
};