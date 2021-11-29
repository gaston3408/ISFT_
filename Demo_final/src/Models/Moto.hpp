#include "Vehicle.hpp"
#include <iostream>
using namespace std;

class Moto: public Vehicle
{
private:
    string color;
    string marca;
    bool started;
public:
    Moto(string color, string marca){
        this->color = color;
        this->marca = marca;
        this->started = false;
    };
    void start(){
        this->started = true;
    };
    void stop(){
        this->started = false;
    };
    void rest(){
        this->started = false;

    };
    string getColor(){
        return this->color;
    };
    void setColor(string color){
        this->color = color;
    };
    string getMarca(){
        return this->marca;
    };
    void setMarca(string marca){
        this->marca = marca;
    };
    ~Moto();
};
