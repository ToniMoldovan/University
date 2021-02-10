#include <iostream>
#include <string>
using namespace std;

int vocals(string propozitie)
{

	int vocale_gasite = 0;
	int lungime_prop = propozitie.length();

	for (int i = 0; i < lungime_prop; i++)
	{
		if (propozitie[i] == 'a' or propozitie[i] == 'e' or propozitie[i] == 'i' or propozitie[i] == 'o' or propozitie[i] == 'u')
		{
			vocale_gasite++;
		}
	}

	if (vocale_gasite == 0)
	{
		cout << "Nu au fost gasite vocale." << endl;
	}

	return vocale_gasite;
}

int main()
{

	string propozitie;
	int contor = 0, nr_vocale;

	while (contor < 3)
	{
		cout << "Introdu propozitia ta: "; getline(cin, propozitie);
		//cout << propozitie; //for testing purposes :))
		nr_vocale = vocals(propozitie);
		cout << "Numar vocale: " << nr_vocale << endl;
		contor++;
	}
	

}