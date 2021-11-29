#include "Garage.hpp"
#include "Moto.hpp"
#include "Car.hpp"
#include "../Enums/VehicleType.hpp"

#include <iostream>
using namespace std;

class GarageService
{
private: 
    Vehicle* getVehicle(VehicleType type, string color, string marca){
        switch (type)
        {
        case MOTO:
            return new Moto(color, marca);
            break;
        case AUTO:
            return new Car(color, marca);
            break; 
        default:
            break;
        }
    };
public:
    GarageService(){};
    void getVehicles(Garage *garage){
        string color;
        string marca;
        int type;


        while (type != 0)
        {
            cout << "0 - Salir"<< endl;
            cout << "1 - Moto"<< endl;
            cout << "2 - Auto"<< endl;
            cout << "Selecciona un tipo de vehiculo: ";
            cin >> type;

            if(type != 0){

                cout << "Ingresa la marca: ";
                cin >> marca;
                cout << "Ingresa el color: ";
                cin >> color;

                VehicleType vehicleType = VehicleType(type - 1);
                Vehicle* vehicle = this->getVehicle(vehicleType, color, marca);
                garage->addVehicle(vehicle);
            }
        } 
    };

    void deleteVehicles(Garage *garage){
        for (int i = 0; i < garage->count; i++)
        {
            delete garage->vehicles[i];
        }
    };
    ~GarageService(){};
};
