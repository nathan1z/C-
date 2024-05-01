#include "Vector.h"
Vector::Vector(int* _array)
{
	arreglo = _array;
}
void Vector::setArreglo(int* _array)
{
	arreglo = _array;
}
int* Vector::getArreglo()
{
	return arreglo;
}

void Vector::setArreglo1(float* _array1)
{
	arreglo1 = _array1;
}

float* Vector::getArreglo1()
{
	return arreglo1;
}
