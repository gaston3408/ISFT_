#include <iostream>
#include "entities/Lamp.hpp"

using namespace std;

string showStatus(Status status);

int main()
{
    Lamp* osram = new Lamp;
    cout << "El estado inicial es: " << showStatus(osram->getStatus()) << endl;
    cout << "La intensidad inicial es: " << osram->getIntensity() << endl;

    osram->turnOn();
    cout << "El estado es: " << showStatus(osram->getStatus()) << endl;
    cout << "La intensidad es: " << osram->getIntensity() << endl;
    cout << "Se usó " << osram->getUses() << " vez" << endl;
    
    osram->intensify();
    cout << "La intensidad es: " << osram->getIntensity() << endl;
    
    osram->intensify();
    cout << "La intensidad es: " << osram->getIntensity() << endl;
   
    osram->attenuate();
    cout << "La intensidad es: " << osram->getIntensity() << endl;
   
    osram->turnOff();
    cout << "El estado es: " << showStatus(osram->getStatus()) << endl;

     cout << "Se usó " << osram->getUses() << " veces" << endl;
    

    delete osram;
    return 0;
}


string showStatus(Status status){
    switch (status)
    {
    case ON:
        return "Encendido";
        break;
    case OFF:
        return "Apagado";
        break;
    case BREAK:
        return "Luz agotada";
        break;
    default:
        return "";
        break;
    }
}
