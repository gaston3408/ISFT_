#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
using namespace std;

class Vehicle
{
private:
    string color;
    string marca;
    bool started;
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void rest() = 0;
    virtual string getColor() = 0;
    virtual void setColor(string color) = 0;
    virtual string getMarca() = 0;
    virtual void setMarca(string color) = 0;
};

#endif