#include "../AbstractModels/Oviparous.hpp"
#include <iostream>
using namespace std;

class Pelican : public Oviparous
{
public:
    Pelican(string name, int code)
        : Oviparous(name, code){};

    void isAtWater()
    {
        cout << this->getName() << " está sobre el agua" << endl;
    }

    void fly()
    {
        cout << this->getName() << " está volando" << endl;
    }

    ~Pelican();
};