#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*tako da se u svaki neparni red polje unesu parni brojevi a u svaki parni red neparni broj. 
Napraviti funkciju koja pronalazi kolonu sa najmanjim prosjekom elemenata. 
U istoj funkciji ispisati index pronađene kolone a u main funkciji sve elemente te kolone.*/

const int red = 8;
const int kolona = 8;

void unosNaTablu(int tabla[red][kolona])
{
    int temp;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            if (i % 2 == 0)
            {
                do
                {
                    cout << "Unesite neparan broj[" << i << "][" << j << "] = ";
                    cin >> temp;
                    if (temp % 2 != 0)
                    {
                        tabla[i][j] = temp;
                        break;
                    }
                    if (temp % 2 == 0)
                        cout << "GRESKA..." << endl;
                } while (temp % 2 == 0);
            }
            if (i % 2 != 0)
            {
                do
                {
                    cout << "Unesite paran broj[" << i << "][" << j << "] = ";
                    cin >> temp;
                    if (temp % 2 == 0)
                    {
                        tabla[i][j] = temp;
                        break;
                    }
                    if (temp % 2 != 0)
                        cout << "GRESKA..." << endl;
                } while (temp % 2 != 0);
            }
        }
    }
}

void ispisTable(int tabla[red][kolona])
{
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            cout << setw(3) << tabla[i][j] << " ";
        }
    }
}

int najmanjiProsjekIndex(int matrica[red][kolona])
{
    float prosjek[kolona]{ 0.0f };
    int najmanjiIndex = 0;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            prosjek[i] += matrica[j][i];
        }
        prosjek[i] /= kolona;
    }

    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            if (prosjek[i] > prosjek[najmanjiIndex])
            {
                najmanjiIndex = i;
            }
        }
    }
    return najmanjiIndex;
}

int main()
{
     int matrica[red][kolona];

    unosNaTablu(matrica);
    ispisTable(matrica);
    int index = najmanjiProsjekIndex(matrica);
    cout << endl;
    cout << "ispis kolone sa najmanjim prosjekom elemenata: " << endl;

    for (int i = 0; i < red; i++)
    {
        cout << setw(3) << matrica[i][index] << " ";
    }
}