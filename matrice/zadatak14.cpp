#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*dijagonalno slaganje matrica*/

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
    matrica = nullptr;
}


int** diagonalStack(int** m1, int** m2, int r1, int r2, int c1, int c2)
{
    int rows = r1 + r2;
    int cols = c1 + c2;
    int** m3 = createMatrix(rows,cols);

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            m3[i][j] = m1[i][j];
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < cols; j++)
            m3[i + r1][j + c1] = m2[i][j];
    return m3;
}



int main()
{
    int** m1 = createMatrix(3, 3);
    int** m2 = createMatrix(3, 3);

    int from = 5, to = 15;

    setRandomValues(m1, 3, 3, from, to);
    setRandomValues(m2, 3, 3, from, to);

    printMatrix(m1, 3, 3);
    printMatrix(m2, 3, 3);

    int** m3 = diagonalStack(m1,m2,3,3,3,3);
    int r3 = 3 + 3;
    int c3 = 3 + 3;

    if (m3 != nullptr)
    {
        cout << "dijagonalno slaganje m1 i m2: " << endl;
        printMatrix(m3, r3, c3);
    }

    deleteMatrix(m1, 3);
    deleteMatrix(m2, 3);
    deleteMatrix(m3, r3);
}