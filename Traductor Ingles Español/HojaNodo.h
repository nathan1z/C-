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
#include<iostream>
#include "Palabra.h"
using namespace std;
/// <summary>
/// Declaracion de la clase hoja nodo
/// </summary>
class HojaNodo {
public:
    Palabra datos;
    HojaNodo* izquierda;
    HojaNodo* derecha;
    HojaNodo()=default;
    ~HojaNodo();
    HojaNodo(Palabra datos);
    Palabra getDatos();
};