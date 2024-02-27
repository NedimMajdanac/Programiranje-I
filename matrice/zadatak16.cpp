#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*suma glavne i sporedne dijagonale, i suma ispod sporedne i suma iznad glavne dijagonale*/

int getRandomValues(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

int** createMatrix(int rows, int columns)
{
    int** matrica = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        *(matrica + i) = new int[columns];
    }
    return matrica;
}

void setRandomValues(int** matrica, int rows, int columns, int from, int to)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            *(*(matrica + i) + j) = getRandomValues(from, to);
        }
    }
}

void printMatrix(int** matrica, int rows, int columns)
{
    cout << "---------------------------------------------------" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << "Matrica [" << i << "][" << j << "] = " << *(*(matrica + i) + j) << endl;
        }
    }
}

int sumaSporedneDijagonale(int** matrica,int rows,int columns)
{
    int suma = 0;
    for (int i = 0; i < rows; i++)
    {
        suma += matrica[i][rows - 1 - i];
    }
    return suma;
}

int sumaGlavneDijagonale(int** matrica,int rows,int columns)
{
    int suma = 0;
    for (int i = 0; i < rows; i++)
    {
        suma += matrica[i][i];
    }
    return suma;
}

int sumaIspodSporedneDijagonale(int** matrica,int rows,int columns)
{
    int suma = 0;
    for (int i = 1; i < rows; ++i)
    {
        for (int j = 0; j < columns-i; ++j)
        {
            suma += matrica[i + j][j];
        }
    }
    return suma;
}

int sumaIznadGlavneDijagonale(int** matrica,int rows,int columns)
{
    int suma = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = i+1; j < columns; ++j)
        {
            suma += matrica[i][j];
        }
    }
    return suma;
}

int main()
{
    srand(time(NULL));

    

    /*int red, kolona;
    cout << "Unesite red: " << endl;
    cin >> red;
    cout << "Unesite broj kolona: " << endl;
    cin >> kolona;
    int** m = new int* [red];
    for (int i = 0; i < red; i++)
        m[i] = new int[kolona];

    setRandomValues(m, red, kolona, 5, 15);
    printMatrix(m, red, kolona);

    cout << "Suma sporedne: " << sumaSporedneDijagonale(m, red, kolona) << endl;
    cout << "suma glavne: " << sumaGlavneDijagonale(m, red, kolona) << endl;
    cout << "suma ispod sporedne: " << sumaIspodSporedneDijagonale(m, red, kolona) << endl;
    cout << "suma iznad glavne: " << sumaIznadGlavneDijagonale(m, red, kolona) << endl;

    deleteMatrix(m, red);
}