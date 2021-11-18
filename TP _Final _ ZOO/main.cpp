#include <iostream>
#include "src/Models/AnimalList.hpp"
#include "src/Structures/HandleAnimals.hpp"


int main()
{
    HandleAnimals action;
    AnimalList *animalList = new AnimalList();
    action.getAnimals(animalList);
    action.showAnimals (animalList);
    action.deleteAnimals(animalList);
    return 0;
}
