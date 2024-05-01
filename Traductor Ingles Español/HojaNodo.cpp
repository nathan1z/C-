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
#include "HojaNodo.h"
/// <summary>
/// Metodo destructor
/// </summary>
HojaNodo::~HojaNodo()
{
}
/// <summary>
/// Metodo Constructor dse hoja nodo
/// </summary>
/// <param name="v"></param>
HojaNodo::HojaNodo(Palabra datos)
{
    this-> datos = datos;
    this-> izquierda = NULL;
    this-> derecha = NULL;
}
/// <summary>
/// 
/// </summary>
/// <returns></returns>
Palabra HojaNodo::getDatos()
{
    return this->datos;
}
