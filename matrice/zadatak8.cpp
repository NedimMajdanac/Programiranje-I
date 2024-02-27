#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


/*Neka je data matrica dimenzija 10x12 u kojoj svaki red predstavlja uposlenika firme, a svaka kolona mjesec u godini.
Elementi matrice predstavljaju evidentirane plate po mjesecima i uposlenicima (plata je iznos sa dvije decimalne cifre iza zareza). 
Kreirati, a potom u glavnom programu testirati, sljedeće funkcije:

•	Funkciju za unos plata za sve uposlenike za odabrani mjesec. Omogućiti poziv funkcije iz main funkcije više puta kako bi se unijeli podaci za 
    sve mjesece u godini. 

•	Funkciju koja za odabranog uposlenika vrši ispis plata po mjesecima. Ukoliko je za neki od mjeseci, uposlanik bio na neplacenom otsustvu, 
    njegova plata ce biti 0 i nece se ispisivati podatak za taj mjesec. Pored toga, funkcija kao rezultat vraća prosječnu platu za cijelu
    godinu za odabranog uposlenika ukljucujuci i mjesece otsustva.

•	Funkciju koja pronalazi uposlenika sa najvecom prosjecnom platom i ispisuje iznos prosjecne plate zaokruzen na dvije decimale, 
    te vraca index tog uposlenika.
*/

const int SIZE_ROW = 10; // broj uposlenika
const int SIZE_COLUMN = 12; // broj mjeseci

void unosPlate(int matrica[SIZE_ROW][SIZE_COLUMN])
{
    for (int i = 0; i < SIZE_ROW; i++)
    {
        for (int j = 0; j < SIZE_COLUMN; j++)
        {
            matrica[i][j] = rand() % 1000 + 1;
            cout << "Plata za radnika na indexu [" << i << "] za " << j << ". mjesec je: " << matrica[i][j] << endl;
            
        }
    }
}

void ispisPlata(int matrica[SIZE_ROW][SIZE_COLUMN], int indexRadnika)
{
    float prosjecnaPlata = 0.0f;

    cout << "Radnik sa indexom [" << indexRadnika << "] ima platu po mjesecima: " << endl;
    for (int i = 0; i < SIZE_ROW; i++)
    {
        for (int j = 0; j < SIZE_COLUMN; j++)
        {
            if (indexRadnika == i)
            {
                cout << j << ". mjesec plata je: " << matrica[i][j] << endl;
                prosjecnaPlata += matrica[i][j];
            }
        }
    }
    cout << "Prosjecna plata radnika sa indexom [" << indexRadnika << "] je " << prosjecnaPlata / 12 << endl;

}

int najveciProsjekIndex(int matrica[SIZE_ROW][SIZE_COLUMN])
{
    float prosjek[SIZE_ROW] = { 0.0f };
    for (int i = 0; i < SIZE_ROW; i++)
    {
        for (int j = 0; j < SIZE_COLUMN; j++)
        {
            prosjek[i] += matrica[i][j];
        }
    }
    
    int najveciIndex = 0;
    for (int i = 0; i < SIZE_ROW; i++)
    {
        for (int j = 0; j < SIZE_COLUMN; j++)
        {
            if (prosjek[i] < prosjek[najveciIndex])
            {
                najveciIndex = i;
            }
        }
    }
    return najveciIndex;
}

int main()
{
    int matrica[SIZE_ROW][SIZE_COLUMN];

    unosPlate(matrica);
    
    int index;
    cout << endl;
    do
    {
        cout << "unesite radnicki index: ";
        cin >> index;
    } while (index>9);
    
    cout << endl;
    ispisPlata(matrica, index);
    cout << "Radnik sa najvecom prosjecnom platom se nalazi na indexu: " << najveciProsjekIndex(matrica);
}