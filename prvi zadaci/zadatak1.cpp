#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*Napisati program koji simulira izvlacenje 3 karte. Karte mogu imati vrijednosti od 1 do 14 (koristeci rand() funkciju). 
Cilj je da se dobiju 3 vrijednosti karata koje su medjusobno u razmaku po 5 (npr 1, 6, 11). 
Program treba da ispise koliko je pokusaja bilo potrebno da se te ostvari i konacnu kombinaciju vrijednosti karata*/

int main()
{
	srand(time(NULL));
	
    int karta1;
    int karta2; 
    int karta3; 
    int pokusaj = 0;

    while (true)
    {
        karta1 = rand() % 14 + 1;
        karta2 = rand() % 14 + 1;
        karta3 = rand() % 14 + 1;
        if (karta3 - karta2 == 5 && karta2 - karta1 == 5)
            break;
        pokusaj++;
    }

    cout << karta1 << "  " << karta2 << "  " << karta3 << endl;
    cout << "pokusaja: " << pokusaj << endl;
}
