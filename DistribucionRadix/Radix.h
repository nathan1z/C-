#pragma once
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <functional>
#include "Vector.h"
using namespace std;
class Radix
{
public:
	Vector generar(Vector, int );
	void imprimir1(Vector, int);
	int getMax(Vector list, int n);
	void tamaño(Vector list, int n, int exp);
	void radix(Vector list, int n);
	void imprimir(Vector list, int n);
};