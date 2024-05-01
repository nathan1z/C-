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
#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h>
#include <locale.h>
#include"ArbolAVL.h"
#include "HojaNodo.h"
#include "Ingreso.h"
#pragma warning(disable : 4996)
#define NOMBRE_ARCHIVO "diccionario.txt"
#define ARRIBA 72
#define ABAJO 80
#define ENTER 13
void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
int menu(const char titulo[], const char* opciones[], int n);
using namespace std;
/// <summary>
/// Metodo main
/// </summary>
/// <returns>El programa de arboles AVL</returns>
int main()
{
    setlocale(LC_ALL, "spanish"); // Cambiar locale - Suficiente para máquinas Linux
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows
    HojaNodo* nuevo_nodo = new HojaNodo();
    ifstream archivo(NOMBRE_ARCHIVO);
    Ingreso in;
    Palabra *palabra;
    ArbolAVL obj;
    char delimitador = ',';
    int option, val;
    HojaNodo* hojanodo;
    //leer csv
    string espanol, ingles, linea;
    if (!archivo)
    {
        cout << "\n Incapaz de crear este o abrir el fichero ";
        cout << " para salida " << endl;
    }
    getline(archivo, linea);
    while (getline(archivo, linea))
    {
        stringstream stream(linea);
        getline(stream, ingles, delimitador);
        getline(stream, espanol, delimitador);
        palabra = new Palabra(espanol, ingles);
        hojanodo = new HojaNodo(*palabra);
        obj.raiz = obj.insertar(obj.raiz,hojanodo);

    }
  //  archivo.close();
    string palabra_ingresada;
    Palabra* palabra_a_buscar;
    Palabra* pal;
    const char* titulo = "----------Traductor Ingles-Español---------------";
    const char* opciones[] = { "Traducir de Ingles a Español", "Mostrar Arbol", "Mostrar Palabras en el diccionario","Insertar Nueva Palabra","Salir"};
    int n = 5;  // Numero de opciones
    bool repite = true;
    int opcion;
    string nuevoEsp, nuevoIng;
    do {
        system("CLS");
        opcion = menu(titulo, opciones, n);

        switch (opcion) {
        case 1:
            std::cout << "\n-------------Traducir de Ingles a Español--------------" << endl;
            palabra_ingresada = in.texto("Ingresa la palabra a traducir (ingles): ");
            palabra_a_buscar = new Palabra(" ", palabra_ingresada);
            nuevo_nodo = obj.busquedaRecursiva(obj.raiz, *palabra_a_buscar);
            std::cout << "\n=========================================================" << endl;
            if (nuevo_nodo != NULL) {
                std::cout << "\nPalabra encontrada" << endl;
                std::cout << "*******" << endl;
                std::cout << nuevo_nodo->getDatos().toString() << endl;
                std::cout << "*******" << endl;
            }
            else {
                std::cout << "\nPalabra no Encontrada" << endl;
            }
            std::cout << "=========================================================" << endl;
            system("Pause");
            break;
        case 2:
            std::cout << "\n---------Impresion 2D---------" << endl;
            obj.imprimir2D(obj.raiz, 5);
            std::cout << endl;
            break;
            system("Pause");
        case 3:
            cout << "\n";
            obj.imprimirInorden(obj.raiz);
            system("Pause");
            break;
        case 4:
            std::cout << "\n---------Insertar Nueva Palabra---------" << endl;
            cout << "Nueva Palabra ingles:";
            cin >> nuevoIng;
            cout << "Nueva Palabra esp:";
            cin >> nuevoEsp;
            pal = new Palabra(nuevoEsp, nuevoIng);
            hojanodo = new HojaNodo(*pal);
            obj.raiz = obj.insertar(obj.raiz, hojanodo);
            break;
        case 5:
            cout << "\nEl programa se cerrara!! ADIOS" << endl;
            repite = false;
            break;
        }
        std::cin.get();
    } while (repite);

    std::cin.get();


    return 0;




}

int menu(const char titulo[], const char* opciones[], int n)
{
    int opcionSeleccionada = 1;  // Indica la opcionSeleccionada
    int tecla;
    bool repite = true; // controla el bucle para regresar a la rutina que lo llamo, al presionar ENTER

    do {
        system("CLS");
        gotoxy(5, 2 + opcionSeleccionada); cout << "--->" << endl;
        gotoxy(15, 2); cout << titulo;
        for (int i = 0; i < n; ++i) {
            gotoxy(10, 3 + i); cout << (i + 1) << ") " << opciones[i];
        }
        // Solo permite que se ingrese ARRIBA, ABAJO o ENTER
        do {
            tecla = _getch();
            // clreol(); gotoxy(15, 15); cout << "tecla presionada: " << (char)tecla << " = " << tecla;
        } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);
        switch (tecla) {
        case ARRIBA:   // En caso que se presione ARRIBA
            opcionSeleccionada--;
            if (opcionSeleccionada < 1) {
                opcionSeleccionada = n;
            }
            break;
        case ABAJO:
            opcionSeleccionada++;
            if (opcionSeleccionada > n) {
                opcionSeleccionada = 1;
            }
            break;
        case ENTER:
            repite = false;
            break;
        }
    } while (repite);
    return opcionSeleccionada;
}
