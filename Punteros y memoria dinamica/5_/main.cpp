#include <iostream>
using namespace std;

int **matriz;
int **matriz2;

void getRowsAndCols( int *cols, int *rows);
void createSpaces( int cols, int rows);
void getData( int cols, int rows);
void showMatriz(int **matriz, int rows, int cols);
void sumMatrizes(int rows, int cols);
void deleteMatrizes(int rows);

int main()
{
    int cols;
    int rows;
    getRowsAndCols( &cols, &rows);
    createSpaces(cols, rows);
    getData(cols, rows);
    showMatriz(matriz, rows, cols);
    showMatriz(matriz2, rows, cols);
    sumMatrizes(rows, cols);
    deleteMatrizes(rows);
    
    return 0;
}

void getRowsAndCols( int *cols, int *rows){
    cout << "Ingrese las columnas: ";
    cin >> *cols;
    cout << "Ingrese las filas: ";
    cin >> *rows;
}

void createSpaces( int cols, int rows){
    matriz = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        matriz[i] = new int[cols];
    }

    matriz2 = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        matriz2[i] = new int[cols];
    }
}

void getData( int cols, int rows ){
    cout << "*** Ingrese los numeros de la matriz 1 ***" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Ingrese número ["<< i <<"]["<< j <<"]";
            cin >> matriz[i][j];
        }
        
    }

    cout << "*** Ingrese los numeros de la matriz 2 ***"<< endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Ingrese número ["<< i <<"]["<< j <<"]";
            cin >> matriz2[i][j];
        }
        
    }
}

void showMatriz(int **matrizDin, int rows, int cols){
    cout << "La matriz es: " << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "|";
        for (int j = 0; j < cols; j++)
        {
            cout << matrizDin[i][j] << "|";
        } 
        cout << endl;
    }
}

void sumMatrizes(int rows, int cols){

    cout << "La suma de las matrices es: " << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "|";
        for (int j = 0; j < cols; j++)
        {
            cout << matriz[i][j] + matriz2[i][j] << "|";
        } 
        cout << endl;
    }
}

void deleteMatrizes(int rows){
    for (int i = 0; i < rows; i++)
    {
        delete [] matriz[i];
        delete [] matriz2[i];
    }
    delete [] matriz;
    delete [] matriz2;

    cout << "deleted"<< endl;
}


