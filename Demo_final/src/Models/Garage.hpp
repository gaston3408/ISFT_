#ifndef GARAGE_H
#define GARAGE_H

#include "Vehicle.hpp"

const int MAX_LIMIT = 100; 

typedef Vehicle* listVehicles[MAX_LIMIT];


class Garage
{
public:
    listVehicles vehicles;
    int max_vehicles;
    int count;

    Garage(int max_vehicles){
        this->count = 0;
        this->max_vehicles = max_vehicles < MAX_LIMIT ? max_vehicles : MAX_LIMIT;
    };

    void addVehicle(Vehicle *vehicle){
        if (this->count < this->max_vehicles)
        {
            this->vehicles[this->count] = vehicle;
            this->count++;
        }
        else
        {
            cout << "No hay mas espacio en el taller." << endl;
        }      
    }

    void fixVehicles(){
        for (int i = 0; i < this->count; i++)
        {
            this->vehicles[i]->start();
            cout << "El vehiculo de marca " << vehicles[i]->getMarca() << " de color " << vehicles[i]->getColor() << " arrancó." << endl;
        }  
    }

    ~Garage(){};
};

#endif
