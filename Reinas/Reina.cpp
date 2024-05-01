
#include "Reina.h"

bool Reina::comprobar(int* reinas, int n, int k)
{
	int i;
	for (i = 0; i < k; i++)
	{
		if ((*(reinas+i) == *(reinas+k)) || (abs(k - i) == abs(*(reinas+k) - *(reinas+i))))
		{
			return false;
		}
	}
	return true;
}

void Reina::Nreinas(int* reinas, int n, int k)
{
	if (k == n) {
		imprimirT(reinas, n);
		}
		for (*(reinas+k) = 0; *(reinas+k) < n; reinas[k]++)
		{
			if (comprobar(reinas, n, k)) {
				Nreinas(reinas, n, k + 1);
			}
			
		}
		

}

void Reina::imprimirT(int* vec, int t)
{
	int i, j;
	printf("\n\nSoluciones %d:\n\n", ++cantidad);

	for (i = 1; i <= t; ++i)
		printf("\t%d", i);

	for (i = 1; i <= t; ++i)
	{
		printf("\n\n%d", i);
		for (j = 1; j <= t; ++j) //for nxn board
		{
			if (vec[i] == j)
				printf("\tR"); 
			else
				printf("\t-"); //empty slot
		}
	}
	printf("\n***Coordenadas***\n");
	for (i = 1; i < t; i++) {
		for (j = 1; j < t; j++) {
			if (vec[i] == j) {
				printf("(%d,%d)\t", i, j);
			}
		}
	}
}

void Reina::guardarMatriz(char* fileName, int* matriz)
{
	/*FILE* fp = fopen(fileName, "w");
	if (fp == NULL) {
		exit(EXIT_FAILURE);
	}
	char linea[80];
	sprintf_s(linea, "%d %d\n", filas);
	fputs(linea, fp);
	for (int i = 0; i < filas; i++) {
		linea[0] = '\0';
		for (int j = 0; j < cols; j++) {
			char buffer[10];
			sprintf(buffer, "%d ", matriz[i]);
			strcat(linea, buffer);
		}
		int len = strlen(linea);
		linea[len - 1] = '\n';
		fputs(linea, fp);
	}
	fclose(fp);*/
}

int** Reina::leerMatriz(char* fileName)
{
	//FILE* fp = fopen(fileName, "r");
	//if (fp == NULL) {
	//	exit(EXIT_FAILURE);
	//}
	//char linea[80];
	//fgets(linea, 79, fp);
	//char* token = strtok(linea, " ");//10 6
	//filas = atoi(token);
	//token = strtok(NULL, " ");
	//cols = atoi(token);
	//int** matriz = new int* [filas];
	//for (int i = 0; i < filas; i++) {
	//	matriz[i] = new int[cols];
	//	fgets(linea, 79, fp);
	//	token = strtok(linea, " ");
	//	matriz[i][0] = atoi(token);
	//	for (int j = 1; j < cols; j++) {
	//		token = strtok(NULL, " ");
	//		matriz[i][j] = atoi(token);
	//	}
	//}
	//fclose(fp);
	return NULL;
}
