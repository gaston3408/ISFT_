#include <iostream>

using namespace std;

int main()
{
    int hours, minutes, seconds;
    cout << "Por favor ingrese los segundos: ";
    cin >> seconds;

    hours = seconds / 3600;
    minutes = (seconds % 3600)/ 60;
    seconds = (seconds % 3600)% 60;

    cout << "la hora es " << hours << ":" << minutes << ":" << seconds;
    return 0;
}
