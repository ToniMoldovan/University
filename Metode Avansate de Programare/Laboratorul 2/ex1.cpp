#include <iostream>
#include <cmath>
using namespace std;

typedef struct Puncte
{
	int x, y, z;
};

Puncte coordonate();
void distanta(struct Puncte A, struct Puncte B);

int main()
{
	Puncte A, B;
	
	cout << "Introdu coordonatele lui A: " << endl;
	A = coordonate();
	cout << "Introdu coordonatele lui B: " << endl;
	B = coordonate();

	cout << "Distanta este: " << distanta;

	return 0;
}

Puncte coordonate()
{
	Puncte punct;
	cout << "Introdu x: "; cin >> punct.x;
	cout << "Introdu y: "; cin >> punct.y;
	cout << "Introdu z: "; cin >> punct.z;

	return punct;
}

void distanta(struct Puncte A, struct Puncte B)
{
	long long rezultat;

	rezultat = sqrt(pow((A.x - B.x), 2) + pow((A.y - B.y), 2) + pow((A.z - B.z), 2));
}
