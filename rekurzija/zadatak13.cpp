#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


void enterArray(int** parray, int vel, int i=0)
{
    if (i == vel)
        return;
    cout << "Unesite element niza[" << i << "] = ";
    cin >> *parray[i];
    enterArray(parray, vel, i + 1);
}

void printArray(int** parray, int vel, int i = 0)
{
    if (i >= vel)
        return;
    cout << "Element[" << i << "] = " << *parray[i] << endl;
    printArray(parray, vel, i + 1);
}

int sumArray(int** parray, int vel, int i = 0)
{
    if (i == vel)
        return 0;
    return *parray[i] + sumArray(parray, vel, i + 1);
}

int findElement(int** parray, int vel, int target, int i = 0)
{
    if (i == vel)
        return -1;
    if (target == *parray[i])
        return i;
    return findElement(parray, vel, target, i + 1);
}



int main()
{
int* parray[10] = { nullptr };
//alokacija
for (int i = 0; i < size(parray); i++)
    parray[i] = new int;

enterArray(parray, size(parray));
printArray(parray, size(parray));
cout << "----------------------------------------------" << endl;

cout << "suma elemenata je: " << sumArray(parray, size(parray)) << endl;
cout << "----------------------------------------------" << endl;

int target;

cout << "Upisite broj za pretragu: ";
cin >> target;

int index = findElement(parray, size(parray), target);
if (index != -1)
    cout << "element je pronadjen na indexu: " << index << endl;
else
    cout << "element se ne nalazi u nizu..." << endl;


// dealokacija
for (int i = 0; i < size(parray); i++)
{
    delete parray[i];
    parray[i] = nullptr;
}
}