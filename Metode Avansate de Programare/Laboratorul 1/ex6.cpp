#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{

	ifstream input;
	input.open("fisier1.txt");

	//Verificare fisier
	if (!input.is_open())
	{
		cout << "Fisierul nu a fost gasit. " << "\x1B[31m[OOPS]\033[0m\t\t" << endl;
	}
	else
	{
		cout << "Fisierul a fost gasit " << "\x1B[32m[OK]\033[0m\t\t" << endl;
	}

	ofstream output;
	output.open("fisier2.txt", ios_base::app);
	
	system("pause");

	string text;

	cout << "Concatenare in curs.. " << endl;
	while (!input.eof())
	{
		getline(input, text);
		output << text;
	}
	cout << "Concatenare realizata cu succes " << "\x1B[32m[OK]\033[0m\t\t" << endl;

	fcloseall();

	return 0;
}