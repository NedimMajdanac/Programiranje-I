#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


/*1d niz rekurzivno napraviti unos, ispis, sumu elemenata, sumu poz elemenata i sumu neparnih indeksa*/

void upisNiza(int* niz, int vel, int i)
{
    if (i == vel)
        return;
    cout << "Element niza[" << i << "] = ";
    cin >> *(niz + i);
    upisNiza(niz, vel, i + 1);
}

void ispisNiza(int* niz, int vel, int i)
{
    if (i >= vel)
        return;
    cout << *(niz+i) << endl;
    ispisNiza(niz, vel, i + 1);
}

int sumaElemenata(int* niz, int vel, int i)
{
    if (i == vel)
        return 0;
    return *(niz + i) + sumaElemenata(niz, vel, i + 1);
}

int sumaPozitivnihElemenata(int* niz, int vel, int i)
{
    if (i == vel) 
        return 0;
    return (*(niz + i) > 0 ? *(niz + i) : 0) + sumaPozitivnihElemenata(niz, vel, i + 1);
        
}

int sumaNeparnihIndexa(int* niz, int vel, int i)
{
    if (i == vel)
        return 0;
    return (i % 2 == 0 ? *(niz + i) : 0) + sumaNeparnihIndexa(niz, vel, i + 1);
}




int main()
{
    int velicina;
    cout << "Velicina: ";
    cin >> velicina;

    int* niz = new int[velicina];

    cout << "Upisi elemente niza:" << endl;
    upisNiza(niz, velicina, 0);
    cout << "------------------------------------------------------" << endl;

    cout << "Ispis elemenata niza:" << endl;
    ispisNiza(niz, velicina, 0);
    cout << "------------------------------------------------------" << endl;

    cout << "Suma svih elemenata je: " << sumaElemenata(niz, velicina, 0) << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "Suma svih pozitivnih elemenata je: " << sumaPozitivnihElemenata(niz, velicina, 0) << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "Suma svih neparnih indeksa je: " << sumaNeparnihIndexa(niz, velicina, 0) << endl;

    delete[]niz;
    niz = nullptr;
}