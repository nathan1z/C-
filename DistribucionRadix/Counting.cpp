#include "Counting.h"

int Counting::getMax(Vector list, int n)
{
    int* tempGet = list.getArreglo();
    int mx = *(tempGet + 0);
    int i;
    for (i = 1; i < n; i++)
        if (*(tempGet + i) > mx)
            mx = *(tempGet + i);
    return mx;
}

void Counting::counting(Vector list, int n)
{
    int* tempGet = list.getArreglo();
    int output[1000];
    int count[1000];
    int max = *(tempGet + 0);

    // Encuentra el elemento más grande de la matriz
    for (int i = 1; i < n; i++) {
        if (*(tempGet + i) > max)
            max = *(tempGet + i);
    }

    // Inicializa la matriz de recuento con todos los ceros.
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // Almacena el recuento de cada elemento
    for (int i = 0; i < n; i++) {
        count[*(tempGet + i)]++;
    }

    // Almacena el recuento acumulativo de cada matriz
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Encuentra el índice de cada elemento de la matriz original en la matriz de recuento, y
    // coloca los elementos en la matriz de salida
    for (int i = n - 1; i >= 0; i--) {
        output[count[*(tempGet + i)] - 1] = *(tempGet + i);
        count[*(tempGet + i)]--;
    }

    // Copia los elementos ordenados en la matriz original
    for (int i = 0; i < n; i++) {
        *(tempGet + i) = output[i];
    }
}
