/**<
Un empresa de viaje nos pide que realicemos un programa para tomar
reservas en avión, las mismas pueden ser clase Primera, Bussiness y
económica, además del dni apellido y nombre, aeropuerto origen y destino:
Código Aeropuerto
1. Bahía Blanca-BHI
2. Buenos Aires Aeroparque-AEP
3. Buenos Aires El Palomar-EPA
4. Buenos Aires Ezeiza-EZE
5. San Carlos de Bariloche-BRC
6. San Fernando del Valle de Catamarca-CTC
7. Comodoro Rivadavia-CRD
El usuario introduce los datos personales, la clase y el origen – destino,
mostrando el resultado x pantalla.
 */

#include <iostream>

using namespace std;

typedef enum {first, economic, business} tClase;
typedef enum {BHI, AEP, EPA, EZE, BRC, CTC, CRD} tPlace;

void showPlaces();
void showClases();
void selectClase(tClase& clase);
void selectPlace(tPlace& place, string action);
void savePersonalInformation(string& names, long& dni);
string getClase(tClase clase);
string getPlace(tPlace place);
void showResult(string names, long dni, tClase clase, tPlace origin, tPlace destiny);

int main()
{
    string names;
    long dni;
    tClase clase;
    tPlace origin;
    tPlace destiny;

    savePersonalInformation(names, dni);
    showClases();
    selectClase(clase);
    showPlaces();
    selectPlace(origin, "origen");
    showPlaces();
    selectPlace(destiny, "destino");

    showResult(names, dni, clase, origin, destiny);


    return 0;
}

void showPlaces()
{
    cout << "*************************" << endl;
    cout << "1. Bahía Blanca-BHI" << endl;
    cout << "2. Buenos Aires Aeroparque-AEP" << endl;
    cout << "3. Buenos Aires El Palomar-EPA" << endl;
    cout << "4. Buenos Aires Ezeiza-EZE" << endl;
    cout << "5. San Carlos de Bariloche-BRC" << endl;
    cout << "6. San Fernando del Valle de Catamarca-CTC" << endl;
    cout << "7. Comodoro Rivadavia-CRD" << endl;
    cout << "*************************" << endl;
}

void showClases()
{
    cout << "*************************" << endl;
    cout << "1. Primera" << endl;
    cout << "2. Economica" << endl;
    cout << "3. Business" << endl;
    cout << "*************************" << endl;
}

void savePersonalInformation(string& names, long& dni)
{
    cout << "*************************" << endl;
    cout << "Bienvenido!! Aqui puede reservar su pasaje." << endl;
    cout << "*************************" << endl;
    cout << "Ingrese su apellido y nombre : ";
    getline(cin, names);
    cout << "Ingrese su DNI : ";
    cin >> dni;
}

void selectClase(tClase& clase)
{
    int number;
    cout << "Ingrese la clase : ";
    cin >> number;
    clase = tClase(number - 1);
    cout << "*************************" << endl;
}

void selectPlace(tPlace& place, string action)
{
    int number;
    cout << "Ingrese su " << action << " : ";
    cin >> number;
    place = tPlace(number - 1);
    cout << "*************************" << endl;
}

string getClase(tClase clase)
{
    switch(clase)
    {
    case first:
        return "Primera";
    case economic:
        return "Economica";
    case business:
        return "Business";
    default:
        return "Clase invalida";
    }
}

string getPlace(tPlace place)
{
    switch(place)
    {
    case BHI:
        return "Bahía Blanca-BHI";
    case AEP:
        return "Buenos Aires Aeroparque-AEP";
    case EPA:
        return "Buenos Aires El Palomar-EPA";
    case EZE:
        return "Buenos Aires Ezeiza-EZE";
    case BRC:
        return "San Carlos de Bariloche-BRC";
    case CTC:
        return "San Fernando del Valle de Catamarca-CTC";
    case CRD:
        return "Comodoro Rivadavia-CRD";
    default:
        return "Lugar invalido";
    };
}

void showResult(string names, long dni, tClase clase, tPlace origin, tPlace destiny)
{
    cout << "*************************" << endl;
    cout << "RESERVA" << endl;
    cout << "Para " << names << endl;
    cout << "Dni : " << dni << endl;
    cout << "Clase " << getClase(clase) << endl;
    cout << "Origen " << getPlace(origin) << endl;
    cout << "Destino " << getPlace(destiny) << endl;
    cout << "*************************" << endl;
}

