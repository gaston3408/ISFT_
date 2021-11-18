#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
using namespace std;

class Animal
{
private:
    string name;
    int code;

public:
    virtual string getName() = 0;
    virtual int getCode() = 0;
    virtual void move() = 0;
    virtual void eat() = 0;
    ~Animal() {};
};

#endif
