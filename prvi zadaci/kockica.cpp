#include<iostream>
#include<iostream>

/*Napisati program koji će omogućiti korisniku unos broja n ( 10 <= n <= 1000). Zatim simulirati n bacanja kockice (kockica ima 6 strana i na tim stranicama su brojevi 1-6). Simuliranje bacanja svake kockice ostvariti funkcijom rand() % 6 + 1. Izračunati statičke podatke u kojem procentu ukupnog bacanja se dobiva svaki od mogućih brojeva 1-6. Obavezno koristiti switch statement za zbrajanje rezultata bacanja kockice.*/

int main()
{
int slucaj1 = 0, slucaj2 = 0, slucaj3 = 0, slucaj4 = 0, slucaj5 = 0, slucaj6 = 0; // za pojavljivanje stranica
int brojBacanja = 0;

for (int i = 0; i <= unos; i++)
{
	int kocka = rand() % 6 + 1;

	switch (kocka)
	{
	case 1: {
		slucaj1++;
	} break;

	case 2: {
		slucaj2++;
	} break;

	case 3: {
		slucaj3++;
	} break;
	case 4: {
		slucaj4++;
	} break;
	case 5: {
		slucaj5++;
	} break;
	case 6: {
		slucaj6++;
	} break;

	default: {
		cout << "restartujte program..." << endl;
	}
	}
	brojBacanja++;
}

cout << endl;
cout << "Procenat za broj 1: " << round(100 * double(slucaj1) / unos * 100.0) / 100.0 << "%" << endl;
cout << "Procenat za broj 2: " << round(100 * double(slucaj2) / unos * 100.0) / 100.0 << "%" << endl;
cout << "Procenat za broj 3: " << round(100 * double(slucaj3) / unos * 100.0) / 100.0 << "%" << endl;
cout << "Procenat za broj 4: " << round(100 * double(slucaj4) / unos * 100.0) / 100.0 << "%" << endl;
cout << "Procenat za broj 5: " << round(100 * double(slucaj5) / unos * 100.0) / 100.0 << "%" << endl;
cout << "Procenat za broj 6: " << round(100 * double(slucaj6) / unos * 100.0) / 100.0 << "%" << endl;

}