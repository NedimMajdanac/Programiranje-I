#include<iostream>

using namespace std;

/*Napisati program koji rješava sljedeći problem. Date su firma A, B i C sa godišnjim prihodima: A - prihod 10M eura B - prihod 7M eura C - prihod 5M eura sa sljedećim stabilnim fiksnim godišnjim rastom prihoda za koji pretpostavljamo da se neće mijenjati A - 2.05% B - 2.80% C - 4.30% Potrebno je pronaći koja firma će prva prestići firmu A u godišnjem prihodu i za koliko godina će se to desit.*/

int main()
{
double firmaA = 10, firmaB = 7, firmaC = 5;
const double rastA = 2.05, rastB = 2.80, rastC = 4.30;


int brojGodina = 1;

while (firmaA > firmaB || firmaA > firmaC)
{
	firmaA = firmaA + (firmaA * rastA / 100.0);
	firmaB = firmaB + (firmaB * rastB / 100.0);
	firmaC = firmaC + (firmaC * rastC / 100.0);

	brojGodina++;
}

if (firmaB > firmaB)
	cout << "Firma B je prva prestigla firmu A za " << brojGodina << " godina." << endl;
else
	cout << "Firma C je prva prestigla firmu A za " << brojGodina << " godina." << endl;

cout << "prihod A: " << firmaA << endl;
cout << "prihod B: " << firmaB << endl;
cout << "prihod C: " << firmaC << endl;
}