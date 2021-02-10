#include <iostream>
using namespace std;

void fiboancci_sequence(int n)
{
	int t1 = 0, t2 = 1, t3 = 0;

	for (int i = 1; i <= n; i++)
	{
		if (i == 1)
		{
			cout << t1 << ", ";
			continue; //daca nu pun continue el se duce la linia 61 apoi la 65
		}
		if (i == 2)
		{
			cout << t2 << ", ";
			continue;

		}

		t3 = t1 + t2;
		t1 = t2;
		t2 = t3;

		cout << t3 << ", ";

	}

}

int main()
{
	int counter = 0, x;

	while (counter < 4)
	{
		cout << "Introdu numarul de termeni: "; cin >> x;
		fiboancci_sequence(x);
		cout << "\n";
		counter++;
	}



	return 0;
}
