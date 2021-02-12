#include <iostream>
using namespace std;

void write_matrix(int** matrice, int n);
void read_matrix(int** matrice, int n);
void free_matrix(int** matrice, int n);

void first_diagonal(int** matrice, int n);
void second_diagonal(int** matrice, int n);


int main()
{
	int n;

	cout << "Introdu n: "; cin >> n;

	//Creare dinamica a matricei

	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}

	//Adaugare elemente in matrice:
	write_matrix(matrix, n);

	//Afisare matrice
	read_matrix(matrix, n);
	cout << endl;


	//Diagonala principala
	first_diagonal(matrix, n);
	cout << endl;


	//Diagonala secundara
	second_diagonal(matrix, n);


	free_matrix(matrix, n);

	
	return 0;
}


void first_diagonal(int** matrice, int n)
{
	cout << endl << "Diagonala Principala" << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				cout << matrice[i][j] << "\t";
			}
		}
	}

	cout << endl;
}


void second_diagonal(int** matrice, int n)
{
	cout << endl << "Diagonala Secundara" << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			if ((i + j) == (n - 1))
			{
				cout << matrice[i][j] << "\t";
			}
		}
	}
	
	cout << endl;
}




void write_matrix(int** matrice, int n)
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Element: [" << i << "][" << j << "] = ";
			cin >> matrice[i][j];
		}
	}
	cout << endl;
	
}

void read_matrix(int** matrice, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrice[i][j] << " ";
		}
		cout << endl;
	}
}

void free_matrix(int** matrice, int n)
{
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{

			delete[] matrice;

		}

	}
	
	matrice = NULL;

}
