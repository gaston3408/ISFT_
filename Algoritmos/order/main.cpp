
/**< EJERCICIO A
Una aplicación para un restaurante que tiene: primer plato,
plato principal y postre, toma pedidos de los mozos.
Estos envían la comanda codificada por número para cada plato.
El cocinero recibe el pedido en formato de texto con el nro de mesa,
nombre mozo, fecha, hora, primer plato, plato principal y poste.
Se pide desarrollar una APP que pida la comanda y muestre por pantalla
la información solicitada.*/


#include <iostream>
#include <ctime>
#include<stdlib.h>
#include<time.h>

using namespace std;

typedef enum {salad, friedChicken, rice, soup} tDish;
typedef enum {pasta, stew, roastBeef} tMainDish;
typedef enum {iceCream, cake, fruitSalad} tDessert;

void saveDataAndSayHello(string& name, int& tableNumber);
void showDishs();
void showMainDishs();
void showDesserts();
void saveDish(tDish& dish);
void saveMainDish(tMainDish& mainDish);
void saveDessert(tDessert& dessert);
string getDish(tDish dish);
string getMainDish(tMainDish mainDish);
string getDessert(tDessert dessert);
void getDateAndHour();
void showOrder(string name, int tableNumber, tDish dish, tMainDish mainDish, tDessert dessert);

int main()
{
    tDish dish;
    tMainDish mainDish;
    tDessert dessert;
    string name;
    int tableNumber;

    saveDataAndSayHello(name, tableNumber);

    showDishs();
    saveDish(dish);

    showMainDishs();
    saveMainDish(mainDish);

    showDesserts();
    saveDessert(dessert);

    showOrder(name, tableNumber, dish, mainDish, dessert);

    return 0;
}

void showDateAndHour()
{
    time_t now = time(0);
    tm * time = localtime(&now);
    int day = time->tm_mday;
    int month = time->tm_mon + 1;
    int year = 1900 + time->tm_year;
    int hour = time->tm_hour;
    int minutes = time->tm_min;
    string adition = (minutes < 10) ? "0" : "";

    cout << day << "-" << month << "-" << year << " " << hour << ":"<< adition << minutes << endl;
}

void showDishs()
{
    cout << "**********************" << endl;
    cout << "1 - Ensalada" << endl;
    cout << "2 - Pollo frito" << endl;
    cout << "3 - Arroz" << endl;
    cout << "4 - Sopa" << endl;
    cout << "**********************" << endl;
}

void showMainDishs()
{
    cout << "**********************" << endl;
    cout << "1 - Pasta" << endl;
    cout << "2 - Guiso" << endl;
    cout << "3 - Carne asada" << endl;
    cout << "**********************" << endl;
}

void showDesserts()
{
    cout << "**********************" << endl;
    cout << "1 - Helado" << endl;
    cout << "2 - Pastel" << endl;
    cout << "3 - Ensalada de frutas" << endl;
    cout << "**********************" << endl;
}

void saveDataAndSayHello(string& name, int& tableNumber)
{
    cout << "Introduce tu nombre : ";
    cin >> name;
    cout << "Bienvenido/a " << name << "!!" << endl;
    cout << "**********************" << endl;
    cout << "Introduce tu numero de mesa : ";
    cin >> tableNumber;
    cout << "**********************" << endl;

}

void saveDish(tDish& dish)
{
    int number;
    cout << "Introduce el primer plato : ";
    cin >> number;
    dish = tDish(number - 1);
}

void saveMainDish(tMainDish& mainDish)
{
    int number;
    cout << "Introduce el plato principal : ";
    cin >> number;
    mainDish = tMainDish(number - 1);
}

void saveDessert(tDessert& dessert)
{
    int number;
    cout << "Introduce el postre : ";
    cin >> number;
    dessert = tDessert(number - 1);
}

string getDish(tDish dish)
{
    switch(dish)
    {
    case salad:
        return "Ensalada";
    case friedChicken:
        return "Pollo frito";
    case rice:
        return "Arroz";
    case soup:
        return "Sopa";
    default:
        return "Plato invalido";
    }
}

string getMainDish(tMainDish mainDish)
{
    switch(mainDish)
    {
    case pasta:
        return "Pasta";
    case stew:
        return "Guiso";
    case roastBeef:
        return "Carne asada";
    default:
        return "Plato invalido";
    }
}

string getDessert(tDessert dessert)
{
    switch(dessert)
    {
    case iceCream:
        return "Helado";
    case cake:
        return "Pastel";
    case fruitSalad:
        return "Ensalada de frutas";
    default:
        return "Plato invalido";
    };
}

void showOrder(string name, int tableNumber, tDish dish, tMainDish mainDish, tDessert dessert)
{
    srand(time(NULL));

    cout << "**********************" << endl;
    cout << "PEDIDO N°" << rand() << endl;
    cout << "Mozo : " << name << endl;
    cout << "Fecha : "; showDateAndHour();
    cout << "Primer plato : " << getDish(dish) << endl;
    cout << "Plato principal : " << getMainDish(mainDish) << endl;
    cout << "Postre : " << getDessert(dessert) << endl;
    cout << "**********************" << endl;
}
