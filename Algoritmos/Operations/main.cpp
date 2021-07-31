#include <iostream>

using namespace std;

void showOptions()
{
    cout << "1 - Sumar" << endl;
    cout << "2 - Resta" << endl;
    cout << "3 - Multiplicar" << endl;
    cout << "4 - Dividir" << endl;
}

void showResult(int option, double firstNumber, double secondNumber)
{
    switch (option)
    {
        case 1:
            cout << "El resultado de la suma es : " << firstNumber + secondNumber << endl;
            break;
        case 2:
            cout << "El resultado de la resta es : " << firstNumber - secondNumber << endl;
            break;
        case 3:
            cout << "El resultado de la multiplicación es : " << firstNumber * secondNumber << endl;
            break;
        case 4:
            cout << "El resultado de la división es : " << firstNumber / secondNumber << endl;
            break;
    }
}

int main()
{
    int option;
    double firstNumber;
    double secondNumber;
    double result;

    showOptions();

    while(option != 1 && option != 2 && option != 3 && option != 4 )
    {
        cout << "Ingrese la operación :";
        cin >> option;
    }

    cout << "Ingrese el primer número :";
    cin >> firstNumber;

    cout << "Ingrese el segundo número :";
    cin >> secondNumber;

    showResult(option, firstNumber, secondNumber);

    return 0;
}
