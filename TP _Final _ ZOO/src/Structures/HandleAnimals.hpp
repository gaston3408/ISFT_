#include "../Models/Whale.hpp"
#include "../Models/Cocodrile.hpp"
#include "../Models/Goose.hpp"
#include "../Models/Pelican.hpp"
#include "../Models/Bat.hpp"
#include "../Models/SeaLion.hpp"
#include "../Enums/AnimalType.hpp"
#include "../Models/AnimalList.hpp"
#include "../AbstractModels/Animal.hpp"

const int MAX = 5;

struct HandleAnimals
{
    void getAnimals(AnimalList *animalList);
    void showAnimals (AnimalList *animalList);
    Animal* getAnimal(AnimalType type, string name, int code);
    void deleteAnimals(AnimalList *animalList);
};

void HandleAnimals::getAnimals(AnimalList *animalList){
    string name;
    int code;
    int type;

    for (int i = 0; i < MAX; i++)
    {
        cout << "Ingrese un nuevo animal." << endl;
        cout << "Nombre: ";
        cin >> name;
        cout << "Codigo: ";
        cin >> code;
        cout << "Tipo: " << endl;
        cout << "1- Cocodrilo" << endl;
        cout << "2- Ganso " << endl;
        cout << "3- Pelicano " << endl;
        cout << "4- Murcielago " << endl;
        cout << "5- Ballena " << endl;
        cout << "6- Lobo Marino " << endl;
        cout << "Seleccioná un tipo: " << endl;
        cin >> type;

        Animal* animal = getAnimal(AnimalType(type), name, code);
        animalList->addAnimal(animal);
    }
}

void HandleAnimals::showAnimals (AnimalList *animalList){
    for (int i = 0; i < animalList->count ; i++)
    {
        animalList->list[i]->eat();
        animalList->list[i]->move();
    }
    
}

Animal* HandleAnimals::getAnimal(AnimalType type, string name, int code){
    switch (type)
    {
    case COCODRILE:
        return new Cocodrile(name, code);
        break;
    case GOOSE:
        return new Goose(name, code);
        break;
    case PELICAN:
        return new Pelican(name, code);
        break;
    case BAT:
        return new Bat(name, code);
        break;
    case WHALE:
        return new Whale(name, code);
        break;
    case SEALION:
        return new SeaLion(name, code);
        break;
    }
}

void HandleAnimals::deleteAnimals(AnimalList *animalList)
{
    for (int i = 0; i < animalList->count; i++)
    {
        delete animalList->list[i];
    }
    
}
