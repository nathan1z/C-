
#include "Laberinto.h"

bool Laberinto::backtraking(int maze[N][N], int x, int y, int sol[N][N])
{
    if (x == N - 1 && y == N - 1&& maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }
    // Comprueba si laberinto [x] [y] es válido
    if (validar(maze, x, y) == true) {
        // Compruebe si el bloque actual ya forma parte de la ruta de la solución.  
        if (sol[x][y] == 1)
            return false;

        // marca x, y como parte de la ruta de la solución
        sol[x][y] = 1;

        /* Avanzar en la dirección x */
        if (backtraking(
            maze, x + 1, y, sol)
            == true)
            return true;

        /* Si se mueve en la dirección x
         no da solución entonces
         Mover hacia abajo en la dirección y */
        if (backtraking(
            maze, x, y + 1, sol)
            == true)
            return true;

        /* Si se mueve en la dirección y
        no da solución entonces
        Retroceder en la dirección x */
        if (backtraking(
            maze, x - 1, y, sol)
            == true)
            return true;

        /* Si se mueve hacia atrás en la dirección x
        no da solución entonces
        Mover hacia arriba en la dirección y */
        if (backtraking(
            maze, x, y - 1, sol)
            == true)
            return true;

        /* Si ninguno de los movimientos anteriores
        trabajar luego BACKTRACK: desmarcar
        x, y como parte de la ruta de la solución */
        sol[x][y] = 0;
        return false;
    }

    return false;
}

void Laberinto::imprimirSolucion(int sol[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		{
		if (sol[i][j]==0) printf ("%c",219);
		//if(sol[i][j]==0)printf("0",219);
		else printf (" ");
		}

		printf("\n");
	}
}

bool Laberinto::validar(int maze[N][N], int x, int y)
{
	if (x >= 0 && x < N && y >= 0&& y < N && maze[x][y] == 1)
		return true;
	return false;

}

bool Laberinto::resolverLab(int maze[N][N])
{
    int sol[N][N];
    for (int c = 0; c < N; c++)
    {
        for (int f = 0; f < N; f++)
        {
            sol[f][c] = 0;
        }
    }
    if (backtraking(maze, 0, 0, sol)== false) {
        printf("La solucion no existe");
        return false;
    }
    imprimirSolucion(sol);
    return true;
}

void Laberinto::leerArchivo(char *fileName,int sol[N][N])
{
  FILE *fp = fopen(fileName, "w");
	if (fp == NULL) {
		exit(EXIT_FAILURE);
	}
	char linea[80];
	sprintf(linea, "Matriz %d x %d\n", N, N);
	fputs(linea, fp);
	for (int i = 0; i < N; i++) {
		linea[0] = '\0';
		for (int j = 0; j < N; j++) {
			char buffer[10];
			sprintf(buffer, "%d ", sol[i][j]);
			strcat(linea, buffer);
		}
		int len = strlen(linea);
		linea[len - 1] = '\n';
		fputs(linea, fp);
	}
	fclose(fp);
}

void Laberinto::MuestraLaberinto()
{
	
}
