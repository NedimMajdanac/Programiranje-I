#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*Napisati program koji simulira bacanje 3 kockice (jedna kockica ima 6 strana i na tim stranama su brojevi 1 - 6). Simuliranje bacanja svake kockice ostvariti funkcijom rand() % 6 + 1. Simulirati konstantno bacanje sve tri kockice dok se u dva uzastopna bacanja ne desi da se dobiju isti brojevi na sve tri kockice (npr. u šestom bacanju se dobiju brojevi 2, 2, 2, a u sedmom 4, 4, 4 na sve tri kockice).*/

int main()
{
    int brojBacanja = 0, brojIstih = 0;

    do
    {
        int k1 = rand() % 6 + 1;
        int k2 = rand() % 6 + 1;
        int k3 = rand() % 6 + 1;

        if (k1 == k2 && k2 == k3) { brojIstih++; }
        else { brojIstih = 0; }

        brojBacanja++;

    } while (brojIstih<2);

    cout << brojBacanja;
}