#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*Napisati program za sabiranje matrica proizvoljnih dimenzija.
	Neka su date dvije matrice A i B, koje je potrebno popuniti slučajnim vrijednostima u opsegu [1-5]
	Formirati matricu C kao zbir matrica A i B:
	C[i,j] = A[i,j] + B[i,j]*/


int getRandomValues(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

int** createMatrix(int rows, int columns)
{
    int** matrica = new int* [rows];
    for (int i = 0; i < rows; i++)
        *(matrica + i) = new int[columns];
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
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << setw(3) << *(*(matrica + i) + j) << " " ;
        }
    }
}

int** sumMatrix(int** m1, int** m2, int rows, int columns)
{
    int** m3 = createMatrix(rows, columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            *(*(m3 + i) + j) = *(*(m1 + i) + j) + *(*(m2 + i) + j);
        }
    }
    return m3;
}

void deleteMatrix(int** matrica, int rows)
{
    for (int i = 0; i < rows; i++)
    {
       delete[] *(matrica + i);
       *(matrica + i) = nullptr;
    }
    delete[]matrica;
    matrica = nullptr;
}

int main()
{
   int red, kolona;

    while (cout << "Red: ", cin >> red, red < 2);
    while (cout << "Kolona: ", cin >> kolona, kolona < 2);

    // kreiranje
    int** m1 = createMatrix(red,kolona);
    int** m2 = createMatrix(red,kolona);
    
    int from = 1, to = 5;

    // postavljanje vrijednosti
    setRandomValues(m1, red, kolona, from, to);
    setRandomValues(m2, red, kolona, from, to);

    // ispis
    cout << "Matrica 1 : " << endl;
    printMatrix(m1, red, kolona);
    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "matrica 2 : " << endl;
    printMatrix(m2, red, kolona) ;
    cout << endl;
    cout << "-----------------------------------------------------" << endl;

    int** m3 = sumMatrix(m1, m2, red, kolona);

    cout << "Zbir dvije matrice:" << endl;
    printMatrix(m3, red, kolona);
    cout << endl;
    cout << "-----------------------------------------------------" << endl;

    deleteMatrix(m1, red);
    deleteMatrix(m2, red);
    deleteMatrix(m3, red);
}