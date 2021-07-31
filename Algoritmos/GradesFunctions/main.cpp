#include <iostream>
using namespace std;

void showOptions()
{
    cout << "1 - De Centigrados a Fahrenheit" << endl;
    cout << "2 - De Fahrenheit a Centigrados" << endl;
}

double getResult(int option, double number)
{
   if( option == 1 )
    {
        return ((number * 9)/5) + 32 ;
    }

    return (number - 32) * 5/9;
}

void showResult(int option, double number, double result)
{
    string numberGrades = option == 1 ? "°C" : "°F";
    string resultGrades = option == 1 ? "°F" : "°C";

    cout << number << numberGrades << " equivalen a " << result << resultGrades;
}

int main()
{
    int option = 3;
    double number;
    double result;

    showOptions();

    while( option != 1 && option != 2 )
    {
        cout << "Ingrese la opción : ";
        cin >> option;
    }

    cout << "Ingrese el número a convertir : ";
    cin >> number;

    result = getResult(option, number);

    showResult(option, number, result);

    return 0;
}
