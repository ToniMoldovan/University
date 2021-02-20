#define _CRT_SECURE_NO_WARNINGS
#define MAX 1024
#include <iostream>
#include <stdio.h>
#include <string.h>

int word_count(FILE* input, char cuvant[]);

int main()
{
	char cuvant_dorit[50];

	printf("Introdu cuvantul pe care doresti sa il gasesti: ");
	gets_s(cuvant_dorit);

	//printf("Cuvant dorit: %s", cuvant_dorit);

	//Deschidere fisier
	FILE* input = fopen("input.txt", "rt"); //deschidere in mod de citire

	//Verificare daca exista sau nu
	if (input == NULL)
	{
		printf("[LOG]: Fisierul input.txt nu a fost gasit sau nu exista. ");
		system("pause");
		return -1;
	}

	printf("Cuvantul apare de: %d", word_count(input, cuvant_dorit)); //Apelare functie de numarare

	return 0;

}

int word_count(FILE* input, char cuvant[])
{
	int aparitii_cuvant = 0;
	int lungime_cuvant = strlen(cuvant);
	printf(" lungime cuvant: %d", lungime_cuvant);
	printf(" ");
	char buffer[MAX]; //citeste maxim 1024 octeti'
	char* pos;

	int index;

	// Read line from file till end of file.
	while ((fgets(buffer, MAX, input)) != NULL)
	{
		index = 0;

		// Find next occurrence of word in buffer
		while ((pos = strstr(buffer + index, cuvant)) != NULL)
		{
			// Index of word in buffer is
			// Memory address of pos - memory
			// address of buffer.
			index = (pos - buffer) + 1;

			aparitii_cuvant++;
		}
	}

	return aparitii_cuvant;

}