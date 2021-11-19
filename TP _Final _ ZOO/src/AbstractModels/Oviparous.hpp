#ifndef OVIPAROUS_H
#define OVIPAROUS_H
#include "Animal.hpp"

class Oviparous : public Animal
{
private:
    string name;
    int code;
    int yearsOld;

public:
    Oviparous(string name, int code)
    {
        this->name = name;
        this->code = code;
        this->yearsOld = 0;
    }

    string getName()
    {
        return this->name;
    }

    int getCode()
    {
        return this->code;
    }

    int getYearsOld()
    {
        return this->yearsOld;
    }

    void move()
    {
        cout << "El oviparo " << this->getName() << " se esta moviendo" << endl;
    }

    void eat()
    {
        cout << "El oviparo " << this->getName() << " está comiendo" << endl;
    }

    void setYearsOld(int value)
    {
        this->yearsOld = value;
    }

    void layEggs()
    {
        cout << this->name << " puso huevo." << endl;
    }

};

#endif