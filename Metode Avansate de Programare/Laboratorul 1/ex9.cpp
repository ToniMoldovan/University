#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

struct Angajat
{
	char nume[30], prenume[30];
	unsigned salariu;
};

int main()
{
	Angajat persoana[10];

	ifstream input;
	input.open("input.txt");

	ofstream output;
	output.open("output.txt");

	if (!input.is_open())
	{
		cout << "Eroare fisier";
		return -1;
	}

	int numar_randuri;

	input >> numar_randuri; //citesc primul rand ca sa vad cate elemente sunt

	//Extragere date din fisier > structura
	while (!input.eof())
	{
		for (int i = 0; i < numar_randuri; i++)
		{
			input >> persoana[i].nume;
			input >> persoana[i].prenume;
			input >> persoana[i].salariu;
		}
	}

	input.close();

	//Afisare date
	for (int i = 0; i < numar_randuri; i++)
	{
		cout << persoana[i].nume << endl;
		cout << persoana[i].prenume << endl;
		cout << persoana[i].salariu << endl;
		cout << endl;
	}
	
	//Diminuare salariu cu 25%
	for (int i = 0; i < numar_randuri; i++)
	{
		output << persoana[i].nume << " " << persoana[i].prenume << " " << (persoana[i].salariu * 25) / 100 << endl;
	}

	output.close();
	//Medie aritmetica dupa si inainte de diminuare + diferenta

	int suma = 0;
	for (int i = 0; i < numar_randuri; i++)
	{
		suma += persoana[i].salariu;
	}

	int medie_aritmetica =  suma / numar_randuri;

	int suma_diminuata = 0;
	for (int i = 0; i < numar_randuri; i++)
	{
		suma_diminuata += (persoana[i].salariu * 25) / 100;
	}
	int medie_aritmetica_dim = suma_diminuata / numar_randuri;
	float diferenta = (float(medie_aritmetica) - float(medie_aritmetica_dim)) / abs(float(medie_aritmetica));



	cout << "Medie aritmetica inainte de diminuare: " << medie_aritmetica << endl;
	cout << "Medie aritmetica dupa diminuare: " << medie_aritmetica_dim << endl;
	cout << "Diferenta dintre ele: " << int(diferenta * 100) << "%" << endl;

	return 0;
}