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

#include "Ingreso.h"
/// <summary>
/// Ingreso de texto
/// </summary>
/// <param name="mensaje"></param>
/// <returns></returns>
string Ingreso::texto(string mensaje) {

    string text = "";
    char letter;

    cout << "\n" << mensaje << " ";
    letter = _getch();
    while (letter != 13) {

        if ((letter < 91 && letter > 64) || (letter < 123 && letter > 96) || letter == 48 || letter == 64) {
            text.push_back(letter);
            cout << letter;
        }
        letter = _getch();
    }
    return text;
}
/// <summary>
/// Ingreso de numeros
/// </summary>
/// <param name="mensaje"></param>
/// <returns></returns>
string Ingreso::numeros(string mensaje) {

    string num = "";
    char dig;
    //int numero;

    cout << "\n\t" << mensaje;
    dig = _getch();
    while (dig != 13) {

        if (dig < 58 && dig > 47) {
            num.push_back(dig);
            cout << dig;
        }
        dig = _getch();
    }
    //istringstream(num) >> numero;
    return num;
}
/// <summary>
/// Ingreso de numeros maximos
/// </summary>
/// <param name="mensaje"></param>
/// <param name="max"></param>
/// <returns></returns>
string Ingreso::numerosMax(string mensaje,int max) {

    string num = "";
    char dig;
    //int numero;

    cout << "\n\t" << mensaje;
    dig = _getch();
    while (dig != 13) {
        if (dig < 58 && dig > 47 && max!=0) {
            num.push_back(dig);
            cout << dig;
            max--;
        }
        dig = _getch();
    }
    //istringstream(num) >> numero;
    return num;
}
/// <summary>
/// Ingreso de letras
/// </summary>
/// <param name="mensaje"></param>
/// <returns></returns>
string Ingreso::todos(string mensaje) {
        string todo = "";
    char dig;
    //int numero;

    cout << "\n\t" << mensaje;
    dig = _getch();
    while (dig != 13) {

        if (dig < 150 && dig > 0) {
            todo.push_back(dig);
            cout << dig;
        }
        dig = _getch();
    }
    //istringstream(num) >> numero;
    return todo;
}
/// <summary>
/// Ingreso de numeros deciamles
/// </summary>
/// <param name="mensaje"></param>
/// <param name="max"></param>
/// <returns></returns>
string Ingreso::numerosDecimales(string mensaje, int max) {
    string num = "";
    char dig;
    //int numero;
    int n=3;
    bool punto = true;
    bool decimal = false;
    cout << "\n\t" << mensaje;
    dig = _getch();
    while (dig != 13) {
        if (((dig < 58 && dig > 47 )|| (punto == true && dig == 46)) && n!=0) {
     
            num.push_back(dig);
            cout << dig;
            if (dig == 46) {
                punto = false;
                decimal = true;
            }
            if (decimal == true) {
                n--;
            }
        }
        dig = _getch();
    }
    //istringstream(num) >> numero;
    return num;
}