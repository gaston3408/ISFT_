#include "src/Models/Garage.hpp"
#include "src/Models/GarageService.hpp"

int main()
{
    Garage* garage = new Garage(50);
    GarageService* garageService = new GarageService();

    garageService->getVehicles(garage);
    garage->fixVehicles();
    garageService->deleteVehicles(garage);

    delete garage;
    delete garageService;
    return 0;
}
