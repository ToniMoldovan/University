#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	//Initializare timp
	srand(time(NULL));
	int rasp;
	string raspuns;

	cout << "Introdu ce parte vrei: 1 sau 2: ";
	cin >> rasp;
	if (rasp == 1)
		goto partea1;
	if (rasp == 2)
		goto partea2;
	else
		return -1;


partea1:

	cout << "Incepe generarea de numere. (Apasa enter)" << endl;
	system("pause");

	while (true)
	{
		int numar_random = rand() % RAND_MAX + -RAND_MAX;
		cout << "Numar generat: " <<numar_random << ". Continui? (introdu da/nu)"<< endl;
		cin >> raspuns;

		if (raspuns == "nu")
		{
			cout << "Generarea s-a oprit." << endl;
			break;
		}
	}

	cout << "Continua exercitiul. (apasa enter)"; getchar();



partea2:

	ifstream input;
	input.open("input.txt");

	if (!input.is_open())
	{
		cout << "Eroare deschidere fisier.";
		return -2;
	}

	while (!input.eof())
	{
		int lim_stanga, lim_dreapta;

		input >> lim_stanga;
		input >> lim_dreapta;

		cout << "Interval gasit: [" << lim_stanga << ", " << lim_dreapta << "]" << ". Numere in interval: " << "\x1B[33m" << lim_dreapta - lim_stanga + 1 << "\033[0m\t\t" << endl;
	}



	return 0;
}
