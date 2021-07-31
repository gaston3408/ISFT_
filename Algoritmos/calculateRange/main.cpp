#include <iostream>

using namespace std;

bool isInRange(int firstNumber, int secondNumber, int number)
{
    return number >= firstNumber && number <= secondNumber;
}

void showResult(bool ok)
{
    if(ok){
        cout << "Está en el rango" << endl;
    }
    else
    {
        cout << "No está en el rango" << endl;
    }
}

int main()
{
    int firstNumber = 0;
    int secondNumber = 0;
    int number;

    cout << "Bienvenido !!!" << endl;

    while (firstNumber >= secondNumber)
    {
        cout << "Ingrese el numero más bajo : ";
        cin >> firstNumber;
        cout << "Ingrese el numero mas alto : ";
        cin >> secondNumber;
    }

    cout << "Ingrese el numero a evaluar : ";
    cin >> number;

    showResult( isInRange(firstNumber, secondNumber, number) );

    return 0;
}
