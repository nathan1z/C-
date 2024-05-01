
#include <iostream>
#include <fstream>
#include "Laberinto.h"
int main()
{
	Laberinto l;
	printf("----------Laberinto------------\n");
    int maze[N][N] = { { 1, 0, 0, 0 },
                    { 1, 1, 0, 1 },
                    { 0, 1, 0, 0 },
                    { 1, 1, 1, 1 }, };
    l.resolverLab(maze);  
    l.leerArchivo("laberinto.txt",maze);
    return 0;
}
