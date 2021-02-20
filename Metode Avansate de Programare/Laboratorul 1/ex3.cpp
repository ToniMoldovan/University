#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	ifstream input;
	input.open("input.txt");

	ofstream output;

	string text;
	vector <string> second_text;


	//Verificare daca exista fisierul

	if (!input.is_open())
	{
		cout << "Fisierul nu se poate deschide. Nu exista cel mai probabil." << endl;
		system("pause");
		return -1;
	}
	
	cout << "Acum se rearanjeaza fisierele" << endl;

	while (!input.eof())
	{
		getline(input, text);
		second_text.push_back(text);
	}


	sort(second_text.begin(), second_text.end()); //aranjare alfabetica

	output.open("output.txt"); //Deschidere fisier pentru write
	
	for (int i = 0; i < second_text.size(); i++)
	{
		output << i << ". " << second_text[i] << "\n";
	}
	
	/*
	for (int i = 0; i < second_text.size(); i++)
	{
		cout << second_text[i] << endl;
	}
	*/

	input.close();
	output.close();

	return 0;
}