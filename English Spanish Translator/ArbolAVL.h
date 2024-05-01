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
#include <string>
#include"HojaNodo.h"
#define SPACE 10
/// <summary>
/// Declaracion de la clase Arbol AVL
/// </summary>
class ArbolAVL
{
public:
	HojaNodo* raiz;
	ArbolAVL();
	~ArbolAVL();
	bool arbolVacio();
	int altura(HojaNodo* r);
	int getBalanceFactor(HojaNodo* n);
	HojaNodo* rotacionDerecha(HojaNodo* y);
	HojaNodo* rotacionIzquierda(HojaNodo* x);
	HojaNodo* insertar(HojaNodo* r, HojaNodo* nuevo_nodo);
	HojaNodo* valorMinimo(HojaNodo* node);
	//HojaNodo* eliminarNodo(HojaNodo* r, int v);
	void imprimir2D(HojaNodo* r, int espacio);
	void imprimirPreorden(HojaNodo* r);
	//void imprimirPostorden(HojaNodo* r);
	void imprimirInorden(HojaNodo* r);
	void imprimirNivel(HojaNodo* r, int nivel);
	void imprimirOrdenNivel(HojaNodo* r);
	//HojaNodo* buscar(string palabra_ingles);
	HojaNodo* busquedaRecursiva(HojaNodo* r, Palabra palabra_a_buscar);
	int mayorPalabra(Palabra palabra1, Palabra palabra2);
};