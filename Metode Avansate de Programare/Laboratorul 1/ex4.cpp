#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

int main()
{

	ofstream output;
	output.open("output.txt"); //deschidere fisier pentru write.

	char c;

	cout << "La apasarea tastelor CTRL Z programul se va opri." << endl;
	cout << "Introdu textul tau: " << endl;

	while ((c = getchar()) != EOF)
	{

		if (c == ' ')
		{
			output << ' ';
		}
		else if (c == '\n')
		{
			output << '\n';
		}
		else
		{
			output << c;
		}

	}
		

	cout << "Oprirea s-a efectuat cu succes." << endl;
	output.close(); //inchiderea stream-ului catre output.txt
	system("pause");

	return 0;
}