#ifndef ANIMALLIST_H
#define ANIMALLIST_H

#include "../AbstractModels/Animal.hpp"
typedef Animal *ListAnimals[100];

class AnimalList
{
public : 
    ListAnimals list;
    int count;
    AnimalList(){};

    void addAnimal(Animal *animal)
    {
        this->list[count] = animal;
        this->count++;
    }

    ~AnimalList(){};
};

#endif