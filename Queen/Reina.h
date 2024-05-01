
#pragma once
#include <iostream>
#include <math.h>
using namespace std;
class Reina {
public:
	int cantidad=0;
	int filas = 0;
	int cols = 0;
	bool comprobar(int* reinas, int n, int k);
	void Nreinas(int* reinas, int n, int k);
	void imprimirT(int* vec, int t);
	void  guardarMatriz(char* fileName, int* matriz);
	int** leerMatriz(char* fileName);
};
