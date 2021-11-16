#include "Status.hpp"
const int maxIntensity = 100;
const int MAX_ON_OFF = 50;

class Lamp
{
    private:
        Status status;
        int uses;
        int intensity;  
        void controleUses(int uses);
    public:
        Lamp();
        ~Lamp();
        void turnOn();
        void turnOff();
        void intensify();
        void attenuate();
        Status getStatus();
        int getUses();
        int getIntensity();
};

Lamp::Lamp()
{
    this->status = OFF;
    this->intensity = 0;
    this->uses = 0;
}

Lamp::~Lamp()
{

}

void Lamp::controleUses(int uses){
    if(uses >= MAX_ON_OFF){
        this->status = BREAK;
        this->intensity = 0;
    }
}

void Lamp::turnOn() 
{
    this->status = ON;
    this->intensity = 1;
    this->uses++;
    Lamp::controleUses(uses);
}

void Lamp::turnOff() 
{
    this->status = OFF;
    this->intensity = 0;
    this->uses++;
    Lamp::controleUses(uses);
}

void Lamp::intensify() 
{
    if(this->status == ON and (this->intensity <  maxIntensity))
    {
        this->intensity++;
    }
}

void Lamp::attenuate() 
{
    if(this->status == ON and this->intensity > 0)
    {
        this->intensity--;
        if(this->intensity == 0)
        {
            this->status = OFF;
        }
    }
}

Status Lamp::getStatus() 
{
    return this->status;
}

int Lamp::getIntensity() 
{
    return this->intensity;    
}

int Lamp::getUses()
{
    return this->uses;
}