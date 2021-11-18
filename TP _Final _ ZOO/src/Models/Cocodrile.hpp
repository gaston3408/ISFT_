#include "../AbstractModels/Oviparous.hpp"
#include <iostream>
using namespace std;

class Cocodrile : public Oviparous
{
public:
    Cocodrile(string name, int code)
        : Oviparous(name, code){};

    void swim()
    {
        cout << this->getName() << " está nadando" << endl;
    }

    void kill()
    {
        cout << this->getName() << " mató a otro animal" << endl;
    }

    ~Cocodrile();
};