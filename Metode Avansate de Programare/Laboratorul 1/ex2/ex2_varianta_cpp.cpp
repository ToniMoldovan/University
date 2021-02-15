#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    ifstream fintrare;
    fintrare.open("ex2in.txt");
    string linie, cautat;
    cout << "Introduceti cuvantul pe care vreti sa il cautati: ";
    cin >> cautat;
    if (fintrare.is_open())
    {
        int count = 0;
        while (!fintrare.eof())
        {
            getline(fintrare, linie);
            for (int i = 0; i <= linie.length(); i++)
            {
                int j;
                for (j = 0; j < cautat.length(); j++)
                {
                    if (linie[i + j] != cautat[j])
                    {
                        break;
                    }
                }
                if (j == cautat.length())
                {
                    count++;
                }
            }
        }
        cout <<"Cuvantul "<< cautat << " apare de "<< count <<" in textul dat.\n";
    }

    fintrare.close();
    system("pause");
    return 0;
}
