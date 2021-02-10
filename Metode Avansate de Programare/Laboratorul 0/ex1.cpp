#include <iostream>
using namespace std;


void afisare_numere(int x)
{
	for (int i = 1; i <= x; i++)
	{
		cout << i << " ";
	}

	cout << "\n";

}

int main()
{
	int n, contor = 0;

	while (contor < 3) //ca sa imi apeleze de 3 ori functia, cum cere in exercitiu
	{
		cout << "Introdu n: "; cin >> n;
		afisare_numere(n);
		contor++;
	}


	return 0;
}
