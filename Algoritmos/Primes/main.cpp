#include <iostream>

using namespace std;

bool isPrime (int number)
{
    bool prime = true;

    if(number == 0 || number == 1) return prime;

    int i = 2;

    while (i < number && prime == true)
    {
        if( number % i == 0 )
        {
            prime = false;
        }
        i ++;
    }

    return prime;
}

void showResult(bool isPrime, int number)
{
    if(isPrime) cout << number << " es primo" ;
    else cout << number << " no es primo" ;
}

int main()
{
    int number;

    cout << "Ingresa un numero para saber si es primo : ";
    cin >> number;

    showResult( isPrime(number), number );

    return 0;
}
