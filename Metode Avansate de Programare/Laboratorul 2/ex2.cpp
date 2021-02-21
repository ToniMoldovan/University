#include <iostream>
#include <cmath>
using namespace std;

typedef struct Punct2D
{
	int x, y;
};

Punct2D citirePunct();

int distanta(struct Punct2D A, struct Punct2D B);

void centruGreutate(struct Punct2D A, struct Punct2D B, struct Punct2D C);

void centruGreutatePoligon(struct Punct2D poligon[], int nr);

void sortareVector(struct Punct2D varf[], int nr);

int main()
{
	Punct2D A, B, C;
	cout << "Introduceti abscisa(x) si ordonata(y) pentru A:" << endl;
	A = citirePunct();
	cout << "Introduceti abscisa(x) si ordonata(y) pentru B:" << endl;
	B = citirePunct();
	cout << "Introduceti abscisa(x) si ordonata(y) pentru C:" << endl;
	C = citirePunct();

	cout << endl;

	//Aflare distanta dintre puncte:
	cout << "Distanta dintre A si B: " << distanta(A, B) << endl;
	cout << "Distanta dintre A si C: " << distanta(A, C) << endl;
	cout << "Distanta dintre B si C: " << distanta(B, C) << endl;

	//Aflare centru de greutate
	centruGreutate(A, B, C);

	//Poligon
	int varfuri;
	Punct2D poligon[1000];
	cout << "\n";
	cout << "Introdu cate varfuri vrei sa aiba poligonul: "; cin >> varfuri;
	for (int i = 0; i < varfuri; i++)
	{
		poligon[i] = citirePunct();
	}

	poligon[varfuri].x = poligon[0].x;
	poligon[varfuri].y = poligon[0].y;

	centruGreutatePoligon(poligon, varfuri);
	sortareVector(poligon, varfuri);

	for (int i = 0; i < varfuri; i++)
	{
		cout << "\nVarf[" << i << "](" << poligon[i].x << ", " << poligon[i].y << ")";
	}


	return 0;
}

Punct2D citirePunct()
{
	Punct2D punct;
	cout << "Introdu x: "; cin >> punct.x;
	cout << "Introdu y: "; cin >> punct.y;

	return punct;
}

int distanta(struct Punct2D A, struct Punct2D B)
{
	int distanta = sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
	
	return distanta;
}

void centruGreutate(struct Punct2D A, struct Punct2D B, struct Punct2D C)
{
	long double x, y;
	x = (long double)(A.x + B.x + C.x) / 3;
	y = (long double)(A.y + B.y + C.y) / 3;
	cout << endl;
	cout << "Centru de greutate(" << x << ", " << y << ")";
}

void centruGreutatePoligon(struct Punct2D varf[], int nr)
{
	double Gx = 0, Gy = 0;
	double sumaAria = 0;
	for (int i = 0; i < nr; i++)
	{
		sumaAria = sumaAria + ((varf[i].x * varf[i + 1].y) - (varf[i + 1].x * varf[i].y));
	}
	double aria = abs(sumaAria / 2);
	double sumaX = 0, sumaY = 0;
	for (int i = 0; i < nr; i++)
	{
		sumaX = sumaX + ((varf[i].x + varf[i + 1].x) * ((varf[i].x * varf[i + 1].y) - (varf[i + 1].x * varf[i].y)));
		sumaY = sumaY + ((varf[i].y + varf[i + 1].y) * ((varf[i].x * varf[i + 1].y) - (varf[i + 1].x * varf[i].y)));
	}
	Gx = abs(sumaX) / (6 * aria);
	Gy = abs(sumaY) / (6 * aria);
	cout << "Centrul de greutate pentru varfurile introduse este: G(" << Gx << ", " << Gy << ").";
}

void sortareVector(struct Punct2D varf[], int nr)
{
	int temp;
	for (int i = 0; i < nr; i++)
	{
		for (int j = i; j < nr; j++)
		{
			if (varf[i].x == varf[j].x)
			{
				if (varf[i].y > varf[j].y)
				{
					temp = varf[j].y;
					varf[j].y = varf[i].y;
					varf[i].y = temp;
				}
			}
			else if (varf[i].x > varf[j].x)
			{
				temp = varf[j].x;
				varf[j].x = varf[i].x;
				varf[i].x = temp;
			}
		}
	}
}
