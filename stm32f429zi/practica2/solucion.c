/*
 * solucion.c
 *
 *  Created on: Aug 24, 2025
 *      Author: valentin
 */


/* Ordenar alfabéticamente una lista utilizando un vector bidimensional
 * de cadena de caracteres,
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reordenar(int n, char x[][12]);

void main() {
	int i, n = 0;
	char x[10][12];
	printf("Introducir debajo cada Cadena en una línea\n\n");
	printf("Escribir \"FIN\" para terminar\n\n");
	/*leer la lista de caracteres*/
	do {
		printf("cadena %d: ", n+1);
		scanf("%s",x[n]);
	} while(strcmp(x[n++],"FIN"));

	/* ajustar el valor de n */
	n--;

	/* reordenar la lista de cadena de caracteres */

	reordenar(n, x);

	/* escribir la lista reordenada de cadenas de caracteres */
	printf("\n\n Lista reordenada de cadenas:\n");

	for(i = 0; i < n; ++i) {
		printf("\n cadena %d: %s", i+1, x[i]);
	}
}

void reordenar(int n, char x[][12])
{
	char temp[12];
	int i, elem;
	for (elem = 0; elem < n; ++elem) {
		if(strcmp(x[elem],x[i]) > 0) {
			/* intercambiar las dos cadenas */
			strcpy(temp, x[elem]);
			strcpy(x[elem], x[i]);
			strcpy(x[i], temp);
		}
	}
}



















