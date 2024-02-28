#include <iostream>
#include <cmath>

using namespace std;

struct vozilo 
{
	char* markaVozila;
	char* brojSasije;
	char* tipVozila;
	int* kubnihCM;

	vozilo() 
	{
		markaVozila = new char[15];
		brojSasije = new char[10];
		tipVozila = new char;
		kubnihCM = new int;
	}

	~vozilo() 
	{
		delete[]markaVozila;
		markaVozila = nullptr;

		delete[]brojSasije;
		brojSasije = nullptr;

		delete tipVozila;
		tipVozila = nullptr;

		delete kubnihCM;
		kubnihCM = nullptr;
	}
};

void unosPodataka(vozilo**, int, int);
void ispisPodataka(vozilo**, int, int);
int najvecaKubikaza(vozilo**, int, int);
void prosjecnaKubikaza(vozilo**, int, int);
void dealokacijaVozila(vozilo**&, int);

int main()
{
vozilo** matrix = new vozilo * [red];
	for (int i = 0; i < red; i++)
	{
		*(matrix + i) = new vozilo[kolona];
	}

	unosPodataka(matrix, red, kolona);
	cout << endl;
	ispisPodataka(matrix, red, kolona);
	cout << endl;

	cout << "firma sa najvecom prosjecnom kubikazom je na indeksu: " << najvecaKubikaza(matrix, red, kolona) << endl;

	cout << "Uneseni podaci firme sa najvecom kubikazom su: " << endl;
	int indeks = najvecaKubikaza(matrix, red, kolona);

	for (int j = 0; j < kolona; j++)
	{
		cout << "Marka vozila: " << *(*(matrix + indeks) + j)->markaVozila << endl;
		cout << "broj sasije vozila: " << *(*(matrix + indeks) + j)->brojSasije << endl;
		cout << "tip vozila je: " << *(*(matrix + indeks) + j)->tipVozila << endl;
		cout << "kubna potrosnja vozila je: " << *(*(matrix + indeks) + j)->kubnihCM << endl;
	}
	cout << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	prosjecnaKubikaza(matrix, red, kolona);

	dealokacijaVozila(matrix, red);
}

void unosPodataka(vozilo** matrica, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin.ignore();
			cout << "Unesite marku vozila: ";
			cin.getline((*(matrica + i) + j)->markaVozila, 15);
			cout << "Unesite broj sasije vozila: ";
			cin.getline((*(matrica + i) + j)->brojSasije, 10);

			do
			{
				cout << "Unesite tip vozila (A,B ili C): ";
				cin >> *(*(matrica + i) + j)->tipVozila;
			} while (*(*(matrica + i) + j)->tipVozila != 'A' && *(*(matrica + i) + j)->tipVozila != 'B' && *(*(matrica + i) + j)->tipVozila != 'C');

			cout << "Unesite broj kubne potrosnje vozila: ";
			cin >> *(*(matrica + i) + j)->kubnihCM;

			cout << "---------------------------------------------------------------------------" << endl;

		}
	}
}

void ispisPodataka(vozilo** matrica, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << "Marka vozila je: " << *(*(matrica + i) + j)->markaVozila << endl;
			cout << "Broj sasije je: " << *(*(matrica + i) + j)->brojSasije << endl;
			cout << "Tip vozila je: " << *(*(matrica + i) + j)->tipVozila << endl;
			cout << "Kubna potrosnja vozila je: " << *(*(matrica + i) + j)->kubnihCM << endl;
		}
	}
}

int najvecaKubikaza(vozilo** matrica, int rows, int columns)
{
	float* najvecaKUB = new float[rows] {0.0f};

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			*(najvecaKUB + i) += *(*(matrica + i) + j)->kubnihCM;
		}
		*(najvecaKUB + i) /= columns;
	}

	int indexNajveceg = 0;

	for (int i = 0; i < rows; i++)
	{
		if (*(najvecaKUB + i) > *(najvecaKUB + indexNajveceg))
		{
			indexNajveceg = i;
		}
	}

	delete[]najvecaKUB;
	najvecaKUB = nullptr;

	return indexNajveceg;
}

void prosjecnaKubikaza(vozilo** matrica, int rows, int columns)
{
	float prosjekA = 0.0f;
	float prosjekB = 0.0f;
	float prosjekC = 0.0f;
	int a = 0, b = 0, c = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (*(*(matrica + i) + j)->tipVozila == 'A')
			{
				prosjekA += *(*(matrica + i) + j)->brojSasije;
				a++;
			}
			else if (*(*(matrica + i) + j)->tipVozila == 'B')
			{
				prosjekB += *(*(matrica + i) + j)->brojSasije;
				b++;
			}
			else if (*(*(matrica + i) + j)->tipVozila == 'C')
			{
				prosjekC += *(*(matrica + i) + j)->brojSasije;
				c++;
			}
		}
	}
	if (a != 0) { prosjekA /= a; }
	if (b != 0) { prosjekB /= b; }
	if (c != 0) { prosjekC /= c; }
}

void dealokacijaVozila(vozilo**& matrica, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] * (matrica + i);
	}
	delete[]matrica;
	matrica = nullptr;
}

