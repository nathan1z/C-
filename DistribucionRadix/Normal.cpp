#include "Normal.h"

void Normal::ordenar(Vector vector, int tam)
{
	int temp;
	int* tempGet = vector.getArreglo();
	for (int i = 0; i < tam; i++)
	{
		for (int j= i + 1; j < tam; j++)
		{
			if (*(tempGet + j) < *(tempGet + i))
			{
				temp = *(tempGet + i);
				*(tempGet + i) = *(tempGet + j);
				*(tempGet + j) = temp;
			}

		}
	}
}
