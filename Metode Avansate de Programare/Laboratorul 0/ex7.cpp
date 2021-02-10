#include <iostream>
using namespace std;


void afisare_piramida(int n)
{

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j;
		}
		cout << endl;
	}

}

int main()
{
	int x, contor = 0;

	while (contor < 3)
	{
		cout << "Introdu x: "; cin >> x;
		afisare_piramida(x);
		cout << endl;
		contor++;
	}


	return 0;
}