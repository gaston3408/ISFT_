#include <iostream>

using namespace std;

void getNumbers( int *array, int size);
void showNumbers( int *array , int size);
void orderNumbers( int *array , int size);

int main()
{
    int *arrayPuntero = new int[5];

    getNumbers( arrayPuntero, 5 );
    cout << "Números : " << endl;
    showNumbers( arrayPuntero, 5 );
    cout << "Números ordenados : " << endl;
    orderNumbers( arrayPuntero, 5 );
    showNumbers( arrayPuntero, 5 );

    delete [] arrayPuntero;
   
    return 0;
}

void showNumbers( int *array , int size){

    cout << "| ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " | "; 
    }
    cout << endl;
}

void orderNumbers( int *array , int size){
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (array[j] < array[j-1]){
                int aux = array[j];
                array[j] = array[j-1];
                array[j-1] = aux;
            }
        } 
    }
}

void getNumbers( int *array, int size){

   cout << "*** Vamos a ingresar 5 números ***" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Ingrese un número : "; 
        cin >> array[i];
        cout << endl;
    }
}
