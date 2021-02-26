#include <iostream>
#include <stdarg.h>
#include <algorithm>
using namespace std;

void afisare_numere(int n, ...);

int main()
{
    afisare_numere(5, 3, 4, 8, 1, 9);

    system("pause");
    return 0;
}

void afisare_numere(int n, ...)
{
    va_list argumente;
    va_start(argumente, n);
    int vector[50];
    for (int i = 0; i < n; i++)
    {
        vector[i] = va_arg(argumente, int);
    }
    //Afisare vector fara sortare
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << vector[i] << " ";
    }

    //Sortare vector (bubble sort)
    int sortat;
    do
    {
        sortat = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (vector[i] > vector[i + 1])
            {
                int aux = vector[i];
                vector[i] = vector[i + 1];
                vector[i + 1] = aux;
                sortat = 0;
            }
        }
    } while (sortat == 0);

    cout << endl;

    //Afisare vector sortat
    for (int i = 0; i < n; i++)
    {
        cout << vector[i] << " ";
    }

    va_end(argumente);
}
