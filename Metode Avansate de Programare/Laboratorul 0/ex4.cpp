#include <iostream>
using namespace std;

int rasturnat(int n)
{
	int rasturnat = 0;

	while (n > 0)
	{
		rasturnat = rasturnat * 10 + n % 10;
		n /= 10;
	}

	return rasturnat;
}

int main()
{
	int x, r, counter = 0;

	while (counter < 3)
	{
		cout << "Introdu x: "; cin >> x;
		r = rasturnat(x);
		cout << "Rasturnatul: " << r;
		cout << "\n";
		counter++;
	}

	return 0;
}
