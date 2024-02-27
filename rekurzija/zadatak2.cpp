#include<iostream>
#include <cmath>

/*Napisati rekurzivne funkcije koje popunjavaju i ispisuju jednodimenzionalni dinamicki niz (korisnik unosi velicinu niza). 
I napisati rekurzivnu funkciju koja omogucava korisniku da unese broj a funkcija mu ispise najblizi element niza tome broju.*/

void rekurzivniUnos(int* niz, int vel, int i )
{
    if (i == vel)
        return;
    cout << "Element niza[" << i << "] = ";
    cin >> *(niz + i);
    rekurzivniUnos(niz, vel, i + 1);
}

void rekurzivniIspis(int* niz, int vel, int i)
{
    if (i>=vel)
        return;
    cout << *(niz + i) << endl;
    rekurzivniIspis(niz, vel, i + 1);
}

int najbliziTarget(int trazeniBroj, int* niz, int velicina, int najblizi = -1, int trenutniIndeks = 0)
{
    if (trenutniIndeks == velicina) 
    {
        return najblizi;
    }

    // Pronalazimo trenutno najbliži broj
    if (najblizi == -1 || abs(niz[trenutniIndeks] - trazeniBroj) < abs(najblizi - trazeniBroj)) 
    {
        najblizi = niz[trenutniIndeks];
    }

    // Ako smo pronašli traženi broj, odmah ga vraćamo
    if (niz[trenutniIndeks] == trazeniBroj) 
    {
        return trazeniBroj;
    }

    najbliziTarget(trazeniBroj, niz, velicina, najblizi, trenutniIndeks + 1);
} 

int main()
{
    int velicina;
    while (cout << "unesi velicinu", cin >> velicina, velicina < 2);

    int* niz = new int[velicina];

    rekurzivniUnos(niz,velicina,0);
    cout << "-------------------------------------------------" << endl;
    rekurzivniIspis(niz, velicina,0);

    int target;

    cout << "upisi broj koji zelite pronaci: ";
    cin >> target;

    cout << najbliziTarget(target,niz,velicina);

    delete[]niz;
    niz = nullptr;
}
