#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


void verificare_fisier(ifstream &file);

int main()
{
	//Deschid fisierul input.txt in modul de input
	ifstream input;
	input.open("input.txt");

	//Verifica daca exista sau nu fisierul
	verificare_fisier(input);

	vector <string> text;
	string linie;

	while (!input.eof())
	{
		getline(input, linie); //Citim fiecare linie
		text.push_back(linie); //O adaugam la final in vector
	}

	cout << "Copiere linii din fisier in vector " << "\x1B[32m[OK]\033[0m\t\t" << endl; //log

	//Deschid fisierul backup in mod de write
	ofstream backup;
	backup.open("backup.txt");

	for (int i = 0; i < text.size(); i++)
	{
		backup << i+1 << ". " << text[i] << endl;
	}

	cout << "Copierea continutului in noul fisier " << "\x1B[32m[OK]\033[0m\t\t" << endl;

	input.close();
	backup.close();


	//Sterg primul fisier
	remove("input.txt");

	//Redenumesc al doilea fisier
	rename("backup.txt", "input.txt");

	cout << "Redenumire fisier " << "\x1B[32m[OK]\033[0m\t\t" << endl;
	system("pause");

	return 0;
}

void verificare_fisier(ifstream &file)
{
	if (!file.is_open())
	{
		cout << "Fisierul input.txt nu a fost gasit. " << "\x1B[31m[OOPS]\033[0m\t\t" << endl;
	}
	else
	{
		cout << "Fisierul a fost gasit " << "\x1B[32m[OK]\033[0m\t\t" << endl;

	}
}

using namespace std;