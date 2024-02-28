#include<iostream>
#include<cmath>

using namespace std;

struct automobil
{
	char* markaVozila;
	char* naziv;
	char* tipVozila;
	float* potrosnjaGoriva;

	automobil()
	{
		markaVozila = new char[15];
		naziv = new char[10];
		tipVozila = new char;
		potrosnjaGoriva = new float;
	}
	~automobil()
	{
		delete[]markaVozila;
		markaVozila = nullptr;

		delete[]naziv;
		naziv = nullptr;

		delete[]tipVozila;
		tipVozila = nullptr;

		delete[]potrosnjaGoriva;
		potrosnjaGoriva = nullptr;
	}

};

void unosAutomobil(automobil**, int, int);
void ispisAutomobil(automobil**, int, int);
void najvecaPotrosnja(automobil**, int, int);
void potrosnjaTipaC(automobil**, int, int);
void dealokacijaAutomobil(automobil**&, int);

int main()
{
	int red, kolona;
	cout << "Unesite broj redova: ";
	cin >> red;
	cout << "Unesite broj kolona: ";
	cin >> kolona;

	automobil** matrix = new automobil * [red];
	for (int i = 0; i < red; i++)
	{
		*(matrix + i) = new automobil[kolona];
	}

	unosAutomobil(matrix, red, kolona);
	ispisAutomobil(matrix, red, kolona);

	najvecaPotrosnja(matrix, red, kolona);
	potrosnjaTipaC(matrix, red, kolona);

	dealokacijaAutomobil(matrix, red);
}

void unosAutomobil(automobil** matrica, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin.ignore();
			cout << "unesite marku vozila: ";
			cin.getline((*(matrica + i) + j)->markaVozila, 15);

			cout << "unesite naziv automobila: ";
			cin.getline((*(matrica + i) + j)->naziv, 10);

			do
			{
				cout << "Unesite tip vozila (A, B ili C): ";
				cin >> *(*(matrica + i) + j)->tipVozila;
			} while (*(*(matrica+i)+j)->tipVozila!='A'&& *(*(matrica + i) + j)->tipVozila != 'B'&& *(*(matrica + i) + j)->tipVozila != 'C');

			cout << "Unesite potrosnju: ";
			cin >> *(*(matrica + i) + j)->potrosnjaGoriva;
			cout << "-------------------------------------------------------" << endl;
		}
	}
}

void ispisAutomobil(automobil** matrica, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << "marka vozila: " << *(*(matrica + i) + j)->markaVozila << endl;
			cout << "naziv vozila: " << *(*(matrica + i) + j)->naziv << endl;
			cout << "tip vozila: " << *(*(matrica + i) + j)->tipVozila << endl;
			cout << "potrosnja vozila: " << *(*(matrica + i) + j)->potrosnjaGoriva << endl;
		}
	}
}

void najvecaPotrosnja(automobil** matrica, int rows, int columns)
{
	float* najveciProsjek = new float[rows] {0.0f};

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			*(najveciProsjek + i) += *(*(matrica + i) + j)->potrosnjaGoriva;
		}
		*(najveciProsjek + i) /= columns;
	}

	int index = 0;

	for (int i = 0; i < rows; i++)
	{
		if (*(najveciProsjek + i) > *(najveciProsjek + index))
		{
			index = i;
		}
	}

	cout << "Firma sa najvecom potrosnjom goriva je na index-u: " << index << " ima sljedece podatke: " << endl;

	for (int j = 0; j < columns; j++)
	{
		cout << "marka vozila je: " << *(*(matrica + index) + j)->markaVozila << endl;
		cout << "naziv automobla je: " << *(*(matrica + index) + j)->naziv << endl;
		cout << "tip vozila je: " << *(*(matrica + index) + j)->tipVozila <<endl;
		cout << "potrosnja goriva je: " << *(*(matrica + index) + j)->potrosnjaGoriva << endl;
		cout << "-----------------------------------------------------------------" << endl;
	}
	delete[]najveciProsjek;
}

void potrosnjaTipaC(automobil** matrica, int rows, int columns)
{
	float potrosnjaC = 0.0f;
	int brojac = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (*(*(matrica + i) + j)->tipVozila == 'C')
			{
				potrosnjaC += *(*(matrica + i) + j)->potrosnjaGoriva;
				brojac++;
			}
		}
	}
	cout << "-----------------------------------------------------------------" << endl;
	if (brojac != 0)
		cout << "Prosjecna potrosnja kod C je: " << potrosnjaC / float(brojac) << endl;
	else
		cout << "Prosjecna potrosnja kod C je: " << potrosnjaC << endl;

}

void  dealokacijaAutomobil(automobil**& matrica, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] * (matrica + i);
	}
	delete[]matrica;
	matrica = nullptr;
}

