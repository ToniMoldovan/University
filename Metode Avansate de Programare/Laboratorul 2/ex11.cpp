#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int numarare_cuvinte(ifstream& input);
int numarare_propozitii(ifstream& input);
int numarare_litere(ifstream& input);


int main()
{
	ifstream input;
	input.open("input.txt");

	if (!input.is_open())
	{
		cout << "Eroare deschidere fisier.";
		return -1;
	}


	int nr_cuvinte = numarare_cuvinte(input);
	input.close();
	input.open("input.txt");
	int nr_prop = numarare_propozitii(input);
	input.close();
	input.open("input.txt");
	int nr_litere = numarare_litere(input);
	input.open("input.txt");

	cout << "Numarare finalizata." << endl;
	cout << "Cuvinte: " << nr_cuvinte << endl;
	cout << "Propozitii: " << nr_prop << endl;
	cout << "Litere: " << nr_litere << endl;
	return 0;
}


int numarare_cuvinte(ifstream& input)
{
	int cuvinte = 0;

	string cuvant;

	while (!input.eof())
	{

		if (input >> cuvant)
		{
			cuvinte++;
			continue;
		}

	}

	return cuvinte;
}


int numarare_propozitii(ifstream& input)
{
	int prop = 0;
	string propozitie;

	while (!input.eof())
	{
		input >> propozitie;
		int aux = propozitie.length();

		if ((propozitie[aux - 1] == '.') || (propozitie[aux - 1] == '!') || (propozitie[aux - 1] == '?'))
		{
			prop++;
			continue;
		}
	}

	return prop - 1;
}

int numarare_litere(ifstream& input)
{
	int litere = 0;
	string propozitie;

	while (!input.eof())
	{
		input >> propozitie;
		int temp = propozitie.length();
		litere += temp;
	}
	return litere;
}
