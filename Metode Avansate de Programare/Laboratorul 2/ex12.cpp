#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;


int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	int numar_generat, contor = 0;
	int vector[100000];

	/* initialize random seed: */
	srand(time(NULL));


	while (true)
	{
		numar_generat = rand() % 40 + (-20); //intre -20 si +20
		if (numar_generat == 0)
		{
			break;
		}
		else
		{
			vector[contor] = numar_generat;
			contor++;
		}
	}

	//Sortare vector:
	qsort(vector, contor, sizeof(int), compare);
	for (int i = 0; i < contor; i++)
	{
		cout << "[" << i << "]: " << vector[i] << endl;
	}

	return 0;
}
