#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*Neka je data matrica M proizvoljnih dimenzija koje određuje korisnik. 
	Popuniti matricu M slučajnim vrijednostima u opsegu [6-10]
	Napisati dvije funkcije:
	-> getAveragesByRow [funkcija koja treba da vrati prosjeke redova]
	-> getAveragesByColumn [funkcija koja treba da vrati prosjeke kolona
*/

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

void deleteMatrix(int** matrica, int rows)
{
    for (int i = 0; i < rows; i++)
    {
       delete[] *(matrica + i);
       *(matrica + i) = nullptr;
    }
    delete[]matrica;
}

float* getAveragesByColumn(int** matrica, int rows, int columns)
{
    float* prosjeKolone = new float [columns] {0.0f};

    for (int j = 0; j < columns; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            *(prosjeKolone + j) += *(*(matrica + i) + j);
        }
        *(prosjeKolone + j) /= rows;
    }
    return prosjeKolone;
}

float* getAveragesByRow(int** matrica, int rows, int columns)
{
    float* prosjekReda = new float[rows] {0.0f};

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            *(prosjekReda + i) += *(*(matrica + i) + j);
        }
        *(prosjekReda) /= columns;
    }
    return prosjekReda;
}

void printArray(float* average, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(3) << *(average + i) << " ";
    }
}

void deleteArray(float* average)
{
    delete[]average;
}



int main()
{
    int red, kolona;

    while (cout << "Red: ", cin >> red, red < 2);
    while (cout << "Kolona: ", cin >> kolona, kolona < 2);

    int** matrica = createMatrix(red, kolona);

    setRandomValues(matrica, red, kolona, 6, 10);

    printMatrix(matrica, red, kolona);

    cout << "--------------------------------------------------------------------" << endl;
    cout << "prosjek redova:" << endl;
    float* averageRow = getAveragesByRow(matrica, red, kolona);
    printArray(averageRow, red);

    cout << "--------------------------------------------------------------------" << endl;
    cout << "prosjek kolona: " << endl;
    float* averageColumn = getAveragesByColumn(matrica, red, kolona);
    printArray(averageColumn, kolona);

    deleteMatrix(matrica, red);
    deleteArray(averageRow);
    deleteArray(averageColumn);
}