#pragma once
class Vector
{
private:
	int* arreglo;
	float* arreglo1;
public:
	Vector() = default;
	Vector(int*);
	void setArreglo(int*);
	int* getArreglo();
	void setArreglo1(float*);
	float* getArreglo1();

};