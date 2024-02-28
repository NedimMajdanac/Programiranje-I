#include <iostream>

using namespace std;

bool slozeni(int broj)
{
	for (int i = 0; i <= broj; i++)
		if (i % broj == 0)
			return true;
	return false;
}

int main()
{
int n1, n2, suma = 0, brojac = 0;
while (cout << "N1: ", cin >> n1, n1 < 10 || n1>100);
while (cout << "N2: ", cin >> n2, n2 < 500 || n2>2000);

for (int i = n1; i <= n2; i++)
{
	if (slozeni(i))
	{
		suma += i;
		brojac++;
	}
}
cout << "art sredina je: " << suma / brojac << endl;
}