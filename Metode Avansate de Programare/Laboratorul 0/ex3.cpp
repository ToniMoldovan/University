#include <iostream>
using namespace std;


void afisare_divizori(int n)
{
	cout << "Divizorii lui " << n << " sunt: ";

	for (int i = 1; i <= n; i++) // 12
	{
		if (n % i == 0)
		{
			cout << i << ", ";
		}
	}

}

int main()
{
	int x, contor = 0;

	while (contor < 3)
	{
		cout << "Introdu x: "; cin >> x;
		afisare_divizori(x);
		cout << "\n";
		contor++;
	}

}
