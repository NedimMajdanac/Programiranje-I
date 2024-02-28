#include<iostream>

using namespace std;

bool isSavrsen(int broj)
{
	int suma = 0;
	for (int i = 1; i < broj; i++)
	{
		if (broj % i == 0)
			suma += i;
	}
	if (suma == broj)
		return true;
	return false;
}

int main()
{
	srand(time(NULL));
 	int n;
	float brojac = 0;
	while (cout << "N: ", cin >> n, n < 10 || 1000 < n);

	for (int i = 0; i <= n; i++)
	{
		int random = rand() % 1000 + 1;;
		if (isSavrsen(random))
			brojac++;
	}

	cout << "procenat savrsenih je: " << brojac / n * 100.0 << "%" << endl;
}