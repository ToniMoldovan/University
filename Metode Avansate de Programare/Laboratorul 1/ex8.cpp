#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream input;
	input.open("input.txt");

	ofstream output;
	output.open("temp.txt");

	//Verificare deschidere fisier
	if (!input.is_open())
	{
		cout << "Deschiderea fisierului a esuat. " << "\x1B[31m[OOPS]\033[0m\t\t" << endl;
		return -1;
	}

	char line[1024];
	char* token;

	cout << "Incep tokenizarea..." << endl;
	while (!input.eof())
	{
		input.getline(line, 1024);
		token = strtok(line, " .,");
		while (token != NULL)
		{
			output << token << endl;
			token = strtok(NULL, " .,");
		}
	}

	token = NULL;
	output.close();
	input.close();
	cout << "Tokenizare finalizata " << "\x1B[32m[OK]\033[0m\t\t" << endl;

	ifstream input2;
	input2.open("temp.txt");

	if (!input2.is_open())
	{
		cout << "Deschiderea fisierului a esuat. " << "\x1B[31m[OOPS]\033[0m\t\t" << endl;
		return -1;
	}

	int maxim = 0, minim = 999;
	char cuvant_temp[256], cuvant_lung[256], cuvant_temp2[256],cuvant_scurt[256];

	while (!input2.eof())
	{
		input2.getline(cuvant_temp, 256);
		input2.getline(cuvant_temp2, 256);

		if (maxim < strlen(cuvant_temp))
		{
			maxim = strlen(cuvant_temp);
			strncpy(cuvant_lung, cuvant_temp, 256);
		}

		if (minim > strlen(cuvant_temp2) && strlen(cuvant_temp2) >= 1)
		{
			minim = strlen(cuvant_temp2);
			strncpy(cuvant_scurt, cuvant_temp2, 256);
		}
	}

	input2.close();
	remove("temp.txt");

	cout << "Cel mai lung cuvant: " << cuvant_lung << " [" << maxim << "] litere" << endl;
	cout << "Cel mai scurt cuvant: " << cuvant_scurt << " [" << minim << "] litere" << endl;
	
	return 0;
}