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
    int tama�o = 0;
    cout << "Ingrese el Tamanio: ";
    cin >> tama�o;
    vector2 = r.generar(vector1, tama�o);
    r.imprimir(vector2, tama�o);
    cout << "\nDatos Arreglado Por Radix" << endl;
    r.radix(vector2, tama�o);
    r.imprimir(vector2, tama�o);
    cout << "\nDatos Arreglado Por Cuentas" << endl;
    c.counting(vector2, tama�o);
    r.imprimir(vector2, tama�o);
    cout << "\nDatos Arreglado Normal" << endl;
    n.ordenar(vector2, tama�o);
    r.imprimir(vector2, tama�o);
}

