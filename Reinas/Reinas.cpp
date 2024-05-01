
#include <iostream>
#include "Reina.h"
int main()
{
    Reina r;
	int k = 0;
	int cantidad;
	cout << "Ingrese el tama�o del tablero\n";
	cin >> cantidad;
	int* reinas = new int[cantidad];
	for (int i = 0; i < cantidad; i++)
	{
		*(reinas+i) = -1;
	}
	r.Nreinas(reinas, cantidad, k);
}

