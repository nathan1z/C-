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
#include "ArbolAVL.h"
#pragma warning(disable : 4996)
/// <summary>
/// Asigna null
/// </summary>
ArbolAVL::ArbolAVL()
{
	this->raiz = NULL;
}
ArbolAVL::~ArbolAVL()
{
}
/// <summary>
/// Verifica arbol vacio
/// </summary>
/// <returns></returns>
bool ArbolAVL::arbolVacio()
{
	if (raiz== NULL) {
		return true;
	}
	else {
		return false;
	}
}
/// <summary>
/// Altura del Arbol
/// </summary>
/// <param name="r"></param>
/// <returns></returns>
int ArbolAVL::altura(HojaNodo* r)
{
	if (r == NULL)
		return -1;
	else {
		/* altura de cada subárbol */
		int alturaI = altura(r->izquierda);
		int alturaD = altura(r->derecha);

		/* Compara la altura mas alta */
		if (alturaI > alturaD)
			return (alturaI + 1);
		else return (alturaD + 1);
	}
}
/// <summary>
/// get de balance factor
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
int ArbolAVL::getBalanceFactor(HojaNodo* n)
{
	/* Obtener el factor de equilibrio  */
	if (n == NULL)
		return -1;
	return altura(n->izquierda) - altura(n->derecha);
}
/// <summary>
/// Rotacion a la derecha
/// </summary>
/// <param name="y"></param>
/// <returns></returns>
HojaNodo* ArbolAVL::rotacionDerecha(HojaNodo* y)
{
	HojaNodo* x = y->izquierda;
	HojaNodo* z = x->derecha;

	/* Realiza la rotacion  */
	x->derecha = y;
	y->izquierda = z;
	return x;
}
/// <summary>
/// Rotacion a la izquierda
/// </summary>
/// <param name="x"></param>
/// <returns></returns>
HojaNodo* ArbolAVL::rotacionIzquierda(HojaNodo* x)
{
	HojaNodo* y = x->derecha;
	HojaNodo* z = y->izquierda;

	/* Realiza la rotacion  */
	y->izquierda = x;
	x->derecha = z;

	return y;
}
/// <summary>
/// Metodo inserccion
/// </summary>
/// <param name="r"></param>
/// <param name="nuevo_nodo"></param>
/// <returns></returns>
HojaNodo* ArbolAVL::insertar(HojaNodo* r, HojaNodo* nuevo_nodo)
{
	if (r == NULL) {
		r = nuevo_nodo;
		return r;
	}
	int x;
	x = mayorPalabra(r->getDatos(), nuevo_nodo->getDatos()); // 1) primer valor -> despues en el alfabeto ( mayor), 2) segundo valor -> despues en el alfabeto , 0) iguales
	if (x==1) {
		r->izquierda = insertar(r->izquierda, nuevo_nodo);
	}
	else if (x==2) {
		r->derecha = insertar(r->derecha, nuevo_nodo);
	}
	else {
		return r;
	}
	int factor = getBalanceFactor(r);
	// Rotacion IZQUIERDA IZQUIERDA 
	if (factor > 1 && mayorPalabra(r->izquierda->getDatos(), nuevo_nodo->getDatos()) == 1)//    nuevo_nodo->valor < r->izquierda->valor
		return rotacionDerecha(r);

	//  Rotacion DERECHA DERECHA 
	if (factor < -1 && mayorPalabra(nuevo_nodo->getDatos(), r->derecha->getDatos()) == 1)  // nuevo_nodo->valor > r->derecha->valor
		return rotacionIzquierda(r);

	//   Rotacion IZQUIERDA DERECHA   
	if (factor > 1 && mayorPalabra(nuevo_nodo->getDatos(), r->izquierda->getDatos()) == 1)  // nuevo_nodo->valor > r->izquierda->valor
	{ 
		r->izquierda = rotacionIzquierda(r->izquierda);
		return rotacionDerecha(r);
	}

	//  Rotacion DERECHA IZQUIERDA 
	if (factor < -1 && mayorPalabra(r->derecha->getDatos(), nuevo_nodo->getDatos()) == 1)  //  nuevo_nodo->valor < r->derecha->valor
	{
		r->derecha = rotacionDerecha(r->derecha);
		return rotacionIzquierda(r);
	}

	/*devuelve el puntero de nodo */
	return r;
}
/// <summary>
/// Verifica el valor minimo
/// </summary>
/// <param name="node"></param>
/// <returns></returns>
HojaNodo* ArbolAVL::valorMinimo(HojaNodo* node)
{
	HojaNodo* actual = node;
	while (actual->izquierda != NULL) {
		actual = actual->izquierda;
	}
	return  actual;
}
/// <summary>
/// Metodo de inserccion
/// </summary>
/// <param name="r"></param>
/// <param name="v"></param>
/// <returns></returns>
/*HojaNodo* ArbolAVL::eliminarNodo(HojaNodo* r, int v)
{
	if (r == NULL) {
		return NULL;
	}
	// Si la clave a eliminar es más pequeña se encuentra en el subárbol izquierdo
	else if (v < r->valor) {
		r->izquierda = eliminarNodo(r->izquierda, v);
	}
// Caso Contrario
	else if (v > r->valor) {
		r->derecha = eliminarNodo(r->derecha, v);
	}
	//La clave es la raiz
	else {
		// nodo con una solo hijo
		if (r->izquierda == NULL) {
			HojaNodo* temp = r->derecha;
			delete r;
			return temp;
		}
		else if (r->derecha == NULL) {
			HojaNodo* temp = r->izquierda;
			delete r;
			return temp;
		}
		else {
			//Nodos con dos hijos
			HojaNodo* temp = valorMinimo(r->derecha);
			// Copia el contenido del sucesor del orden en este nodo
			r->valor = temp->valor;
			// Eliminar el sucesor 
			r->derecha = eliminarNodo(r->derecha, temp->valor);
		}
	}

	int bf = getBalanceFactor(r);
	// Rotacion IZQUIERDA IZQUIERDA 
	if (bf == 2 && getBalanceFactor(r->izquierda) >= 0)
		return rotacionDerecha(r);
	//   Rotacion IZQUIERDA DERECHA 
	else if (bf == 2 && getBalanceFactor(r->izquierda) == -1) {
		r->izquierda = rotacionIzquierda(r->izquierda);
		return rotacionDerecha(r);
	}
	//  Rotacion DERECHA DERECHA 	
	else if (bf == -2 && getBalanceFactor(r->derecha) <= -0)
		return rotacionIzquierda(r);
	//  Rotacion DERECHA IZQUIERDA 
	else if (bf == -2 && getBalanceFactor(r->derecha) == 1) {
		r->derecha = rotacionDerecha(r->derecha);
		return rotacionIzquierda(r);
	}
	return r;
}*/
/// <summary>
/// Imprimir 
/// </summary>
/// <param name="r"></param>
/// <param name="espacio"></param>
void ArbolAVL::imprimir2D(HojaNodo* r, int espacio)
{
	if (r == NULL)
		return;
	espacio += SPACE; // Incrementa Distancia
	imprimir2D(r->derecha, espacio);
	cout << endl;
	for (int i = SPACE; i < espacio; i++)
		cout << " ";  
	cout << r->datos.paraAVL() << "\n"; 
	imprimir2D(r->izquierda,espacio);
}
/// <summary>
/// Imprimir en preorden
/// </summary>
/// <param name="r"></param>
void ArbolAVL::imprimirPreorden(HojaNodo* r)
{
	if (r == NULL)
		return;
	/* Imprimir primer Nodo */
	cout << r->getDatos().toString() << " ";
	/* repetir en el arbol Izquierdo */
	imprimirPreorden(r->izquierda);
	/*  repetir en el arbol derecho */
	imprimirPreorden(r->derecha);
}
/// <summary>
/// Imprimir en postorden
/// </summary>
/// <param name="r"></param>
/*void ArbolAVL::imprimirPostorden(HojaNodo* r)
{
	if (r == NULL)
		return;
	imprimirPostorden(r->izquierda);
	cout << r->valor << " ";
	imprimirPostorden(r->derecha);
}*/

