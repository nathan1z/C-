#include "Radix.h"
#pragma once

int Radix::getMax(Vector vector, int n)
{
    int* tempGet = vector.getArreglo();
    int mx = *(tempGet + 0);
    int i;
    for (i = 1; i < n; i++)
        if (*(tempGet +i) > mx)
            mx = *(tempGet + i);
    return mx;
}

void Radix::tamaño(Vector vector,  int n, int exp)
{
    int* tempGet = vector.getArreglo();
    int output[1000];
    int i, count[10] = { 0 };
    for (i = 0; i < n; i++)
        count[(*(tempGet + i) / exp) % 10]++;

    for (i = 1; i < 10; i++)
        *(count+i) += *(count+i - 1);

    for (i = n - 1; i >= 0; i--) {
        *(output+*(count+(*(tempGet +i) / exp) % 10) - 1) = *(tempGet +i);
        count[(*(tempGet + i) / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        *(tempGet + i) = *(output+i);
}

void Radix::radix(Vector vector, int n)
{
    int* tempGet = vector.getArreglo();
    int m = getMax(tempGet, n);
    int exp;
    for (exp = 1; m / exp > 0; exp *= 10)
        tamaño(tempGet, n, exp);
}

void Radix::imprimir(Vector vector, int n)
{
    int i;
    int* tempGet = vector.getArreglo();
    for (i = 0; i < n; i++)
        printf("%d\t", *(tempGet +i));
}

Vector Radix::generar(Vector vector, int tam)
{
    vector.setArreglo(new int[tam]);
    int random = 0;
    for (int i = 0; i < tam; i++)
    {
        random = 1 + rand() % (101 - 1);
        *(vector.getArreglo() + i) = random;
    }
    return vector;
}

void Radix::imprimir1(Vector vector, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        cout << *(vector.getArreglo() + i) << " " << endl;
    }
}
