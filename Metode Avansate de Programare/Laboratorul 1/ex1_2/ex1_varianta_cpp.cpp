#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    ifstream fintrare;
    ofstream fiesire;
    int ch;
    string linie;
    fintrare.open("input.txt");
    fiesire.open("output.txt");
    if (fintrare.is_open())
    {
        fiesire << "Copiere linie cu linie:\n";
        while (!fintrare.eof())
        {
            getline(fintrare, linie);
            fiesire << linie << "\n";
        }
    }
    fintrare.close();
    fintrare.open("ex1in.txt");
    if (fintrare.is_open())
    {
        fiesire << "\nCopiere caracter cu caracter:\n";
        while (!fintrare.eof())
            while (!fintrare.eof())
            {
                getline(fintrare, linie);
                for (int i = 0; i < linie.length(); i++)
                {
                    fiesire << linie[i];
                }
                fiesire << "\n";
            }
    }
    fintrare.close();
    fiesire.close();
    system("pause");
    return 0;
}