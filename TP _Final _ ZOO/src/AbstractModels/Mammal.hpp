#ifndef MAMMAL_H
#define MAMMAL_H
#include "Animal.hpp"

class Mammal : public Animal
{
private:
    string name;
    int code;
    int yearsOld;

public:
    Mammal(string name, int code)
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
        cout << this->getName() << " se esta moviendo" << endl;
    }

    void eat()
    {
        cout << this->getName() << " está comiendo" << endl;
    }

    void setYearsOld(int value)
    {
        this->yearsOld = value;
    }

    void nurse()
    {
        cout << this->name << " amamantó." << endl;
    }

};

#endif