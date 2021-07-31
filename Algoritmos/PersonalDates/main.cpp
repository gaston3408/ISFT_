#include <iostream>

using namespace std;


double getPercent(double points, int percent)
{
    return (points * percent) / 100;
}

double getResult(double laboratoryPoints, double teoryPoints, double practicePoints)
{
    double laboratoryPercent = getPercent(laboratoryPoints, 30);
    double teoryPercent = getPercent(teoryPoints, 60);
    double practicePercent = getPercent(practicePoints, 10);

    return laboratoryPercent + teoryPercent + practicePercent;
}


int main()
{
    double laboratoryPoints;
    double teoryPoints;
    double practicePoints;
    double result;

    cout << "Ingrese la nota de laboratorio : ";
    cin >> laboratoryPoints;
    cout << "Ingrese la nota teorica : ";
    cin >> teoryPoints;
    cout << "Ingrese la nota de practica : ";
    cin >> practicePoints;

    result = getResult(laboratoryPoints, teoryPoints, practicePoints);

    cout << "La nota es : " << result;

    return 0;
}
