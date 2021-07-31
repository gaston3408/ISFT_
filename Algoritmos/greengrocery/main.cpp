/**<
Un Verdulería nos pide que armemos el pedido para el mayorista para lo cual
deberemos pedir al usuario el código proveedor, razón social, fecha de
solicitud y fecha de entrega. Las frutas estarán enumeradas (tomar solo 6 a
modo de ejemplo), mostrando los datos x pantalla.
 */

#include <iostream>

using namespace std;

typedef enum {banana, manzana, frutilla, naranja, durazno, uva} tFruit;

void showDate();
void showFruits();
tFruit selectFruit();
void savePersonalInformation(long& proveedor, string& businessName, string& date);
string getFruit(tFruit fruit);
void showResult(long proveedor, string businessName, string date, tFruit* fruits, int index);

int main()
{
    long proveedor;
    string businessName;
    string date;
    tFruit fruits[10];
    int index = 0;
    char next ='S';

    savePersonalInformation(proveedor, businessName, date);
    showFruits();

    while(next == 'S' && index <= 10)
    {
        fruits[index] = selectFruit();
        index++;
        cout << "Desea agregar otra fruta ? S/N: ";
        cin >> next;
    }

    showResult(proveedor, businessName, date, fruits, index);

    return 0;
}

void showFruits()
{
    cout << "*************************" << endl;
    cout << "1. Banana x Kilo" << endl;
    cout << "2. Manzana x Kilo" << endl;
    cout << "3. Frutilla x Kilo" << endl;
    cout << "4. Naranja x Kilo" << endl;
    cout << "5. Durazno x Kilo" << endl;
    cout << "6. Uva x Kilo" << endl;
    cout << "*************************" << endl;
}

void savePersonalInformation(long& proveedor, string& businessName, string& date)
{
    cout << "*************************" << endl;
    cout << "Bienvenido!! Aqui puede ingresar su pedido." << endl;
    cout << "*************************" << endl;
    cout << "Ingrese su razon social : ";
    getline(cin, businessName);
    cout << "Ingrese el numero de proveedor : ";
    cin >> proveedor;
    cout << "Ingrese fecha de entrega [DD-MM-YYYY] : ";
    cin >> date;
}

tFruit selectFruit()
{
    int number;
    tFruit fruit;
    cout << "Ingrese la fruta : ";
    cin >> number;
    fruit = tFruit(number - 1);

    return fruit;
}

string getFruit(tFruit fruit)
{
    switch(fruit)
    {
    case banana:
        return "1 Kilo de Banana";
    case manzana:
        return "1 Kilo de Manzana";
    case frutilla:
        return "1 Kilo de Frutilla";
    case naranja:
        return "1 Kilo de Naranja";
    case durazno:
        return "1 Kilo de Durazno";
    case uva:
        return "1 Kilo de Uva";
    default:
        return "Fruta invalida";
    };
}

void showDate()
{
    time_t now = time(0);
    tm * time = localtime(&now);
    int day = time->tm_mday;
    int month = time->tm_mon + 1;
    int year = 1900 + time->tm_year;

    cout << day << "-" << month << "-" << year << endl;
}

void showResult(long proveedor, string businessName, string date, tFruit* fruits, int index)
{
    cout << "*************************" << endl;
    cout << "PEDIDO" << endl;
    cout << "Proveedor : " << proveedor << endl;
    cout << "Razon Social : " << businessName << endl;
    cout << "Fecha : "; showDate();
    cout << "Fecha de entrega : " << date << endl;
    for(int i = 0; i < index; i++)
    {
        cout << " + " << getFruit(fruits[i]) << endl;
    }
    cout << "*************************" << endl;
}
