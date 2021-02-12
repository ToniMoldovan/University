void adaugare_elemente(int* vector, int marime)
{

	for (int i = 0; i < marime; i++)
	{
		cout << "[" << i << "]: "; cin >> vector[i];
		cout << endl;
	}

}

void afisare_vector(int* vector, int marime)
{
	for (int i = 0; i < marime; i++)
	{
		cout << "[" << i << "]: " << vector[i] << endl;

	}
}

int main()
{
	int marime_vector;

	cout << "Cat de mare vrei vectorul: "; cin >> marime_vector;

	int* vector = new int[marime_vector];

	adaugare_elemente(vector, marime_vector);
	afisare_vector(vector, marime_vector);

	return 0;

}
