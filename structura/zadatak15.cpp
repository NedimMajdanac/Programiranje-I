#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*struktura Book:
char *imeKnjige;
char *imeAutora;
int brojOcjena; - velicina niza ocjena
int *ocjena; - niz ocjena
Napraviti funkciju u stukturi za unos svih podataka o knjizi, za ispis istih, za dealokaciju svih dinamickih varijabli, i za racunanje
prosjeka ocjena u toj knjizi. Program treba da ponudi korisniku da unese velicinu niza.
Napraviti dinamicki niz unesene velicine, koji ce sadrzavat objekte strukture Book.
Ponuditi korisniku da upise podatke o knjigama u nizu, pa onda i ispisati te podatke u konzolu.
Za svaku knjigu treba ispisati broj rijeci u imenu knjige (preporucljivo je napraviti posebnu globalnu funkciju za to).
Nakon toga program treba ispisati koji je index knjige sa najvecim prosjekom ocjena.*/

struct book {
    char* imeKnjige;
    char* imeAutora;
    int brojOcjena;
    int* ocjena;

    void unos()
    {
        char tempKnjiga[50];
        cout << "upisite ime knjige: ";
        cin.getline(tempKnjiga,sizeof tempKnjiga);
        int velicinaKnjige = strlen(tempKnjiga) + 1;
        imeKnjige = new char[velicinaKnjige];
        strcpy_s(imeKnjige,velicinaKnjige,tempKnjiga);

        char tempAutor[50];
        cout << "upiste ime autora: ";
        cin.getline(tempAutor, sizeof tempAutor);
        int velicinaAutora = strlen(tempAutor) + 1;
        imeAutora = new char[velicinaAutora];
        strcpy_s(imeAutora, velicinaAutora, tempAutor);

        cout << "unesite broj ocjena: ";
        cin >> brojOcjena;
        ocjena = new int[brojOcjena];
        for (int i = 0; i < brojOcjena; i++)
        {
            cout << "ocjena[" << i << "] = ";
            cin >> ocjena[i];
        }
        cin.ignore();
    }

    void ispis()
    {
        cout << "---------------------------------------------------------------" << endl;
        cout << "Ime knjige je: " << imeKnjige << endl;
        cout << "Ime autora je: " << imeAutora << endl;
        cout << "Ocjene: " << endl;
        for (int i = 0; i < brojOcjena; i++)
        {
            cout << "Ocjena[" << i << "] = " << ocjena[i] << endl;
        }
    }

    void dealokacija()
    {
        delete[]imeKnjige;
        imeKnjige = nullptr;

        delete[]imeAutora;
        imeAutora = nullptr;

        delete[]ocjena;
        ocjena = nullptr;
    }

};

int indexNajveciProsjek(book* niz, int vel)
{
    float* prosjek = new float[vel] {0.0f};
    int index = 0;
    for (int i = 0; i < vel; i++)
    {
        int broj = niz[i].brojOcjena;
        for (int j = 0; j < broj; j++)
        {
            prosjek[i] += niz[i].ocjena[i];
        }
        prosjek[i] /= broj;
        if (i > 0)
        {
            if (prosjek[i] < prosjek[index])
                index = i;
        }
    }
    delete[]prosjek;
    return index;
}



int main()
{
    int velicina;
    cout << "Upisite velicinu: ";
    cin >> velicina;
    cin.ignore();

    book* niz = new book[velicina];

    for (int i = 0; i < velicina; i++)
    {
        niz[i].unos();
    }
    for (int i = 0; i < velicina; i++)
    {
        niz[i].ispis();
    }
    for (int i = 0; i < velicina; i++)
    {
        niz[i].dealokacija();
    }
    cout << "najveci index: " << indexNajveciProsjek(niz, velicina) << endl;
    delete[]niz;
    niz = nullptr;
}