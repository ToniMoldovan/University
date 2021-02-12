//Creare dinamica a matricei

	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[col];
	}
  
  
//Scriere in matrice
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


//Afisare matrice
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
