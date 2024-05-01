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
#pragma once
#include <iostream>
using namespace std;
/// <summary>
/// Declaracion de la clase palabra
/// </summary>
class Palabra
{
private:
	string espanol;
	string ingles;
public:
	Palabra() = default;
	Palabra(string, string);
	string getEspanol();
	string getIngles();
	void setEspanol(string);
	void setIngles(string);
	string toString();
	string paraAVL();
};

