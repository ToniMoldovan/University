#include <iostream>;
#include <string>
using namespace std;

typedef unsigned int UINT;
struct Persoana
{
	char CNP[14];
	char nume[14];
	char prenume[14];
	char locnastere[14];
	char domiciliu[14];
};


Persoana add_data(int i);
void afisare_persoane(struct Persoana persoana[], int nr);
void afisare_alfabetica(struct Persoana persoana[], int nr);
void ordonare_varsta(struct Persoana persoana[], int nr);

int main()
{
	Persoana vpers[100];

	UINT numar_persoane;
	cout << "Cate persoane vrei sa fie: "; cin >> numar_persoane;

	for (int i = 0; i < numar_persoane; i++)
	{
		vpers[i] = add_data(i);
	}

	//Afisare ordine alfabetica
	//afisare_persoane(vpers, numar_persoane);
	system("cls");
	afisare_alfabetica(vpers, numar_persoane);
	cout << "\n";
	ordonare_varsta(vpers, numar_persoane);
	return 0;
}

Persoana add_data(int i)
{
	Persoana x;

	cout << "\n" << "Introdu date despre persoana cu numarul: " << "\x1B[32m" << i + 1 << "\033[0m\t\t" << endl;
	cout << "CNP: "; cin >> x.CNP;
	cout << "Nume: "; cin >> x.nume;
	cout << "Prenume: "; cin >> x.prenume;
	cout << "Locul nasterii: "; cin >> x.locnastere;
	cout << "Domiciliu: "; cin >> x.domiciliu;

	return x;
}


void afisare_persoane(struct Persoana persoana[], int nr)
{
	for (int i = 0; i < nr; i++)
	{
		cout << "\nAfisare persoana nr " << i + 1 << endl;
		cout << "Nume: " << persoana[i].nume << endl;
		cout << "Prenume: " << persoana[i].prenume << endl;
		cout << "CNP: " << persoana[i].CNP << endl;
		cout << "Locul nasterii: " << persoana[i].locnastere << endl;
		cout << "Domiciliu: " << persoana[i].domiciliu << endl;
		cout << "\n";
	}
}

void afisare_alfabetica(struct Persoana persoana[], int nr)
{
	Persoana temp;

	for (int i = 0; i < nr - 1; i++)
	{
		for (int j = i + 1; j < nr; j++)
		{
			if (strcmp(persoana[i].nume, persoana[j].nume) == 1)
			{
				temp = persoana[i];
				persoana[i] = persoana[j];
				persoana[j] = temp;
			}
		}
	}

	cout << "Aranjare alfabetica" << endl;
	for (int i = 0; i < nr; i++)
	{
		cout << persoana[i].nume << " " << persoana[i].prenume << endl;
	}
}

void ordonare_varsta(struct Persoana persoana[], int nr)
{
	Persoana temp;

	for (int i = 0; i < nr - 1; i++)
	{
		for (int j = i + 1; j < nr; j++)
		{
			if ((persoana[i].CNP[1] + persoana[i].CNP[2]) < (persoana[j].CNP[1] + persoana[j].CNP[2]))
			{
				temp = persoana[i];
				persoana[i] = persoana[j];
				persoana[j] = temp;
			}
		}
	}

	cout << "Aranjare descrescatoare dupa varsta" << endl;
	for (int i = 0; i < nr; i++)
	{
		cout << persoana[i].nume << " " << persoana[i].prenume << " " << persoana[i].CNP[1] << persoana[i].CNP[2] << endl;
	}
}
