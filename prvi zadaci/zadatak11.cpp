#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*Napisati funkciju koja kao parametare prima dva niza char recenica[200] i char rijec[10] odnosno rečenicu 
(niz od najviše 200 karaktera) i riječ (niz od najviše 10 karaktera) te u nizu recenica[200] 
pretrazuje i pronalazi sekvencu karaktera unesenih u niz rijec[10], te prebrojati koliko puta se ta sekvenca nalazi u recenici.
Radi jednostavnosti rjesenja podrazumjeva se da i recenica i rijec koja se pretrazuje zavrsavaju tackom.*/

const int velicinaRecenice = 200;
const int velicinaRijec = 10;

int brojSekvenciRecenice(char recenica[], char rijec[])
{
    int brojac = 0;
    int duzinaRecenice = strlen(recenica);
    int duzinaRijec = strlen(rijec);

    for (int i = 0; i <= duzinaRecenice - duzinaRijec; i++)
    {
        bool pronadjen = true;
        for (int j = 0; j < duzinaRijec; ++j)
        {
            if (recenica[i+j] != rijec[j])
            {
                pronadjen = false;
                break;
            }
        }
        if (pronadjen)
        {
            brojac++;
        }
    }
    return brojac;
}

int main()
{
    char recenica[velicinaRecenice];
    char rijec[velicinaRijec];

    cout << "Upisi neki string: " << endl;
    cin.getline(recenica,velicinaRecenice);
    cout << "Upisite rijec za pretragu: " << endl;
    cin.getline(rijec,velicinaRijec);

    cout << brojSekvenciRecenice(recenica,rijec);
    
}