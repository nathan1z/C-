#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include "Radix.h"
#include "Vector.h"
#include "Counting.h"
#include "Normal.h"
int main()
{
    Radix r;
    Counting c;
    Normal n;
    Vector vector1=NULL, vector2;
    int tamaño = 0;
    cout << "Ingrese el Tamanio: ";
    cin >> tamaño;
    vector2 = r.generar(vector1, tamaño);
    r.imprimir(vector2, tamaño);
    cout << "\nDatos Arreglado Por Radix" << endl;
    r.radix(vector2, tamaño);
    r.imprimir(vector2, tamaño);
    cout << "\nDatos Arreglado Por Cuentas" << endl;
    c.counting(vector2, tamaño);
    r.imprimir(vector2, tamaño);
    cout << "\nDatos Arreglado Normal" << endl;
    n.ordenar(vector2, tamaño);
    r.imprimir(vector2, tamaño);
}

