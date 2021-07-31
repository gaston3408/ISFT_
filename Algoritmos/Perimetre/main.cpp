#include <iostream>

using namespace std;

void showSquarePerimeter()
{
    double lenght;
    cout << "Ingresa la longitud : ";
    cin >> lenght;

    cout << "El perimetro es :" << 4*lenght;
}

void showRectanglePerimeter()
{
    double lenght;
    double lenght2;

    cout << "Ingresa la longitud : ";
    cin >> lenght;
    cout << "Ingresa la otra longitud : ";
    cin >> lenght2;

    cout << "El perimetro es :" << (2*lenght) + (2*lenght2);
}

void showTrianglePerimeter()
{
    double lenght;
    double lenght2;
    double lenght3;

    cout << "Ingresa la longitud : ";
    cin >> lenght;
    cout << "Ingresa la otra longitud : ";
    cin >> lenght2;
    cout << "Ingresa la otra longitud : ";
    cin >> lenght3;

    cout << "El perimetro es :" << lenght + lenght2 + lenght3;
}

void showOptions()
{
    cout << "Calculemos perimetros !!!" << endl;
    cout << " 1 - Cuadrado " << endl;
    cout << " 2 - Rectangulo " << endl;
    cout << " 3 - Triangulo " << endl;
}

int main()
{
    int option = 0;
    showOptions();

    while (option == 0 || option > 3)
    {
        cout << "Ingresa la opción deseada : ";
        cin >> option;
    }

    if(option == 1) showSquarePerimeter();
    if(option == 2) showRectanglePerimeter();
    if(option == 3) showTrianglePerimeter();

    return 0;
}
