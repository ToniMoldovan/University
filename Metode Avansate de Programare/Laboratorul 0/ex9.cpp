#include <iostream>
using namespace std;

//Declarare functii
void show_matrix(int** matrix, int row, int col);

void read_matrix(int** matrix, int row, int col);

void get_matrix_max(int** matrix, int* max, int* pos_x, int* pos_y, int row, int col);

void free_matrix(int** matrix, int row, int col);

int main()
{
	int row, col, max = 0, position_x = 0, position_y = 0;
	int* adr_max = &max;
	int* adr_position_x = &position_x;
	int* adr_position_y = &position_y;


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
	get_matrix_max(matrix, adr_max, adr_position_x, adr_position_y, row, col);
	free_matrix(matrix, row, col);


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


void get_matrix_max(int** matrix, int* max, int* pos_x, int* pos_y, int row, int col)
{
	
	for (int i = 0; i < row; i++)
	{
		
		for (int j = 0; j < col; j++)
		{
			if (*max < matrix[i][j])
			{

				*max = matrix[i][j];
				*pos_x = i;
				*pos_y = j;
			}

		}

	}

	//Afisare maxim si pozitii

	cout << "Maximul: " << *max << endl << "Pozitia: [" << *pos_x << "][" << *pos_y << "]";


}

void free_matrix(int** matrix, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;

	matrix = NULL;
}