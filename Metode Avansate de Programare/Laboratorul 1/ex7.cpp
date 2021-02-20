#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void gasire_numere(ifstream& input, ofstream& output);
int cauta_numar(string linie, int &pozitie);

int main()
{
	ifstream input;
	input.open("fisier1.txt");

	ofstream output;
	output.open("fisier2.txt");

	//Verificare fisier
	if (!input.is_open())
	{
		cout << "Fisierul nu a fost gasit. " << "\x1B[31m[OOPS]\033[0m\t\t" << endl;
		return -1;
	}
	else
	{
		cout << "Fisierul a fost gasit " << "\x1B[32m[OK]\033[0m\t\t" << endl;
	}


	gasire_numere(input, output);


	return 0;
}

void gasire_numere(ifstream& input, ofstream& output)
{

	string temp;
	int* numere = new int[100];
	int suma = 0, counter = 0;
	int produs = 1;
	int aux = 0;


	while (!input.eof())
	{
		getline(input, temp); //citeste fiecare linie din input in temp
		for (int i = 0; i < temp.size(); i++) 
		{
			if (temp[i] >= '0' && temp[i] <= '9')
			{
				aux = cauta_numar(temp, i);
				suma += aux;
				produs *= aux;
				numere[counter] = aux;
				counter++;
			}
		}
	}


	/*for (int i = 0; i < counter; i++)
	{
		cout << "[" << i << "] = " << numere[i] << endl;
	}*/
	
	bool sem;
	int aux_bubble_sort;
	do
	{
		sem = false;
		for (int i = 0; i < counter - 1; i++)
		{
			for (int j = 0; j < counter - 1; j++)
			{
				if (numere[j] > numere[j + 1])
				{
					sem = true;
					aux_bubble_sort = numere[j];
					numere[j] = numere[j + 1];
					numere[j + 1] = aux_bubble_sort;
				}
			}
		}
	} while(sem == true);

	output << "Suma = " << suma << endl;
	output << "Produs = " << produs << endl;
	output << "Lista numere in ordine crescatoare: ";
	for (int i = 0; i < counter; i++)
	{
		output << numere[i] << " ";
	}

	cout << "Noul fisier a fost scris. " << "\x1B[32m[OK]\033[0m\t\t" << endl;
	

	delete[] numere;
	numere = NULL;
	input.close();
	output.close();

}

int cauta_numar(string linie, int &pozitie)
{
	string aux_string = "";

	while (linie[pozitie] <= '9' && linie[pozitie] >= '0')
	{
		aux_string += linie[pozitie];
		pozitie++;
	}

	return stoi(aux_string); //stoi() transforma la nivel de bit string -> integer
}
