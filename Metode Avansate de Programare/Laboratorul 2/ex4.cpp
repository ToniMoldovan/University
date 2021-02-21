#include <iostream>
using namespace std;
/// <summary>
/// Exercitiul nu e complet
/// </summary>

typedef struct Disciplina
{
	char denumire[100];
	int nota;
};

typedef struct Student
{
	char nume[50];
	char prenume[40];
	Disciplina d[10];
	float medie;
};

Student citireStud(int nr_stud, int nr_disc);
Disciplina citireDisc(int nr);


int main()
{

	Student vectorStud[30];
	Disciplina discipline;
	//Citire numar studenti
	int nrStud, nrDisc;
	cout << "Introdu numarul de discipline: "; cin >> nrDisc;
	cout << "Introdu numarul de studenti: "; cin >> nrStud;
	discipline = citireDisc(nrDisc);

	for (int i = 0; i < nrStud; i++)
	{
		cout << "Introdu date pentru studentul cu numarul " << i + 1 << ":" << endl;
		vectorStud[i] = citireStud(nrStud);
		
	}

	return 0;
}
