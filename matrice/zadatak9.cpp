#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*Dat je 2D niz koji simulira šahovsku tablu. Omogućiti korisniku unos cjelobrojnih elemenata 2D niza tako da se u svako „crno“ polje unese parni broj
sa neparnim brojem cifara a u „bijelo“ polje neparni broj sa parnim brijem cifara. Provjeriti da li je matrica simetricna po glavnoj dijagonali 
(dakle da li je broj na poziciji 1.0 jedna broju na poziciji 0.1, na 0.2 jednak onome na 2.0, na 3.1 jednak onome na 1.3 itd.) te 
ako jeste simetricna naci i ispisati index reda sa najvecim prosjekom elemenata, a ako nije u potpunosti simetricna naci i ispisati index 
kolone sa najmanjim prosjekom elemenata.*/

const int red = 8;
const int kolona = 8;

int brojCifri(int broj)
{
    return log10(broj) + 1;
}

void unosNaTablicu(int matrica[red][kolona])
{
    bool unesen = false;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            do
            {
                int broj = rand() % 20 + 1;
                if ((i + j) % 2 == 0 && broj % 2 == 0 && brojCifri(broj) % 2 != 0)
                {
                    matrica[i][j] = broj;
                    unesen = true;
                }
                else if ((i + j) % 2 != 0 && broj % 2 != 0 && brojCifri(broj) % 2 == 0)
                {
                    matrica[i][j] = broj;
                    unesen = true;
                }

            } while (!unesen);
            unesen = false;
        }
    }
}

bool isSimetricnaPoGlavnoj(int matrica[red][kolona])
{
    if (red != kolona)
        return false;
    for (int i = 0; i < red; i++)
        for (int j = 0; j < kolona; j++)
            if (matrica[i][j] != matrica[j][i])
                return false;
    return true;
}

int indexRedaNajvecegProsjeka(int matrica[red][kolona])
{
    float najveciProsjek[red] = { 0.0f };
    int najveciIndex = 0;
    
        for (int i = 0; i < red; i++)
        {
            for (int j = 0; j < kolona; j++)
            {
                najveciProsjek[i] += matrica[i][j];
            }
            najveciProsjek[i] /= kolona;
        }
        for (int i = 0; i < red; i++)
        {
            for (int j = 0; j < kolona; j++)
            {
                if (najveciProsjek[i] < najveciProsjek[najveciIndex])
                {
                    najveciIndex = i;
                }
            }
        }
    return najveciIndex;
}

int indexKoloneNajmanjegProsjeka(int matrica[red][kolona])
{
    float najmanjiProsjek[kolona] = { 0.0f };
    int najmanjiIndex = 0;

    for (int j = 0; j < kolona; j++)
    {
        for (int i = 0; i < red; i++)
        {
            najmanjiProsjek[j] += matrica[i][j];
        }
        najmanjiProsjek[j] /= red;
    }
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            if (najmanjiProsjek[i] > najmanjiProsjek[najmanjiIndex])
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

    unosNaTablicu(matrica);

    if (isSimetricnaPoGlavnoj(matrica))
        cout << "index: " << indexRedaNajvecegProsjeka(matrica);
    if (!isSimetricnaPoGlavnoj(matrica))
        cout << "index: " << indexKoloneNajmanjegProsjeka(matrica);
}