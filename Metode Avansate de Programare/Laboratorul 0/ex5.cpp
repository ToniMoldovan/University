#include <iostream>
#include <math.h>       /* pow */
using namespace std;

float aria_patratului(float l)
{
	float aria;

	aria = pow(l, 2);


	return aria;
}

int main()
{
	float l, rezultat;
	int contor = 0;

	while (contor < 3)
	{
		cout << "Introdu latura: "; cin >> l;
		rezultat = aria_patratului(l);
		cout << "Aria este: " << rezultat << "\n";
		contor++;
	}

	return 0;
}