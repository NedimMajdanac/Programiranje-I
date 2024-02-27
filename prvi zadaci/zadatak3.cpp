#include <iostream>
#include <cmath>

using namespace std;

/*unosi se binarni broj i provjerava se da li je i onda se vrsi konverzija u oktalni*/

bool isBinary(int broj)
{
    while (broj)
    {
        if (broj % 10 != 0 && broj % 10 != 1)
            return false;
        broj /= 10;
    }
    return true;
}

int toOctal(int broj)
{
    int octalNumber = 0, decimalNumber = 0, brojac = 0;
    while (broj != 0)
    {
        decimalNumber += (broj % 10) * pow(2, brojac);
        brojac++;
        broj /= 10;
    }
    brojac = 1;
    while (decimalNumber != 0)
    {
        octalNumber += (decimalNumber % 8) * brojac;
        decimalNumber /= 8;
        brojac *= 10;
    }
    return octalNumber;
}



int main()
{
    int broj;
    
    do
    {
        cout << "uneciste neki binarni broj: ";
        cin >> broj;
    } while (!isBinary(broj));

    cout << "Binarni broj " << broj << " je u oktalnom sistemu " << toOctal(broj) << endl;
}
