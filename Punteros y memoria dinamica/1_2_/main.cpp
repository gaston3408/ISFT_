#include <iostream>
using namespace std;
const int MAX = 10;

void showList( int* list);
void showEvenNumbers( int* list);
void showMemorySpaces( int* list);
void showMinorNumber( int* list);

int main () {
    int *numberList = new int[MAX];

    showList( numberList );
    showEvenNumbers( numberList );
    showMemorySpaces( numberList );
    showMinorNumber( numberList);
    
    delete [] numberList;
}

void showList( int *list ) {
        cout << "|";

    for (int i = 0; i < MAX; i++)
    {
        list[i] = rand()%(0-20+1)+0;
        cout << list[i] << "|";
    }

    cout << endl;

}

void showEvenNumbers( int* list) {
    cout << "Los números pares son:" << endl;

    for (int i = 0; i < MAX; i++)
    {
        (list[i] % 2) == 0 && cout << list[i] << "|";
    }

    cout << endl;
}

void showMemorySpaces( int* list) {
    cout << "Las posiciones de memoria son:" << endl;

    for (int i = 0; i < MAX; i++)
    {
        cout << &list[i] << "|";
    }

    cout << endl;
}

void showMinorNumber( int* list) {
    int minorNumber = list[0];
    cout << "El número mas chico es: ";

    for (int i = 0; i < MAX; i++)
    {
        if (list[i] < minorNumber)
        {
            minorNumber = list[i];
        }
    }

    cout << minorNumber << endl;
}