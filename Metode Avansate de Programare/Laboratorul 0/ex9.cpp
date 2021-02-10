#include <iostream>
using namespace std;

//Declarare functii
void show_matrix(int** matrix, int row, int col);

void read_matrix(int** matrix, int row, int col);


int main()
{
	int row, col;


	cout << "Introdu randuri: "; cin >> row;

	cout << "Introdu coloane: "; cin >> col;

	int** matrix = new int* [row];

	for (int i = 0; i < row; i++) 
	{
		matrix[i] = new int[col]; 
	}

	cout << endl;

	read_matrix(matrix, row, col);
	show_matrix(matrix, row, col);


	cin.get();

	return 0;
}

void read_matrix(int** matrix, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << "matrix[" << i << "][" << j << "] = ";
			cin >> matrix[i][j];
			cout << endl;
		}
	}
}


void show_matrix(int** matrix, int row, int col)
{
	cout << "Afisare matrice:" << endl;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << matrix[i][j] << " ";
		}

		cout << "\n";
	}
}
