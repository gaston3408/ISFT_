#include "../AbstractModels/Mammal.hpp"
#include <iostream>
using namespace std;

class Bat : public Mammal
{
public:
    Bat(string name, int code)
        : Mammal(name, code){};

    void hang()
    {
        cout << this->getName() << " está colgado" << endl;
    }

    void fly()
    {
        cout << this->getName() << " está volando" << endl;
    }

    ~Bat();
};