
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
#include <fstream>
using namespace std;
#define N 4
class Laberinto
{
public:
    bool backtraking(int maze[N][N], int x,int y, int sol[N][N]);
    void imprimirSolucion(int sol[N][N]);
    bool validar(int maze[N][N], int x, int y);
    bool resolverLab(int maze[N][N]);
    void leerArchivo(char *fileName,int sol[N][N]);
    void MuestraLaberinto();
};