void ArbolAVL::imprimirInorden(HojaNodo* r)
{
	if (r == NULL)
		return;
	imprimirInorden(r->izquierda);
	imprimirInorden(r->derecha);
	cout << r->getDatos().toString() << endl;
	cout << "\n";
}

void ArbolAVL::imprimirNivel(HojaNodo* r, int nivel)
{
	if (r == NULL)
		return;
	else if (nivel == 0)
		cout << r->getDatos().toString() << " ";
	else 
	{
		imprimirNivel(r->izquierda, nivel - 1);
		imprimirNivel(r->derecha, nivel - 1);
	}
}

void ArbolAVL::imprimirOrdenNivel(HojaNodo* r)
{
	int h = altura(r);
	for (int i = 0; i <= h; i++)
		imprimirNivel(r, i);
}

/*HojaNodo* ArbolAVL::buscar(string palabra_ingles)
{
	if (raiz == NULL) {
		return raiz;
	}
	else {
		HojaNodo* temp = raiz;
		while (temp != NULL) {
			if (palabra_ingles == temp->getDatos().getIngles()) {
				return temp;
			}
			else if (mayorPalabra()) { //v < temp->valor
				temp = temp->izquierda;
			}
			else {
				temp = temp->derecha;
			}
		}
		return NULL;
	}
}*/

HojaNodo* ArbolAVL::busquedaRecursiva(HojaNodo* r, Palabra palabra_a_buscar)
{
	if (r == NULL || r->getDatos().getIngles() == palabra_a_buscar.getIngles())
		return r;

	else if (mayorPalabra(r->getDatos(), palabra_a_buscar) == 1) {
		return busquedaRecursiva(r->izquierda, palabra_a_buscar);
	}//valor < r->valor
	else {
		return busquedaRecursiva(r->derecha, palabra_a_buscar);
	}

}

int ArbolAVL::mayorPalabra(Palabra palabra1, Palabra palabra2) {

	char pal1[25], pal2[25];
	strcpy(pal1, palabra1.getIngles().c_str());
	strcpy(pal2, palabra2.getIngles().c_str());
	int x = strcmp(pal1, pal2);

	if (x<=-1) {
		return 2;
	}
	if (x == 0) {
		return 0;
	}
	if (x >=1) {
		return 1;
	}
	return 0;
	/*
	char a = palabra1.getIngles().at(0);
	char b = palabra2.getIngles().at(0);
	if (a > b) {
		return 1;
	}
	if (a == b) {
		a = palabra1.getIngles().at(1);
		b = palabra2.getIngles().at(1);
		if (a > b) {
			return 1;
		}
		if (a < b) {
			return 2;
		}
		if (a == b) {
			a = palabra1.getIngles().at(2);
			b = palabra2.getIngles().at(2);
			if (a > b) {
				return 1;
			}
			if (a < b) {
				return 2;
			}
			if (a == b) {
				a = palabra1.getIngles().at(3);
				b = palabra2.getIngles().at(3);
				if (a > b) {
					return 1;
				}
				if (a < b) {
					return 2;
				}
				if (a == b) {
					return 0;
				}
			}
		}
	}
	if (a < b) {
		return 2;
	}
	*/
}


