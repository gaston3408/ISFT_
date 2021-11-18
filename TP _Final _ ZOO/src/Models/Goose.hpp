#include "../AbstractModels/Oviparous.hpp"
#include <iostream>
using namespace std;

class Goose : public Oviparous
{
public:
    Goose(string name, int code)
        : Oviparous(name, code){};

    void fly()
    {
        cout << this->getName() << " está volando" << endl;
    }

    void doSounds()
    {
        cout << this->getName() << " está haciendo sonidos" << endl;
    }

    ~Goose();
};