#include <iostream>
using namespace std;

void write_matrix(int** matrice, int rows, int col);
void read_matrix(int** matrice, int rows, int col);
void max_position_matrix(int** matrice, int rows, int col, int* max, int* pos_x, int* pos_y);
void free_matrix(int** matrice, int rows, int col);


int main()
{
	int rows, col, maxim = 0, pos_x = 0, pos_y = 0;

	int* adr_maxim = &maxim;
	int* adr_pos_x = &pos_x;
	int* adr_pos_y = &pos_y;

	cout << "raunduri: "; cin >> rows;
	cout << "coloane: "; cin >> col;

	//Creare dinamica a matricei

	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[col];
	}

	//Adaugare elemente in matrice:
	write_matrix(matrix, rows, col);

	//Afisare matrice
	read_matrix(matrix, rows, col);

	//Gasire maxim si pozitie:
	max_position_matrix(matrix, rows, col, adr_maxim, adr_pos_x, adr_pos_y);
	cout << "Maximul: " << *adr_maxim << endl;
	cout << "Pozitia: [" << *adr_pos_x << "][" << *adr_pos_y << "]" << endl;

	free_matrix(matrix, rows, col);


	return 0;
}


void write_matrix(int** matrice, int rows, int col)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << "Element: [" << i << "][" << j << "] = ";
			cin >> matrice[i][j];
		}
	}
	cout << endl;

}

void read_matrix(int** matrice, int rows, int col)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << matrice[i][j] << " ";
		}
		cout << endl;
	}
}

void max_position_matrix(int** matrice, int rows, int col, int* max, int* pos_x, int* pos_y)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{

			if (*max < matrice[i][j])
			{
				*max = matrice[i][j]; //elementul de pe matrice[i][j] = 8, altfel spus, elementul de pe matrice[3][6] = 8
				*pos_x = i; // i = 3 rand
				*pos_y = j; // j = 6 coloana
			}

		}
	}

	cout << "Am gasit maxim si pozitiile acestuia cu succes." << endl;

}

void free_matrix(int** matrice, int rows, int col)
{
	for (int i = 0; i < rows; i++)
	{

		for (int j = 0; j < col; j++)
		{

			delete[] matrice;

		}

	}

	matrice = NULL;

}
