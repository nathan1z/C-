/*
	Universidad de las Fuerzas Armadas "ESPE"
	Ingenieria de Software
	Autores:
	@Fausto Vizuete
	@Sebastian Yanzapata
	@Jonathan Zapata
	@Christopher Yepez
	@Vanessa Zurita
	Enunciado:Realizar los metodos de los arboles AVL - Traductor 
	Fecha de creacion: 05/08/2021
	Fecha de modificacion: 05/08/2021
*/
#include "Palabra.h"

Palabra::Palabra(string espanol, string ingles)
{
	this->espanol = espanol;
	this->ingles = ingles;
}

string Palabra::getEspanol()
{
	return this->espanol;
}

string Palabra::getIngles()
{
	return this->ingles;
}

void Palabra::setEspanol(string espanol)
{
	this->espanol = espanol;
}

void Palabra::setIngles(string ingles)
{
	this->ingles = ingles;
}

string Palabra::toString()
{
	return "Español : " + getEspanol() + "\nIngles : " + getIngles();
}

string Palabra::paraAVL()
{
	return getIngles();
}
