#include <iostream>
#include <math.h>
using namespace std;

void ecuatie(float a, float b, float c)
{
	float delta;

	if (a == 0)
	{
		cout << "a este egal cu 0. Nu se poate rezolva." << endl;
	}
	else
	{
		//Aflare delta
		delta = pow(b, 2) - 4 * a * c;
		cout << "Delta = " << delta << endl;

		//Verificare valori ale lui Delta pentru a trece sau nu mai departe:

		if (delta < 0)
		{
			cout << "[DELTA < 0]: Ecuatia nu are solutii reale." << endl;
		}

		if (delta == 0)
		{
			cout << "[DELTA = 0]: Ecuatia are 2 solutii reale si egale (x1 = x2): " << endl << (-b) / (2 * a) << endl;
		}
		if (delta > 0)
		{
			float x1, x2;

			x1 = (-b + sqrt(delta)) / (2 * a);
			x2 = (-b - sqrt(delta)) / (2 * a);

			cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl;
		}
		
	}

	


}

int main()
{
	float a, b, c, contor = 0;

	while (contor < 3)
	{
		cout << "Introdu a: "; cin >> a;
		cout << "Introdu b: "; cin >> b;
		cout << "Introdu c: "; cin >> c;
		ecuatie(a, b, c);
		cout << "\n";
		contor++;
	}


	return 0;
}