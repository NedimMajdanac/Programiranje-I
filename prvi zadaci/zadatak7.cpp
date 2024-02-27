#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*Napisati program koji će omogućiti unos cjelobrojnih parnih vrijednosti sa neparnim brojem cifara jednodimenzionalni niz od 20 elemenata. 
Zatim napraviti funkciju koja će u primati kao argument taj niz. Funkcija treba da izbaci iz niza sve brojeve djeljive sa 6 a da ostavi u nizu 
sve ostale brojeve. Izbacivanje brojeva se treba napraviti tako da se ostatak niza pomjeri u lijevo da ne bi bilo praznih elemenata. 
To pomjeranje je potrebno uraditi prilikom izbacivanja svakog elementa a ne na kraju posto su svi elementi djeljivi sa 6. */

const int SIZE = 20;

bool isParan(int broj)
{
    if (broj % 2 != 0)
        return false;
    else
        return true;
}

bool isNeparanBrojCifri(int broj)
{
    int brCifri = log10(broj) + 1;
    if (brCifri % 2 == 0)
        return false;
    else
        return true;
}

void izbaciDjeljiveSaSest(int niz[], int velicina)
{
    int pomak = 0;

    for (int i = 0; i < velicina; i++)
    {
        if (niz[i] % 6 == 0)
        {
            pomak++;
        }
        else
        {
            niz[i - pomak] = niz[i];
        }
    }
    velicina -= pomak;
}


int main()
{
    int niz[SIZE];
    
    for (int i = 0; i < SIZE; i++)
    {
        do
        {
            cout << "Upisi paran broj sa neprarnim brojem cifri [" << i << "] = ";
            cin >> niz[i];

        } while (!isParan(niz[i]) && !isNeparanBrojCifri(niz[i]));
    }
    cout << "-----------------------------------------------------------" << endl;
    cout << "Originalni niz:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(3) << niz[i] << " " ;
    }
    cout << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "novi niz:" << endl;
    izbaciDjeljiveSaSest(niz, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(3) << niz[i] << " "
}