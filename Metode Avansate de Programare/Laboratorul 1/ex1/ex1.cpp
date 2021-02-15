#define _CRT_SECURE_NO_WARNINGS
#define MAX 1024
#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
using namespace std;

void copiere(FILE* input, FILE* output);

int main()
{
	FILE* file_in, * file_out;

	file_in = fopen("E:\\Facultate\\Semestrul 2\\Modul 3\\MAP\\Laboratorul1\\Ex1\\ex1_plin.txt", "rt");
	file_out = fopen("E:\\Facultate\\Semestrul 2\\Modul 3\\MAP\\Laboratorul1\\Ex1\\ex1_nou.txt", "wt");

	//Verificare daca exista

	if (file_in == NULL)
	{
		printf("[LOG]: Fisierul de intrare nu a fost gasit sau nu exista.\n");
		getchar();
		return -1;
	}
	else if (file_out == NULL)
	{
		printf("[LOG]: Fisierul de iesire nu a fost gasit sau nu exista.\n");
		getchar();
		return -1;
	}

	printf("[LOG]: Ambele fisiere au fost deschise cu succes.\n");
	system("pause");

	//Incepere copiere fisiere
	copiere(file_in, file_out);

	_fcloseall(); // Inchidere stream-uri

	return 0;
}

void copiere(FILE* input, FILE* output)
{
	//Definire buffer
	char* buffer = new char[MAX]; //citeste maxim 1024 octeti'
	int caractere_citite;

	while (fgets(buffer, MAX, input) != NULL)
	{
		fputs(buffer, output);
	}

	printf("[LOG]: Copiere finalizata cu succes!\n");
	system("pause");

}
